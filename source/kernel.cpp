#include <cl/kernel.hpp>

#include <cstdio>

void cl::kernel::check_args_count(cl_uint count) throw(exception)
{
	if(count != _arg_count)
	{
		char strbuf[0x100];
		snprintf(strbuf,0xff,"kernel '%s' takes %u arguments, %u given",_name.data(),_arg_count,count);
		throw(exception(strbuf));
	}
}

cl::kernel::kernel(cl_program program, const std::string &name) throw(cl::exception)
	: _name(name)
{
	cl_int ret;
	
	_kernel = clCreateKernel(program, name.data(), &ret);
	if(ret != CL_SUCCESS) 
		throw cl_exception("clCreateKernel",ret);
	
	ret = clGetKernelInfo(_kernel,CL_KERNEL_NUM_ARGS,sizeof(cl_uint),&_arg_count,NULL);
	if(ret != CL_SUCCESS) 
		throw cl_exception("clGetKernelInfo",ret);
}

cl::kernel::~kernel() throw(cl::exception)
{
	cl_int ret;
	ret = clReleaseKernel(_kernel);
	if(ret != CL_SUCCESS)
		throw cl_exception("clReleaseKernel",ret);
}

const char *cl::kernel::get_name() const
{
	return _name.data();
}

cl_kernel cl::kernel::get_cl_kernel() const
{
	return _kernel;
}

cl_event cl::kernel::get_cl_event() const
{
	return _event;
}

void cl::kernel::bind_queue(cl_command_queue __queue)
{
	_queue = __queue;
}

void cl::kernel::bind_queue(const queue &__queue)
{
	bind_queue(__queue.get_cl_command_queue());
}

cl_ulong cl::kernel::measure_time()
{
	cl_ulong time_start, time_end;
	
	clWaitForEvents(1,&_event);
	clGetEventProfilingInfo(_event, CL_PROFILING_COMMAND_START, sizeof(time_start), &time_start, NULL);
	clGetEventProfilingInfo(_event, CL_PROFILING_COMMAND_END, sizeof(time_end), &time_end, NULL);
	
	return time_end - time_start;
}

void cl::kernel::print_time()
{
	printf("%s: %0.3f ms\n",get_name(),measure_time()/1000000.0);
}

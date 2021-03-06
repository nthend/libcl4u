#pragma once

#include "opencl.hpp"

#include <vector>
#include <string>

#include "exception.hpp"
#include "kernel.hpp"
#include "map.hpp"

namespace cl
{
class program
{
public:
	class build_exception : public exception
	{
	private:
		std::string build_output;
	public:
		build_exception(const std::string &msg);
		const std::string &get_build_output() const;
	};

private:
	cl_program _program;
	map<kernel*> _kernel_map;
	void *_inc = nullptr;
	void _free_inc();
	
public:
	program(cl_context context, cl_device_id device_id, const std::string &filename, const std::string &include_dir = "") throw(exception);
	~program();
	
	cl_program get_cl_program() const;
	map<kernel*> &get_kernel_map();
	kernel *get_kernel(const std::string &kname) throw(exception);
	void bind_queue(cl_command_queue queue);
};
}

#include <cl/utility.hpp>

#define __RET_CASE(err) \
case err: return #err;

const char *get_code_name(cl_int err)
{
	switch(err)
	{
	__RET_CASE(CL_SUCCESS)
	__RET_CASE(CL_DEVICE_NOT_FOUND)
	__RET_CASE(CL_DEVICE_NOT_AVAILABLE)
	__RET_CASE(CL_COMPILER_NOT_AVAILABLE)
	__RET_CASE(CL_MEM_OBJECT_ALLOCATION_FAILURE)
	__RET_CASE(CL_OUT_OF_RESOURCES)
	__RET_CASE(CL_OUT_OF_HOST_MEMORY)
	__RET_CASE(CL_PROFILING_INFO_NOT_AVAILABLE)
	__RET_CASE(CL_MEM_COPY_OVERLAP)
	__RET_CASE(CL_IMAGE_FORMAT_MISMATCH)
	__RET_CASE(CL_IMAGE_FORMAT_NOT_SUPPORTED)
	__RET_CASE(CL_BUILD_PROGRAM_FAILURE)
	__RET_CASE(CL_MAP_FAILURE)
	__RET_CASE(CL_MISALIGNED_SUB_BUFFER_OFFSET)
	__RET_CASE(CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST)
	__RET_CASE(CL_COMPILE_PROGRAM_FAILURE)
	__RET_CASE(CL_LINKER_NOT_AVAILABLE)
	__RET_CASE(CL_LINK_PROGRAM_FAILURE)
	__RET_CASE(CL_DEVICE_PARTITION_FAILED)
	__RET_CASE(CL_KERNEL_ARG_INFO_NOT_AVAILABLE)
	__RET_CASE(CL_INVALID_VALUE)
	__RET_CASE(CL_INVALID_DEVICE_TYPE)
	__RET_CASE(CL_INVALID_PLATFORM)
	__RET_CASE(CL_INVALID_DEVICE)
	__RET_CASE(CL_INVALID_CONTEXT)
	__RET_CASE(CL_INVALID_QUEUE_PROPERTIES)
	__RET_CASE(CL_INVALID_COMMAND_QUEUE)
	__RET_CASE(CL_INVALID_HOST_PTR)
	__RET_CASE(CL_INVALID_MEM_OBJECT)
	__RET_CASE(CL_INVALID_IMAGE_FORMAT_DESCRIPTOR)
	__RET_CASE(CL_INVALID_IMAGE_SIZE)
	__RET_CASE(CL_INVALID_SAMPLER)
	__RET_CASE(CL_INVALID_BINARY)
	__RET_CASE(CL_INVALID_BUILD_OPTIONS)
	__RET_CASE(CL_INVALID_PROGRAM)
	__RET_CASE(CL_INVALID_PROGRAM_EXECUTABLE)
	__RET_CASE(CL_INVALID_KERNEL_NAME)
	__RET_CASE(CL_INVALID_KERNEL_DEFINITION)
	__RET_CASE(CL_INVALID_KERNEL)
	__RET_CASE(CL_INVALID_ARG_INDEX)
	__RET_CASE(CL_INVALID_ARG_VALUE)
	__RET_CASE(CL_INVALID_ARG_SIZE)
	__RET_CASE(CL_INVALID_KERNEL_ARGS)
	__RET_CASE(CL_INVALID_WORK_DIMENSION)
	__RET_CASE(CL_INVALID_WORK_GROUP_SIZE)
	__RET_CASE(CL_INVALID_WORK_ITEM_SIZE)
	__RET_CASE(CL_INVALID_GLOBAL_OFFSET)
	__RET_CASE(CL_INVALID_EVENT_WAIT_LIST)
	__RET_CASE(CL_INVALID_EVENT)
	__RET_CASE(CL_INVALID_OPERATION)
	__RET_CASE(CL_INVALID_GL_OBJECT)
	__RET_CASE(CL_INVALID_BUFFER_SIZE)
	__RET_CASE(CL_INVALID_MIP_LEVEL)
	__RET_CASE(CL_INVALID_GLOBAL_WORK_SIZE)
	__RET_CASE(CL_INVALID_PROPERTY)
	__RET_CASE(CL_INVALID_IMAGE_DESCRIPTOR)
	__RET_CASE(CL_INVALID_COMPILER_OPTIONS)
	__RET_CASE(CL_INVALID_LINKER_OPTIONS)
	__RET_CASE(CL_INVALID_DEVICE_PARTITION_COUNT)
#ifdef CL_GL_INTEROP
	__RET_CASE(CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR)
#endif
	default: return "UNKNOWN_RETURN_CODE";
	}
}

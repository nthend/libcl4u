#pragma once

#define CAM_SIZE (27*sizeof(float))
#define RAY_SIZE (9*sizeof(float) + 3*sizeof(int))
#define HIT_SIZE (12*sizeof(float) + 3*sizeof(int))
#define HIT_INFO_SIZE (6*sizeof(int))
#define SHAPE_SIZE 6*3*sizeof(float)

#define SHAPE_BUFFER_SIZE 4*SHAPE_SIZE
#define MAX_CHILD_RAYS 2

#ifdef RAY_GL
static GLuint gl_texture_id;
#endif
static cl_mem cl_image;

static cl_program program;

static unsigned int width, height;

static float cam_pos[3] = {0.0f,0.0f,0.0f};
static float cam_ori[9] = 
{
  1,0,0,
  0,0,1,
  0,1,0
};
static float cam_pre_pos[3] = {0.0f,0.0f,0.0f};
static float cam_pre_ori[9] = 
{
  1,0,0,
  0,0,1,
  0,1,0
};
static float cam_fov = 1.0f;
static float cam_rad = 0.0f;
static float cam_dof = 4.0f;

static unsigned long samples = 0;

size_t screen_size;
size_t buffer_size;
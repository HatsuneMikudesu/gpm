
#pragma once

#include <gpm_platform_common/log.h>

#define _IOC(type,nr)   ((type)|(nr))
#define _GPM_IOC(x,y)   _IOC(x,y)
#define USEC_PER_TICK   (1000000 / GPM_TICKS_PER_SEC)
#define USEC2TICK(x)    (((x) + (USEC_PER_TICK / 2)) / USEC_PER_TICK)

#ifdef __cplusplus
constexpr bool GPM_ISFINITE(float x) { return __builtin_isfinite(x); }
constexpr bool GPM_ISFINITE(double x) { return __builtin_isfinite(x); }
#endif

__BEGIN_DECLS
extern long GPM_TICKS_PER_SEC;
__END_DECLS

#define GPM_ERROR (-1)
#define GPM_OK 0

#if 0
#define OK 0
#define ERROR -1
#define MAX_RAND 32767
#endif

/* Math macro's for float literals. Do not use M_PI et al as they aren't
 * defined (neither C nor the C++ standard define math constants) */
#define M_E_F			2.71828183f
#define M_LOG2E_F		1.44269504f
#define M_LOG10E_F		0.43429448f
#define M_LN2_F			0.69314718f
#define M_LN10_F		2.30258509f
#define M_PI_F			3.14159265f
#define M_TWOPI_F		6.28318531f
#define M_PI_2_F		1.57079632f
#define M_PI_4_F		0.78539816f
#define M_3PI_4_F		2.35619449f
#define M_SQRTPI_F		1.77245385f
#define M_1_PI_F		0.31830989f
#define M_2_PI_F		0.63661977f
#define M_2_SQRTPI_F	1.12837917f
#define M_DEG_TO_RAD_F	0.0174532925f
#define M_RAD_TO_DEG_F	57.2957795f
#define M_SQRT2_F		1.41421356f
#define M_SQRT1_2_F		0.70710678f
#define M_LN2LO_F		1.90821484E-10f
#define M_LN2HI_F		0.69314718f
#define M_SQRT3_F		1.73205081f
#define M_IVLN10_F		0.43429448f	// 1 / log(10)
#define M_LOG2_E_F		0.69314718f
#define M_INVLN2_F		1.44269504f	// 1 / log(2)

#define M_DEG_TO_RAD 	0.017453292519943295
#define M_RAD_TO_DEG 	57.295779513082323

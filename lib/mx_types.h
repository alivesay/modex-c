#ifndef H_MXTYPES
#define H_MXTYPES

#include <epoxy/gl.h>
#include <epoxy/glx.h>

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif
#ifndef bool
typedef int bool;
#endif

#ifdef _MSC_VER
typedef unsigned	__int8		uint8;
typedef signed		__int8		sint8;
typedef unsigned	__int16		uint16;
typedef signed		__int16		sint16;
typedef unsigned	__int32		uint32;
typedef signed		__int32		sint32;
typedef	unsigned	__int64		uint64;
typedef signed		__int64		sint64;

typedef 			float       real32;
typedef	    		double	    real64;
#endif

#ifdef __GNUC__
typedef	unsigned	char    	uint8;
typedef	signed		char	   	sint8;
typedef unsigned	short	   	uint16;
typedef signed		short	  	sint16;
typedef unsigned	int         uint32;
typedef signed		int		    sint32;
typedef unsigned	long long	uint64;
typedef signed		long long	sint64;

typedef 	    	float		real32;
typedef			    double		real64;
#endif

#endif // H_MXTYPES

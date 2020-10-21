#include "Defines.h"
#ifndef Defines_C

	#define Defines_C
	const DATA_PROTECTOR_TYPE DATA_PROTECTOR_VALUE = 0x0DEADBEEFBADF00D;
	#ifdef TYPE 
		#undef TYPE 
	#endif

	#define TYPE int
		#include "Stack.c"
	#undef TYPE

	#define TYPE double
		#include "Stack.c"
	#undef TYPE

	#define TYPE short
		#include "Stack.c"
	#undef TYPE

	#define TYPE char
		#include "Stack.c"
	#undef TYPE

#endif
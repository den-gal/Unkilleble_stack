#include "Defines.h"
#ifndef Defines_C

	#define Defines_C
	#ifdef TYPE 
		#undef TYPE 
	#endif

	#define TYPE int
		#include "Stack.cpp"
	#undef TYPE

#endif
/*
#define TYPE double
	#include "Stack.cpp"
#undef TYPE

/*
#define TYPE short
	#include "Stack.cpp"
#undef TYPE

#define TYPE char
	#include "Stack.cpp"
#undef TYPE
*/
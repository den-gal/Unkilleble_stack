#include "Templates.h"
#ifndef Defines_H

	#define Defines_H

	typedef uint64_t DATA_PROTECTOR_TYPE;
	extern const DATA_PROTECTOR_TYPE DATA_PROTECTOR_VALUE;
	
	#ifdef TYPE 
		#undef TYPE 
	#endif

	#define TYPE int
		#include "Stack.h"
	#undef TYPE

	#define TYPE double
	#include "Stack.h"
	#undef TYPE

	#define TYPE short
	#include "Stack.h"
	#undef TYPE

	#define TYPE char
	#include "Stack.h"
	#undef TYPE

	#define TYPE uint64_t
	#include "Stack.h"
	#undef TYPE

	#define TYPE int64_t
	#include "Stack.h"
	#undef TYPE

	#define TYPE uint32_t
	#include "Stack.h"
	#undef TYPE

#endif

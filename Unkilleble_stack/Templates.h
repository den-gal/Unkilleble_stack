#pragma once
#ifndef Templates_

	#define Templates_
	#define CAT(X,Y) X##_##Y
	#define Template_(X,Y) CAT(X,Y)
	#include <stdint.h>
	#include <stdio.h>

	#define PRINT(TYPE) PrintValue_##TYPE 

	void PrintValue_int(int value);
	void PrintValue_char(char value);
	void PrintValue_short(short value);
	void PrintValue_double(double value);
	void PrintValue_uint64_t(uint64_t value);
	void PrintValue_int64_t(int64_t value);
	void PrintValue_uint32_t(uint32_t value);

#endif

#ifdef TYPE 
#undef TYPE 
#endif

#define TYPE int
#include "stack.c"
#undef TYPE

#define TYPE double
#include "stack.c"
#undef TYPE

#define TYPE short
#include "stack.c"
#undef TYPE

#define TYPE char
#include "stack.c"


#define TYPE int
#include "stack.h"
#undef TYPE

#define TYPE double
#include "stack.h"
#undef TYPE

#define TYPE short
#include "stack.h"
#undef TYPE

#define TYPE char
#include "stack.h"
#undef TYPE

#define TYPE uint64_t
#include "stack.h"
#undef TYPE


#define TYPE int64_t
#include "stack.h"
#undef TYPE


#define TYPE uint32_t
#include "stack.h"
#undef TYPE

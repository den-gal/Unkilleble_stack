#ifndef Templates_

	#define Templates_
	#define CAT(X,Y) X##_##Y
	#define Template_(X,Y) CAT(X,Y)
	#include <stdint.h>
	#include <stdio.h>
	#include <sys/types.h>
	#include <stdlib.h>
	#include <assert.h>
/*
	#define PRINT(TYPE) PrintValue_##TYPE 

	void PrintValue_int(int value);
	void PrintValue_char(char value);
	void PrintValue_short(short value);
	void PrintValue_double(double value);
	void PrintValue_uint64_t(uint64_t value);
	void PrintValue_int64_t(int64_t value);
	void PrintValue_uint32_t(uint32_t value);
*/
#endif


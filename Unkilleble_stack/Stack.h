#ifdef TYPE	   
	#include "Templates.h" 

	typedef struct Template_(Stack, TYPE)
	{
		int size;
		int capacity;
		TYPE* data;

	} Template_(Stack, TYPE);

	bool Template_(StackConstr, TYPE)(Template_(Stack, TYPE) * stack, int capacity);

	Template_(Stack, TYPE) Template_(StackCopyConstr, TYPE)(Template_(Stack, TYPE)* priv_stack);
	
	bool Template_(StackDestr, TYPE)(Template_(Stack, TYPE)* stack);

	void Template_(Push, TYPE)(Template_(Stack, TYPE)* stack, TYPE elem);

	TYPE Template_(LastElem, TYPE)(Template_(Stack, TYPE)* stack);

	TYPE Template_(Pop, TYPE)(Template_(Stack, TYPE)* stack);

#endif 


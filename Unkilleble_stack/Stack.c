#ifdef TYPE
	//#include "Stack.h" 
	#include "Templates.h"

	//Stack Constructor function
	void Template_(StackConstr, TYPE)(Template_(Stack, TYPE)* stack, int capacity)
	{
		#ifdef STACK_CANARY
			void* data = calloc(capacity * sizeof(TYPE) + 2 * sizeof(DATA_PROTECTOR_TYPE), sizeof(uint8_t));
			
			DATA_PROTECTOR_TYPE* begin_canary = (DATA_PROTECTOR_TYPE*)data;
			DATA_PROTECTOR_TYPE* end_canary = (DATA_PROTECTOR_TYPE*)((uint8_t*)data + sizeof(DATA_PROTECTOR_TYPE) + capacity * sizeof(TYPE));
			
			*begin_canary = DATA_PROTECTOR_VALUE;
			*end_canary = DATA_PROTECTOR_VALUE;
			
			stack->data = (TYPE*)((DATA_PROTECTOR_TYPE*)data + 1);
			stack->top_canary = DATA_PROTECTOR_VALUE;
			stack->bottom_canary = DATA_PROTECTOR_VALUE;
		#else
			stack->data = (TYPE*)calloc(capacity, sizeof(TYPE));
		#endif
		stack->capacity = capacity;
		stack->size = 0;
	}

	//Stack Copy Constructor function
	Template_(Stack, TYPE) Template_(StackCopyConstr, TYPE)(Template_(Stack, TYPE) * priv_stack)
	{
		Template_(Stack, TYPE) new_stack;
		#ifdef STACK_CANARY
			void* data = calloc(priv_stack->capacity * sizeof(TYPE) + 2 * sizeof(DATA_PROTECTOR_TYPE), sizeof(uint8_t));

			DATA_PROTECTOR_TYPE* begin_canary = (DATA_PROTECTOR_TYPE*)data;
			DATA_PROTECTOR_TYPE* end_canary = (DATA_PROTECTOR_TYPE*)((uint8_t*)data + sizeof(DATA_PROTECTOR_TYPE) + priv_stack->capacity * sizeof(TYPE));

			*begin_canary = DATA_PROTECTOR_VALUE;
			*end_canary = DATA_PROTECTOR_VALUE;

			new_stack.data = (TYPE*)((DATA_PROTECTOR_TYPE*)data + 1);
			new_stack.top_canary = priv_stack->begin_canary;
			new_stack.bottom_canary = priv_stack->end_canary;
		#else
			new_stack.data = (TYPE*)calloc(priv_stack->data, sizeof(TYPE));
		#endif
		new_stack.capacity = priv_stack->capacity;
		new_stack.size = priv_stack->size;
		return new_stack;
	}

	//Stack Destructor function
	void Template_(StackDestr, TYPE)(Template_(Stack, TYPE)* stack)
	{
		#ifdef STACK_CANARY
			free((char*)stack->data - sizeof(DATA_PROTECTOR_TYPE));
		#else
			free(stack->data);
		#endif
		stack->data = NULL;   // Poison
		stack->size = -1;     // Poison
		stack->capacity = -1; // Poison
	}

	//Stack Push function
	void Template_(Push, TYPE)(Template_(Stack, TYPE)* stack, TYPE elem)
	{
		if (stack->size == stack->capacity)
		{
			stack->capacity *= 2;
			#ifdef STACK_CANARY
				TYPE* data = (TYPE*)realloc((DATA_PROTECTOR_TYPE*)stack->data - 1, stack->capacity * sizeof(TYPE) + 2 * sizeof(DATA_PROTECTOR_TYPE));
			#else
				TYPE* data = (TYPE*)realloc(stack->data, stack->capacity * sizeof(*stack->data));
			#endif
			if (!data)
			{
				printf("Problem with reallocation:: Check Push function");
				assert(!"Reallocation error");
				exit(-1);
			}
			else
			{
				#ifdef STACK_CANARY
					DATA_PROTECTOR_TYPE* begin_canary = (DATA_PROTECTOR_TYPE*)data;
					DATA_PROTECTOR_TYPE* end_canary = (DATA_PROTECTOR_TYPE*)((uint8_t*)data + sizeof(DATA_PROTECTOR_TYPE) + stack->capacity * sizeof(TYPE));

					*begin_canary = DATA_PROTECTOR_VALUE;
					*end_canary = DATA_PROTECTOR_VALUE;

					stack->data = (TYPE*)((DATA_PROTECTOR_TYPE*)data + 1);
				#else
					stack->data = data;
				#endif
			}
		}
		stack->data[stack->size++] = elem;
	}

	//Stack function which returns last element of the stack
	TYPE Template_(LastElem, TYPE)(Template_(Stack, TYPE)* stack)
	{
		if (stack->size < 1) {
			assert(!"Stack is empty");
			printf("Stack is empty. Nothing to show(pop).\n"); 
			return (TYPE)1;
		}
		return stack->data[stack->size - 1];
	}

	//Stack Pop function
	TYPE Template_(Pop, TYPE)(Template_(Stack, TYPE)* stack)
	{
		TYPE elem = Template_(LastElem, TYPE)(stack);
		stack->size--;
		return elem;
	}
	
#endif 

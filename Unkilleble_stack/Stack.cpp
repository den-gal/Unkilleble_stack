#ifdef TYPE
	#include "Stack.h"
	
	struct Template_(Stack, TYPE)
	{
		int size;
		int capacity;
		TYPE* data;
	};

	bool Template_(StackConstr, TYPE)(Template_(Stack, TYPE)* stack, int capacity)
	{
		stack->data = (TYPE*)calloc(capacity, sizeof(TYPE));
		stack->capacity = capacity;
		stack->size = 0;
		return true;
	}

	Template_(Stack, TYPE) Template_(StackCopyConstr, TYPE)(Template_(Stack, TYPE)* priv_stack)
	{
		Template_(Stack, TYPE) new_stack;
		new_stack->data = (TYPE*)calloc(priv_stack->data, sizeof(TYPE))
		new_stack.capacity = priv_stack->capacity;
		new_stack.size = priv_stack->size;
		return new_stack;
	}

	bool Template_(StackDestr, TYPE)(Template_(Stack, TYPE)* stack)
	{
		free(stack->data);
		stack->data = NULL;   // Poison
		stack->size = -1;     // Poison
		stack->capacity = -1; // Poison
		return true;
	}

	void Template_(Push, TYPE)(Template_(Stack, TYPE)* stack, TYPE elem)
	{
		if (stack->size == stack->capacity)
		{
			stack->capacity *= 2;
			TYPE * data = (TYPE*)realloc(stack->data, stack->capacity * sizeof(*stack->data));
			if (!data)
			{
				printf("Problem with reallocation:: Check Push function");
				assert(!"Reallocation error");
				exit(-1);
			}
			else
				stack->data = data;
		}
		stack->data[stack->size++] = elem;
	}

	TYPE Template_(LastElem, TYPE)(Template_(Stack, TYPE)* stack)
	{
		if (stack->size < 1) {
			assert(!"Stack is empty");
			printf("Stack is empty. Nothing to show(pop).\n"); //for release
			return (TYPE)1;
		}
		return stack->data[stack->size - 1];
	}

	TYPE Template_(Pop, TYPE)(Template_(Stack, TYPE)* stack)
	{
		TYPE elem = Template_(LastElem, TYPE)(stack);
		stack->size--;
		return elem;
	}

#endif 

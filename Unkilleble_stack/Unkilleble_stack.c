// Denis Galanin 327 group of CMC MSU

#include "Defines.h"


int Test_Stack_Int_Push_Pop()
{
        Stack_int stack;
        int capacity = 10;
        StackConstr_int(&stack, capacity);
        assert((stack.size == 0) && (stack.capacity == capacity) && (stack.data != NULL));
        for (int i = 0; i < 15; ++i) 
            Push_int(&stack, i);
        assert((stack.size == 15) && (stack.capacity == 20) && (stack.data != NULL));
        for (int i = 14; 0 <= i ; i--) 
            assert(Pop_int(&stack) == i);
        StackDestr_int(&stack);
        printf("Test function for push&pop copmlited successfully.\n");
}

int main()
{
    Test_Stack_Int_Push_Pop();
}


#ifdef TYPE	   
	#include "Templates.h" 

	/// 
	//! Stack for elements that are of type TYPE
	///
	typedef struct Template_(Stack, TYPE)
	{
		#ifdef STACK_CANARY
			DATA_PROTECTOR_TYPE begin_canary;
		#endif

		int size;
		int capacity;
		TYPE* data;

		#ifdef STACK_CANARY
			DATA_PROTECTOR_TYPE end_canary;
		#endif
	} Template_(Stack, TYPE);

	/// 
	//! Constructs stack
	//!
	//! @param [in] stack - our stack  	
	//! 
	//! @param [in]	capacity - capacity of our stack
	//! 
	/// 
	void Template_(StackConstr, TYPE)(Template_(Stack, TYPE) * stack, int capacity);

	/// 
	//! Copies previous stack
	//!
	//! @param [in] priv_stack - previous stack
	//! 
	//! @return copied stack
	/// 
	Template_(Stack, TYPE) Template_(StackCopyConstr, TYPE)(Template_(Stack, TYPE) * priv_stack);
	
	/// 
	//! Destructs our stack
	//!
	//! @param [in]	stack - destructable stack
	//! 
	/// 
	void Template_(StackDestr, TYPE)(Template_(Stack, TYPE)* stack);

	/// 
	//! Pushes an element to stack
	//!
	//! @param [in]	stack - our stack
	//! 
	//! @param [in] elem - new element of the stack
	/// 
	void Template_(Push, TYPE)(Template_(Stack, TYPE)* stack, TYPE elem);

	/// 
	//! Shows last element of the stack
	//!
	//! @param [in]	stack - our stack
	//! 
	//! @return last element of the stack
	/// 
	TYPE Template_(LastElem, TYPE)(Template_(Stack, TYPE)* stack);

	/// 
	//! Extracts last element from the stack
	//!
	//! @param [in]	stack - our stack
	//! 
	//! @return last element from the stack 
	/// 
	TYPE Template_(Pop, TYPE)(Template_(Stack, TYPE)* stack);
	
#endif 


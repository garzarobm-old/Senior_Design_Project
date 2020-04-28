missing c files

calc128


full instruction
	CXXFLAGS += -DNDEBUG -O3 -DTF_LITE_STRIP_ERROR_STRINGS
	CCFLAGS  += -DNDEBUG -O3 -DTF_LITE_STRIP_ERROR_STRINGS




# Os notes
	- TCB contains
		1. stackPtr (has to be first)Points to the location of the last item placed on the tasks stack.  THIS MUST BE THE FIRST MEMBER OF THE TCB STRUCT
		2. MpuSettings
		3. list (maybe linked list) for state
		4. list for task
		5. long priority
		5. 32bit stackptr
		6. char name ptr 
		7. pointer end of the stack (if it grows up )
		8. long critical nesting depth
		9. long tcbnum (tid)
		10. long taskNumber (only for debugging)
		11. basePrority for last priority
		12. for semaphores
		13. functionPtr for checking task
		14. localStorage pointers = array of void pointers  
		15. uint32_t for runtime 
		16. struct for newLibrentrancy <----- check later
		17. volatile uint32_t for tracking notifiedValue
		18. volatile uint32_t for tracking notifiedState
		19. int8_t to check if a task is static or not
		20. uint8_t for a microcontroller update
		21. int for checking taskErrno





when program loads, it goes all the way to 0x253b0
152496 address

/*
-------------------------------------
File:    stack_array.h
Project: R7
file description
-------------------------------------
Author:  Will Roberts
ID:      191023880
Email:   robe3880@mylaurier.ca
Version  2021-06-22
-------------------------------------
 */

#ifndef STACK_ARRAY_H_
#define STACK_ARRAY_H_

#define True 1
#define False 0
#include"data.h"

typedef struct{
	Data* array;
	int top;
	int capacity;
	
}Stack;

Stack* create_stack(int stack_capacity);
void destroy_stack(Stack **s);
Data* pop_stack(Stack *s);
int push_stack(Stack *s,Data* d);
void print_stack(Stack *s);
Data* peek_stack(Stack *s);
int len_stack(Stack *s);
int is_full_stack(Stack *s);
int is_empty_stack(Stack *s);
Stack* copy_stack(Stack *s);



#endif /* STACK_ARRAY_H_ */

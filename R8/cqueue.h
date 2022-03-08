/*
 -------------------------------------
 File:    cqueue.h
 Project: R8
 file description
 -------------------------------------
 Author:  Will Roberts
 ID:      191023880
 Email:   robe3880@mylaurier.ca
 Version  2021-06-28
 -------------------------------------
 */

#ifndef CQUEUE_H_
#define CQUEUE_H_
# include "data.h"
# define True 1
# define False 0

typedef struct {
	Data *array;  //array of elements
	int front;  //index of first item in queue
	int rear;  //index of last item in queue
	int capacity; //maximum queue length
	int size;  // number of elements in the queue
} cQueue;

cQueue* create_cqueue(int capacity);
int is_empty_cqueue(cQueue *q);
int len_cqueue(cQueue *q);
int is_full_cqueue(cQueue *q);
int insert_cqueue(cQueue *q, Data *d);
Data* peek_cqueue(cQueue *q);
void destroy_cqueue(cQueue **q);
int get_capacity_cqueue(cQueue *q);

#endif /* CQUEUE_H_ */

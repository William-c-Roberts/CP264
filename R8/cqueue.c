/*
 -------------------------------------
 File:    cqueue.c
 Project: R8
 file description
 -------------------------------------
 Author:  Will Roberts
 ID:      191023880
 Email:   robe3880@mylaurier.ca
 Version  2021-06-28
 -------------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>

# include "cqueue.h"

cQueue* create_cqueue(int capacity) {
	cQueue *q = (cQueue*) malloc(sizeof(cQueue));
	if (capacity < 1) {
		printf("Error(create_cqueue): invalid cqueue capacity, set to 10\n");
		capacity = 10;
	}
	q->capacity = capacity;
	q->array = (Data*) malloc(sizeof(Data) * capacity);
	q->front = -1;
	q->rear = -1;

	q->size = 0;
	return q;
}
int is_empty_cqueue(cQueue *q) {
	assert(q!=NULL);
	return (q->size == 0);
}
int len_cqueue(cQueue *q) {
	assert(q!=NULL);
	return q->size;
}
int is_full_cqueue(cQueue *q) {
	assert(q!=NULL);
	return (q->size == q->capacity);
}
int insert_cqueue(cQueue *q, Data *d) {
	assert(q!=NULL && d!=NULL);
	if (is_full_cqueue(q)) {
		printf("Error(insert_cqueue): cqueue is full\n");
		return 0;
	}
	if (is_empty_cqueue(q)) {
		q->front++;
	}
	q->rear = (q->rear + 1) % q->capacity;
	q->array[q->rear] = *copy_data(d);
	q->size++;
	return (1);

}
Data* peek_cqueue(cQueue *q) {
	assert(q!=NULL);
	if (is_empty_cqueue(q)) {
		printf("Error(peek_cqueue): cQueue is empty\n");
		return NULL;
	}
	return (copy_data(&q->array[q->front]));
}
void destroy_cqueue(cQueue **q) {
	assert(q!=NULL);
	while (!is_empty_cqueue(*q)) {
		Data *d = remove_cqueue(*q);
		destroy_data(&d);
	}
	free((*q)->array);
	(*q)->array = NULL;
	(*q)->capacity = 0;
	(*q)->front = 0;
	(*q)->rear = 0;
	(*q)->size = 0;
	free(*q);
	*q = NULL;
	return;
}
int get_capacity_cqueue(cQueue *q) {
	assert(q!=NULL);
	return (q->capacity);
}

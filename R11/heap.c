/*
 -------------------------------------
 File:    heap.c
 Project: R11
 file description
 -------------------------------------
 Author:  Will Roberts
 ID:      191023880
 Email:   robe3880@mylaurier.ca
 Version  2021-07-21
 -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "heap.h"
void heapify_up(Heap *h, int i);
void heapify_down(Heap *h, int i);
Heap* create_heap(int capacity) {
	Heap *h = (Heap*) malloc(sizeof(Heap));
	if (capacity <= 0) {
		printf("Error(create_heap): invalid capacity, capacity set to 1\n");
		h->capacity = 1;
	} else
		h->capacity = capacity;
	h->size = 0;
	h->array = (Data*) malloc(sizeof(Data) * h->capacity);
	return h;

}
void destroy_heap(Heap **h) {
	assert(h && *h);
	while (!is_empty_heap(*h))
		remove_heap(*h);
	free((*h)->array);
	(*h)->array = NULL;
	(*h)->capacity = 0;
	(*h)->size = 0;
	free(*h);
	return;
}
int is_empty_heap(Heap *h) {
	assert(h);
	return (h->size == 0);
}
void insert_heap(Heap *h, Data *d) {
	assert(h && d);
	if (contains_heap(h, d)) {
		printf("Error(insert_heap): cannot insert a duplicate\n");
		return;
	}
	//if heap is full --> expand memory(double the size)
	if (h->capacity == h->size) {
		h->capacity = h->capacity * 2;
		h->array = realloc(h->array, sizeof(Data) * h->capacity);
	}
	h->array[h->size] = *copy_data(d);
	h->size++;
	heapify_up(h, h->size - 1);
	return;
}
void heapify_up(Heap *h, int i) {
	assert(h);
	if (i <= 0)
		return;
	if (compare_data(&h->array[i], &h->array[Parent(i)]) == 1)
		swap_data(&h->array[i], &h->array[Parent(i)]);
	heapify_up(h, Parent(i));
}
Data* peek_heap(Heap *h) {
	assert(h);
	if (is_empty_heap(h)) {
		printf("Error(peek_heap): heap is empty\n");
		return NULL;
	}
	return copy_data(&h->array[0]);
}
void remove_heap(Heap *h) {
	assert(h);
	if (is_empty_heap(h)) {
		printf("Error(remove_heap): Cannot delete from an empty heap\n");
		return;
	}
	//if less than 1/3 of heap is utilized = shrink capacity 1/2 size
	if (h->capacity / 3 > h->size) {
		h->capacity = h->capacity / 2;
		h->array = realloc(h->array, sizeof(Data) * h->capacity);
	}
	h->array[0] = *copy_data(&h->array[h->size - 1]);
	h->size--;
	heapify_down(h, 0);
	return;
}
void heapify_down(Heap *h, int i) {
	assert(h);

	if (h->size <= 1)
		return;
	Data *node = &h->array[i];
	Data *left = NULL, *right = NULL;
	if (Left(i) < h->size)
		left = &h->array[Left(i)];
	if (Right(i) < h->size)
		right = &h->array[Right(i)];
	//no children
	if (!left && !right)
		return;

	// one child
	if (!right) {
		if (compare_data(left, node) == 1) {
			swap_data(left, node);
			heapify_down(h, Left(i));
			return;
		} else
			return;
	}

	//two children
	// case: 1 left largest
	if (compare_data(left, node) == 1 && compare_data(left, right) == 1) {
		swap_data(node, left);
		heapify_down(h, Left(i));
		return;
	}
	//case 2: right largest
	if (compare_data(right, node) == 1 && compare_data(right, left) == 1) {
		swap_data(node, right);
		heapify_down(h, Right(i));
		return;
	}
	//case 3: node is largest
	return;
}
int contains_heap(Heap *h, Data *d) {
	assert(h && d);
	if (is_empty_heap(h))
		return False;
	for (int i = 0; i < h->size; i++)
		if (compare_data(d, &h->array[i]) == 0)
			return True;
	return False;

}
void print_heap(Heap *h) {
	assert(h);
	printf("heap Capacity = %d, size = %d\n", h->capacity, h->size);
	if (is_empty_heap(h)) {
		printf("<empty_heap>\n");
	} else {
		int i;
		printf("[");
		for (i = 0; i < h->size - 1; i++) {
			print_data(&h->array[i]);
			printf(" , ");
		}
		printf("%d]\n", h->array[h->size - 1]);
	}
	return;
}
void heap_sort(Data *array, const int size) {
	Heap *h = create_heap(size);
	int i;
	for (i = 0; i < size; i++)
		insert_heap(h, &array[i]);

	for (i = 0; i < size; i++) {
		array[i] = *peek_heap(h);
		remove_heap(h);
	}
	destroy_heap(&h);
	return;

}

/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "A6.h"

void remove_shortest(Process *processes, const int size) {
	if (processes == NULL) {
		printf("Error(remove_shortest): given pointer is NULL\n");
		return;
	}
	if (size <= 0) {
		printf("Error(remove_shortest): invalid array size\n");
		return;
	}
	if (size == 1) {
		processes[0].PID = 0;
		processes[0].arrival = 0;
		processes[0].time = 0;
		return;
	};
	int loc = 0;
	for (int i = 0; i < size; i++) {
		//printf("%d\n", processes[i].time);
		if (processes[i].time < processes[loc].time) {

			loc = i;

		} else if (processes[i].time == processes[loc].time) {
			if (processes[i].arrival < processes[loc].arrival) {

				loc = i;

			} else if (processes[i].arrival == processes[loc].arrival) {
				if (processes[i].PID < processes[loc].PID) {

					loc = i;
				}
			}
		}
	}
	for (int i = loc; i < size - 1; i++) {
		processes[i] = processes[i + 1];

	}
	processes = (Process*) realloc(processes, sizeof(Process) * size - 1);
	return;
}

void reverse_stack(Stack *s) {

	int i, size = len_stack(s);

	Data *array = (Data*) malloc(sizeof(Data) * size);
	for (i = 0; i < size; i++)
		array[i] = *pop_stack(s);
	for (i = 0; i < size; i++)
		push_stack(s, &array[i]);
	return;
}

int contains_stack(Stack *s, Data *value) {
	if (s == NULL) {
		printf("Error(contains_stack): invalid stack\n");
		return 0;
	}
	if (value == NULL) {
		printf("Error(contains_stack): invalid data\n");
		return 0;
	}
	assert(s!=NULL);
	int i, size = len_stack(s), found = 0;

	Data *array = (Data*) malloc(sizeof(Data) * size);
	for (i = 0; i < size; i++) {
		if (is_equal_data(peek_stack(s), value)) {
			found = 1;
		}
		array[i] = *pop_stack(s);

	}
	for (i = size - 1; i >= 0; i--)
		push_stack(s, &array[i]);

	return found;
}

int resize_stack(Stack *s, int new_capacity) {
	if (new_capacity == 0) {
		printf("Error(resize_stack): invalid capacity size.\n");
		return 0;
	}
	if (new_capacity == s->capacity) {
		return 0;
	}
	if (new_capacity > s->capacity) {

		s->capacity = new_capacity;
		s = (Stack*) realloc(s, sizeof(Stack) * new_capacity);

		return 1;
	} else {
		s->capacity = new_capacity;

	}
	return 1;

}
Stack* concat_stack(Stack *s1, Stack *s2) {
	int count = 0;

	Stack *s3 = create_stack(s1->capacity + s2->capacity);
	Stack *stemp1 = create_stack(s1->capacity);
	Stack *stemp2 = create_stack(s2->capacity);

	Data *temp = malloc(sizeof(Data));

	while (is_empty_stack(s1) != 1) {
		temp = pop_stack(s1);
		push_stack(stemp1, temp);

	}
	while (is_empty_stack(s2) != 1) {
		temp = pop_stack(s2);
		push_stack(stemp2, temp);

	}
	//while (is_empty_stack(stemp2) != 1) {
	//temp = pop_stack(stemp2);
	//push_stack(s2, temp);
	//push_stack(s3, temp);

	//}
	//while (is_empty_stack(stemp1) != 1) {
	//temp = pop_stack(stemp1);
	//push_stack(s1, temp);
	//push_stack(s3, temp);

	//}
	//s1 = stemp1;
	//s2 = stemp2;

	return s3;
}

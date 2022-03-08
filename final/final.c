/**
 * ---------------------------------
 * Student Name:	Will Roberts
 * Student ID:		191023880
 * Student Email:	robe3880@mylaurier.ca
 * ---------------------------------
 */

/**
 * ---------------------------------
 *	I certify that I completed this final exam according to academic honesty
 *	guidelines. I attest that I did not use any external help, neither in person nor
 *	virtually. I understand that plagiarizing will lead to my failure in the course, in
 *	addition to other penalties according to the university policies.
 *
 *
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 * If you have any comments to the instructor
 * put it in this box
 *
 * ---------------------------------
 */

//---- Do not change imports -----------------
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <ctype.h>
# include <assert.h>

# include "data_structures.h"
# include "final.h"
//------------------------------------------------

//------------------------ Task 1 -----------------------------
Queue* stack_to_queue(Stack *s, int direction, int count) {
	if (!s) {
		printf("Error(stack_to_queue): invalid stack\n");
		return NULL;
	}
	int i;
	Queue *q = create_queue(s->capacity);
	if (direction != 1 && direction != 0) {
		printf("Error(stack_to_queue): invalid direction\n");
		return q;
	}
	if (count < 0 || count > len_stack(s)) {
		return q;
	}
	if (direction == 0) {
		for (i = 0; i < count; i++)
			insert_queue(q, pop_stack(s));
	} else if (direction == 1) {
		Stack *temp = create_stack(s->capacity);
		while (!is_empty_stack(s))
			push_stack(temp, pop_stack(s));
		for (i = 0; i < count; i++)
			insert_queue(q, pop_stack(temp));
		while (!is_empty_stack(temp))
			push_stack(s, pop_stack(temp));
		destroy_stack(&temp);
	}
	return q;
}

//--------------------- Task 2 --------------------
GData* create_gdata(char *type, void *value) {
	if (strcmp("integer", type) != 0 && strcmp("process", type) != 0) {
		printf("Error(create_gdata): invalid type\n");
		return NULL;
	}
	if (value == NULL) {
		printf("Error(create_gdata): invalid data pointer\n");
		return NULL;
	}
	GData *gd;

	if (strcmp("integer", type) == 0) {
		gd = malloc(sizeof(int) + sizeof(char));
		strcpy(gd->type, type);
		gd->value = malloc(sizeof(int));
		gd->value = value;
	} else {
		gd = malloc(sizeof(Process) + sizeof(char));
		strcpy(gd->type, type);
		gd->value = malloc(sizeof(Process));
		gd->value = value;
	}
	return gd;
}

void destroy_gdata(GData **d) {

	return;
}

void print_gdata(GData *d) {
	if (d == NULL) {
		printf("<NULL GData>\n");
	} else if (strcmp("integer", d->type) == 0) {
		printf("type = %s, value = %d\n", d->type, *(int*) d->value);
	} else if (strcmp("process", d->type) == 0) {
		printf("type = %s, value = ", d->type);
		print_process(d->value);
		printf("\n");
	} else {
		printf("Error(print_gdata): undefined data\n");
	}
	return;
}

GData* copy_gdata(GData *d) {
	GData *d2;
	if (d == NULL) {
		printf("<NULL GData>\n");
	} else if (strcmp("integer", d->type) == 0) {

		d2 = malloc(sizeof(int) + sizeof(char));
		strcpy(d2->type, d->type);
		d2->value = malloc(sizeof(int));
		d2->value = d->value;
	} else if (strcmp("process", d->type) == 0) {
		d2 = malloc(sizeof(Process) + sizeof(char));
		strcpy(d2->type, d->type);
		d2->value = malloc(sizeof(Process));
		d2->value = copy_process(d->value);
	} else {
		printf("Error(copy_gdata): undefined data\n");
		return NULL;
	}
	return d2;
}

//----------------------------- Task 3 -----------------------------
void schedule_DRR(pQueue *q, int period) {
	int i = 0, j;
	Data *d = NULL;
	pQueue *q2 = create_pqueue(70, 'L');
	pQueue *q3 = create_pqueue(20, 'L');
	pQueue *q4 = create_pqueue(2, 'L');
	printf("[Timer:%d]: Starting DRR%d Scheduler\n", i++, period);

	while (!is_empty_pqueue(q)) {
		d = peek_pqueue(q);
		if (d->arrival <= i) {
			d = remove_pqueue(q);
			printf("Fetching Process: ");
			print_data(d);
			printf("\n");
//-----------------------------------------------------------------------------------------------------case 3rd round
			if (!is_empty_pqueue(q3) && compare_data(d, peek_pqueue(q3)) == 0) {
				remove_pqueue(q3);
				if (d->time >= period * 3) {
					for (j = 0; j < period * 3; j++) {
						printf("[Timer:%d]: ", i++);
						print_data(d);
						printf("\n");
					}
				} else {
					for (j = 0; j < d->time; j++) {
						printf("[Timer:%d]: ", i++);
						print_data(d);
						printf("\n");
					}
				}
				if (d->time > period * 3) {
					d->time = d->time - period * 3;
					d->arrival = i;
					insert_pqueue(q, d);
					insert_pqueue(q4, d);
				}
			}
//------------------------------------------------------------------------------------case 2nd round
			else if (!is_empty_pqueue(q2)
					&& compare_data(d, peek_pqueue(q2)) == 0) {
				remove_pqueue(q2);
				if (d->time == period * 2) {
					for (j = 0; j < period * 2; j++) {
						printf("[Timer:%d]: ", i++);
						print_data(d);
						printf("\n");
					}
				} else if (d->time > period * 2) {
					for (j = 0; j < period * 2; j++) {
						printf("[Timer:%d]: ", i++);
						print_data(d);
						printf("\n");
					}
					d->time = d->time - period * 2;
					d->arrival = i;
					insert_pqueue(q, d);
					insert_pqueue(q3, d);

				} else {
					for (j = 0; j < d->time; j++) {
						printf("[Timer:%d]: ", i++);
						print_data(d);
						printf("\n");
					}
				}

			}

//-----------------------------------------------------------------------------------------------------case 1st round

			else {

				if (d->time >= period) {
					for (j = 0; j < period; j++) {
						printf("[Timer:%d]: ", i++);
						print_data(d);
						printf("\n");
					}
				} else {
					for (j = 0; j < d->time; j++) {
						printf("[Timer:%d]: ", i++);
						print_data(d);
						printf("\n");
					}
				}
				if (d->time > period) {
					d->time = d->time - period;
					d->arrival = i;
					insert_pqueue(q, d);
					insert_pqueue(q2, d);
				}
			}
		} else {
			printf("[Timer:%d]: Idle\n", i++);
		}
	}
	printf("[Timer:%d]: Closing RR Scheduler\n", i++);
	free(d);
	return;
}

//-------------------- Task 4 -------------------------
int find_distnace(Graph *g, Vertex *v1, Vertex *v2) {
	printf("Path from Vertex (%d) to Vertex (%d):\n", v1->num, v2->num);
	if (g->matrix[v1->num][v2->num] == 1) {

		printf("(%d)-->(%d)\n", v1->num, v2->num);
		return 1;

	} else {
		printf("no path was found\n");
	}
	return 0;
}


/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>
# include "A8.h"

/*---------------------Task 1 -----------------------------*/
void schedule(char *type, Data *processes, const int size) {
	if (strcmp(type, "FIFO") == 0) {
		pQueue *pq = create_fill_pqueue(size, processes);
		schedule_FIFO(pq);
	} else if (strcmp(type, "SJF") == 0) {
		pQueue *pq = create_fill_pqueue(size, processes);
		schedule_SJF(pq);
	} else if (type[0] == 'R' && type[1] == 'R') {
		pQueue *pq = create_fill_pqueue(size, processes);

		schedule_RR(pq, (int) type[2] - 48);
	} else {
		printf("Error(schedule): Unsupported scheduler type\n");
	}
	return;
}

/*---------------------Task 2 -----------------------------*/
void schedule_FIFO(pQueue *q) {
	int i = 0, j;
	Data *d = NULL;
	printf("[Timer:%d]: Starting FIFO Scheduler\n", i++);
	while (!is_empty_pqueue(q)) {
		d = peek_pqueue(q);
		if (d->arrival <= i) {
			d = remove_pqueue(q);
			printf("Fetching Process: ");
			print_data(d);
			printf("\n");
			for (j = 0; j < d->time; j++) {
				printf("[Timer:%d]: ", i++);
				print_data(d);
				printf("\n");
			}
		} else {
			printf("[Timer:%d]: Idle\n", i++);
		}
	}
	printf("[Timer:%d]: Closing FIFO Scheduler\n", i++);
	free(d);
	return;
}

/*---------------------Task 3 -----------------------------*/
void schedule_SJF(pQueue *q) {
	int i = 0, j;
	Data *d = NULL;
	pQueue *array = NULL;
	array = create_pqueue(30, 'L');
	printf("[Timer:%d]: Starting SJF Scheduler\n", i++);
	while (!is_empty_pqueue(q)) {

		d = SJF_data(i, q, array);
		if (d != NULL) {
			printf("Fetching Process: ");
			print_data(d);
			printf("\n");
			for (j = 0; j < d->time; j++) {
				printf("[Timer:%d]: ", i++);
				print_data(d);
				printf("\n");

			}
		} else {
			printf("[Timer:%d]: Idle\n", i++);
		}
	}
	printf("[Timer:%d]: Closing SJF Scheduler\n", i++);

	return;

}

/*---------------------Task 4 -----------------------------*/
void schedule_RR(pQueue *q, int period) {
	int i = 0, j;
	Data *d = NULL;
	printf("[Timer:%d]: Starting RR Scheduler\n", i++);
	printf("%d", period);
	while (!is_empty_pqueue(q)) {
		d = peek_pqueue(q);
		if (d->arrival <= i) {
			d = remove_pqueue(q);
			printf("Fetching Process: ");
			print_data(d);
			printf("\n");
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
			} else {
			}
		} else {
			printf("[Timer:%d]: Idle\n", i++);
		}
	}
	printf("[Timer:%d]: Closing RR Scheduler\n", i++);
	free(d);
	return;
}
pQueue* create_fill_pqueue(int capacity, Data *processes) {
	pQueue *pq = create_pqueue(capacity, 'L');
	for (int i = 0; i < capacity; i++) {
		insert_pqueue(pq, &processes[i]);
	}
	return pq;
}
Data* SJF_data(int arrival, pQueue *q, pQueue *array) {
	Data *d = NULL;
	Data *fin = NULL;
	int i = 0, j, loc = 0;
	if (!is_empty_pqueue(q)) {
		int min = peek_pqueue(q)->time;
		while (!is_empty_pqueue(q) && peek_pqueue(q)->arrival <= arrival) {
			d = remove_pqueue(q);
			if (d->time < min) {
				loc = i;
				min = d->time;
			}
			insert_pqueue(array, d);
			i++;

		}
		if (i > 0) {
			for (j = 0; j < i; j++) {
				if (j != loc) {
					d = remove_pqueue(array);
					insert_pqueue(q, d);

				} else {
					d = remove_pqueue(array);
					fin = d;

				}
			}
		}
	}

	return fin;
}


#ifndef A8_H_
#define A8_H_

#include "pqueue.h"

void schedule(char *type, Data *processes, const int size);
void schedule_FIFO(pQueue *q);
void schedule_SJF(pQueue *q);
void schedule_RR(pQueue *q, int period);
pQueue* create_fill_pqueue(int capacity, Data *processes);
Data* SJF_data(int arrival, pQueue *q, pQueue *array);
#endif /* A8_H_ */

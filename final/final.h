#ifndef FINAL_H_
#define FINAL_H_

#include "data_structures.h"

//--------------- Task 1 ----------------------
Queue* stack_to_queue(Stack* s, int direction, int count);

//--------------- Task 2----------------------
typedef struct {
	char type[10];  //general data type ('integer' or 'process')
	void *value; 	//pointer to data item
} GData;

GData* create_gdata(char* type, void *value);
void destroy_gdata(GData **d);
void print_gdata(GData *d);
GData* copy_gdata(GData *d);

//--------------- Task 3 ----------------------
void schedule_DRR(pQueue *q, int period);

//--------------- Task 4 ----------------------
int find_distnace(Graph *g, Vertex *v1, Vertex *v2);

#endif /* FINAL_H_ */

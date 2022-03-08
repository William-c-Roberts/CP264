# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# include "data_structures.h"
# include "final.h"

void test_task1();
void test_task2();
void test_task3();
void test_task4();
int read_processes(char*, Data*);

int main() {
	setbuf(stdout, NULL);
	test_task1();
	test_task2();
	test_task3();
	test_task4();
	return 0;
}

Stack* create_process_stack(int size) {
	Stack *s = create_stack(size);
	for (int i = 0; i < size; i++)
		push_stack(s, create_process(i + 1, (i + 1) * 7, (i + 1) * 50000));
	return s;
}
void test_task1() {
	printf("------------------------------\n");
	printf("Start: Testing stack_to_queue\n\n");

	Queue *q = NULL;

	int capacity = 10;
	int direction[8] = { 0, 1, 0, 1, 0, 1, 2, 0 };
	int count[8] = { 10, 10, 9, 9, 8, 8, 10, -2 };

	printf("Input Stack:\n");
	Stack *s = create_process_stack(10);
	print_stack(s);
	printf("\n");

	for (int i = 0; i < 8; i++) {
		printf("Case %d:\n", (i + 1));
		printf("stack_to_queue(s,%d,%d)\n", direction[i], count[i]);
		q = stack_to_queue(s, direction[i], count[i]);
		print_queue(q);
		print_stack(s);
		destroy_queue(&q);
		destroy_stack(&s);
		printf("\n");
		s = create_process_stack(capacity);
	}

	printf("Case 9:\n");
	destroy_stack(&s);
	q = stack_to_queue(s, 0, 10);
	if (q == NULL)
		printf("<NULL queue>\n");
	printf("\n");

	printf("End: Testing stack_to_queue\n");
	printf("------------------------------\n\n");
	return;
}
void test_task2() {
	printf("------------------------------\n");
	printf("Start: Testing GData:\n\n");

	printf("Testing create_gdata:\n");
	int pid = 1000010000, arrival = 30, time = 1;
	Process *p = create_process(pid++, time++, arrival++);
	GData *d1 = create_gdata("process", p);
	if (d1 && strcmp(d1->type, "process") == 0)
		printf("GData of type process created successfully\n");

	int *num1 = (int*) malloc(sizeof(int));
	*num1 = 10;
	GData *d2 = create_gdata("integer", num1);
	if (d2 && strcmp(d2->type, "integer") == 0)
		printf("GData of type integer created successfully\n");

	GData *d3 = create_gdata("float", num1);
	GData *d4 = create_gdata("integer", NULL);
	printf("\n");

	printf("Testing print_gdata:\n");
	print_gdata(d1);
	print_gdata(d2);
	strcpy(d2->type, "float");
	print_gdata(d2);
	strcpy(d2->type, "integer");
	print_gdata(d3);
	printf("\n");

	printf("Testing copy_gdata:\n");
	d3 = copy_gdata(d1);
	printf("Copy data of type process: ");
	print_gdata(d3);
	printf("Copy data of type integer: ");
	d4 = copy_gdata(d2);
	print_gdata(d4);
	strcpy(d2->type, "float");
	printf("Copy data of type float: ");
	GData *d5 = copy_gdata(d2);
	print_gdata(d5);
	printf("\n");

	printf("Testing destroy_mdata:\n");
	destroy_gdata(&d1);
	printf("gdata of type process successfully destroyed\n");
	destroy_gdata(&d2);
	printf("gdata of type integer successfully destroyed\n");
	printf("\n");

	printf("End: Testing MData\n");
	printf("------------------------------\n\n");
	return;
}

void test_task3() {
	printf("------------------------------\n");
	printf("Start: Testing DRR Scheduler\n\n");

	Data *array = NULL;
	pQueue *q = NULL;
	int size = 0;
	int cases[3] = { 3, 2, 4 };
	for (int i = 0; i < 3; i++) {
		array = (Data*) malloc(sizeof(Data) * 30);
		size = read_processes("processes.txt", array);
		q = create_pqueue(size, 'L');
		for (int j = 0; j < size; j++)
			insert_pqueue(q, &array[j]);
		printf("Scheduling DRR%d:\n", cases[i]);
		schedule_DRR(q, cases[i]);
		free(array);
		array = NULL;
		destroy_pqueue(&q);
		printf("---------------------\n");
	}

	printf("End: Testing DRR Scheduler\n");
	printf("------------------------------\n\n");
	return;
}

void test_task4() {
	printf("\n");
	printf("--------- start of test find_distance() ---------\n");

	Graph *g = create_graph(1, 1);

	int i;
	Vertex *v[6];
	Edge *e[5];

	for (i = 0; i < 6; i++) {
		v[i] = create_vertex(i, "");
		add_vertex_graph(g, v[i]);
	}

	e[0] = create_edge(v[0], v[1], 10, 1);
	e[1] = create_edge(v[1], v[2], 20, 1);
	e[2] = create_edge(v[3], v[0], 50, 1);
	e[3] = create_edge(v[2], v[4], 30, 1);
	e[4] = create_edge(v[4], v[5], 40, 1);

	for (i = 0; i < 5; i++)
		add_edge_graph(g, e[i]);

	//manually change the graph into directed graph.
	g->directed = 1;
	g->matrix[0][3] = 0;
	g->matrix[1][0] = 0;
	g->matrix[2][1] = 0;
	g->matrix[4][2] = 0;
	g->matrix[5][4] = 0;

	print_graph(g);

	int distance;
	printf("\n");
	distance = find_distnace(g, v[0], v[1]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[1], v[0]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[0], v[2]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[3], v[2]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[3], v[5]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[5], v[3]);
	printf("Distance = %d\n\n", distance);
	distance = find_distnace(g, v[1], v[4]);
	printf("Distance = %d\n\n", distance);

	printf("----------- end of test find_distance -----------\n");

}

int read_processes(char *fileName, Data *array) {
	FILE *inFile = NULL;
	inFile = fopen(fileName, "r");
	if (inFile == NULL) {
		printf("Error(read_processes): Cannot open file %s\n", fileName);
		return 0;
	}

	char line[40], tempArrival[7], tempPID[12], tempTime[7], *dummy;
	int marker1, marker2, i, factor, digit;
	unsigned int arrival, time;
	unsigned long pid;

	int counter = 0;
	while (fgets(line, sizeof(line), inFile) != NULL) {
		counter++;
		i = 0;

		while (line[i] != ']')
			i++;
		marker1 = i;
		for (i = 1; i < marker1; i++)
			tempArrival[i - 1] = line[i];
		arrival = (unsigned int) strtol(tempArrival, &dummy, 10);

		marker1 += 2;
		for (i = marker1; i < (marker1 + 10); i++)
			tempPID[i - marker1] = line[i];

		pid = 0;
		factor = 1000000000;
		for (i = 0; i < 10; i++) {
			digit = tempPID[i] - '0';
			pid += digit * factor;
			factor = factor / 10;
		}

		marker1 += 11;
		i = marker1;
		while (line[i] != ')')
			i++;
		marker2 = i;

		for (i = marker1; i < marker2; i++)
			tempTime[i - marker1] = line[i];
		tempTime[i - marker1] = '\0';

		time = (unsigned int) strtol(tempTime, &dummy, 10);
		array[counter - 1] = *create_process(pid, time, arrival);
	}
	fclose(inFile);
	return counter;
}

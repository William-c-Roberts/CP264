/*
-------------------------------------
File:    process.h
Project: R7
file description
-------------------------------------
Author:  Will Roberts
ID:      191023880
Email:   robe3880@mylaurier.ca
Version  2021-06-22
-------------------------------------
 */

#ifndef PROCESS_H_
#define PROCESS_H_


#define True 1
#define False 0

typedef struct{
	unsigned long PID;//process id (10-digit)
	unsigned int time;//requested processing time
	unsigned int arrival;//arrival time 
}Process;

Process* create_process(long p_pid,int p_time,int arival_time);
void destory_process(Process** p);
void print_process(Process* p);
Process* copy_process(Process* p);
void get_process_info(Process* p,char* info);
int is_equal_process(Process* p1 , Process* p2);
unsigned long get_UPID();



#endif /* PROCESS_H_ */

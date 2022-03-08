/*
 -------------------------------------
 File:    data.c
 Project: R7
 file description
 -------------------------------------
 Author:  Will Roberts
 ID:      191023880
 Email:   robe3880@mylaurier.ca
 Version  2021-06-22
 -------------------------------------
 */

#include "data.h"
# include <stdio.h>

void print_data(Data *d) {
	print_process(d);
	return;
}

void destroy_data(Data **d) {

	destory_process(d);
	return;

}

Data* copy_data(Data *d) {
	return copy_process(d);
}
int compare_data(Data *d1, Data *d2) {
	if (d1->arrival == d2->arrival) {

		if (d1->time == d2->time) {
			if (d1->PID == d2->PID) {
				return 0;
			} else if (d1->PID > d2->PID) {
				return 1;
			} else {
				return 2;
			}
		} else if (d1->time > d2->time) {
			return 1;
		} else {
			return 2;
		}
	} else if (d1->arrival > d2->arrival) {

		return 1;
	} else {
		return 2;

	}
}


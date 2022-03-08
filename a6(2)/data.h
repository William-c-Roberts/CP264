/*
 -------------------------------------
 File:    data.h
 Project: R7
 file description
 -------------------------------------
 Author:  Will Roberts
 ID:      191023880
 Email:   robe3880@mylaurier.ca
 Version  2021-06-22
 -------------------------------------
 */

#ifndef DATA_H_
#define DATA_H_
#include"process.h"

typedef Process Data;

void print_data(Data *d);
void destroy_data(Data **d);
Data* copy_data(Data *d);
int is_equal_data(Data *d1, Data *d2);

#endif /* DATA_H_ */

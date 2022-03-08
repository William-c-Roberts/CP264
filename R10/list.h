/*
 -------------------------------------
 File:    list.h
 Project: R10
 file description
 -------------------------------------
 Author:  Will Roberts
 ID:      191023880
 Email:   robe3880@mylaurier.ca
 Version  2021-07-12
 -------------------------------------
 */

#ifndef LIST_H_
#define LIST_H_

#include "data.h"

#define True 1
#define False 0

typedef struct linkedListNode {
	Data *data;
	struct linkedListNode *next;

} Node;

Node* create_node(Data *d, Node *n);
void print_node(Node *n);
Node* copy_node(Node *n);
void destroy_node(Node **n);

typedef struct {
	Node *head;
	int size;

} List;

List* create_list();
int is_empty_list(List *list);
void print_list(List *list);
void append_list(List *list, Data *d);
void insert_front_list(List *list, Data *d);
Data* get_data_list(List *list, int index);
Node* get_node_list(List *list, int index);
void destroy_list(List **list);
Data* remove_rear_list(List *list);
void reverse_list(List *list);
List* array_to_list(Data *array, const int size);
#endif /* LIST_H_ */

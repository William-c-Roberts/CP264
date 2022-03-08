/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

# include <stdio.h>
# include <stdlib.h>
# include <assert.h>
# include "list.h"

int equal_data(Data *d1, Data *d2);

/**
 * ------------------------------------------------------------
 * Parameters: 	d - a data item (Data*)
 * 				n - pointer to next node (Node*)
 * Returns: 	new node (Node*)
 * Description:	Creates a new node using the given data
 * Asserts:		data is not NULL
 * ------------------------------------------------------------
 */
Node* create_node(Data *d, Node *n) {
	assert(d);
	Node *node = (Node*) malloc(sizeof(Node));
	node->data = copy_data(d);
	node->next = n;
	return node;
}

/**
 * -------------------------------------------------------
 * Parameters: 	a node (Node*)
 * Returns: 	none
 * Description:	prints the contents of a node
 * 				invokes print_data
 * 				does not print next pointer
 * Assert:		n is not NULL
 * -------------------------------------------------------
 */
void print_node(Node *n) {
	assert(n);
	print_data(n->data);
	return;
}

/**
 * --------------------------------------------------------
 * Parameters: 	a node (Node*)
 * Returns: 	a copy node (Node*)
 * Description:	Creates a copy of the given node
 * 				The new copy has a copy version of the data
 * 				the next pointer points to the same node as the original node's next
 * Assert:		given node is not NULL
 * --------------------------------------------------------
 */
Node* copy_node(Node *n) {
	assert(n);
	return create_node(n->data, n->next);
}

/**
 * ---------------------------------------------------
 * Parameters:  a node (Node**)
 * Returns: 	none
 * Description:	destroys a node by:
 * 				- destroy the encompassed data
 * 				- setting next to NULL
 * 				- free the node pointer
 * Assert:		n and *n are not NULL
 * --------------------------------------------------
 */
void destroy_node(Node **n) {
	assert(n && *n);
	destroy_data(&(*n)->data);

	(*n)->data = NULL;

	(*n)->next = NULL;
	free(*n);
	return;
}

//-----------------------------------------------------------
/**
 * Parameters: 	None
 * Returns: 	A pointer to linked list (List*)
 * Description:	Creates an empty linked list
 * 				head is set to NULL and size to 0
 * 				Returns a pointer to the newly created linked list
 * -----------------------------------------------------------
 */
List* create_list() {
	List *list = (List*) malloc(sizeof(List));
	list->head = NULL;
	list->size = 0;
	return list;
}

/**
 * -------------------------------------------------------------------
 * Parameters: 	Pointer to a linked list (List*)
 * Returns: 	None
 * Description:	traverse through all nodes
 * 				uses print_node(Node*) to print contents of nodes
 * 				starting from list head to tail
 * 				node1-->node2-->node3-->...-->NULL
 * 				prints <NULL> if empty list
 * Assert:		list is not NULL
 * -------------------------------------------------------------------
 */
void print_list(List *list) {
	assert(list);
	Node *current_node = list->head;
	while (current_node != NULL) {
		print_node(current_node);
		printf("-->");
		current_node = current_node->next;
	}
	printf("NULL\n");
	return;
}

/**
 * ---------------------------------------------------------------
 * Parameters: 	A linked list (List*)
 * 				A data item (Data*)
 * Returns: 	None
 * Description:	appends the given data item to the tail of the linked list
 * 				updates size and may update head
 * Assert		list and d are not NULL
 * ---------------------------------------------------
 */
void append_list(List *list, Data *d) {
	assert(list && d);
	Node *new_node = create_node(d, NULL);
	if (list->head == NULL)
		list->head = new_node;
	else {
		Node *current_node = list->head;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	list->size++;
	return;
}

/**
 * ---------------------------------------------------------------
 * Parameters: 	a linked list (List**)
 * Returns: 	None
 * Description:	Destroys a given linked list
 * 				Deletes all nodes (which takes care of destroying data)
 * 				set head to NULL and size to 0
 * 				free list pointer
 * Assert:		**list and *list are is not Null
 * ---------------------------------------------------------------
 */
void destroy_list(List **list) {

	assert(list && *list);

	while ((*list)->size > 0) {
		pop_list(*list, 0);
	}
	(*list)->head = NULL;
	(*list)->size = 0;
	free(*list);
	return;
}

//------------------------- Assignment -------------------------
/**
 * -------------------------------------------------------------------------
 * Parameters: 	a linked list (List*)
 * 				a data item (Data*)
 * 				an index (int)
 * Returns: 	True/False
 * Description:	Inserts the given data item at position (index) at the linked list
 * 				if given index is out of range --> print an error and return False
 * 				returns True if insertion is successful, False otherwise
 * Assert:		given array and data pointers are not Null
 * -------------------------------------------------------------------------
 */
int insert_list(List *list, Data *d, int index) {
	assert(list && d);
	if (index < 0 || index > list->size) {
		printf("Error(insert_list): index out of range\n");
		return 0;
	}

	if (list->size == 0) {
		list->head = create_node(d, NULL);
		list->size++;
	} else {
		Node *curr = list->head;
		Node *prev = NULL;
		int i = 0;
		while (i < index) {
			prev = curr;
			curr = curr->next;
			i++;
		}
		if (prev != NULL) {
			prev->next = create_node(d, curr);
			list->size++;
		} else {
			list->head = create_node(d, curr);

			list->size++;
		}
	}

	return 1;
}

/**
 * -----------------------------------------------------------------
 * Parameters: 	list - a linked list (List*)
 * 				i - an index (int)
 * Returns: 	Copy of popped data (Data*)
 * Description:	deletes the node at position (index) at the linked list
 * 				A copy of the data in the removed node is returned.
 * 				if given index is out of range --> print an error and return NULL
 * 				if given linked list is empty --> print an error and return NULL
 * Asserts:		given linked list is not NULL
 * ------------------------------------------------------------------
 */
Data* pop_list(List *list, int index) {
	assert(list);
	Data *d = NULL;
	if (list->size == 0) {
		printf("Error(pop_list): \n");

		return NULL;

	}
	if (index < 0 || index >= list->size) {
		printf("Error(pop_list): index out of range\n");

		return NULL;
	}

	Node *curr = list->head;
	Node *prev = NULL;

	int i = 0;
	while (i < index) {
		prev = curr;
		curr = curr->next;
		i++;
	}
	if (prev == NULL) {
		d = copy_data(curr->data);
		list->head = curr->next;
		destroy_node(&curr);
		list->size--;
	} else {
		d = copy_data(curr->data);
		prev->next = curr->next;
		destroy_node(&curr);
		list->size--;
	}

	return d;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a linked List (List*)
 * 				start index (int)
 * 				end index  (int)
 * Returns: 	None
 * Description:	deletes items from the list from index start to end (inclusive both ends)
 * 				Updates head and size as necessary
 * 				if given list is empty, print error and return
 *				if given start or end indices are out of range --> print error msg and return
 * Assert:		linked list is not NULL
 * ---------------------------------------------------------------------
 */
void cut_list(List *list, int start, int end) {
	assert(list);
	if (list->size == 0) {
		printf("Error(cut_list): Linked List is empty\n");
		return;

	}
	if (start < 0 || start >= list->size) {
		printf("Error(cut_list): Invalid start index\n");
		return;
	}
	if (end >= list->size || end < start) {
		printf("Error(cut_list): Invalid end index\n");
		return;
	}

	Node *temp1 = NULL;

	Node *node1 = list->head;
	Node *node2 = NULL;
	int i = 0;
	int j = 0;
	if (start == 0 && end == list->size - 1) {
		while (node1->next != NULL) {
			temp1 = node1;
			node1 = node1->next;
			destroy_node(&temp1);

		}
		list->head = NULL;
		list->size = 0;
		return;
	}

	for (i = 0; i < start; i++) {
		temp1 = node1;
		node1 = node1->next;
	}
	node2 = node1;

	for (j = i; j < end; j++) {

		node2 = node2->next;

	}

	if (start == 0) {
		list->head = node2->next;

	} else {
		temp1->next = node2->next;
	}
	for (i = 0; i < end - start; i++) {
		temp1 = node1;
		node1 = node1->next;
		destroy_node(&temp1);

	}
	list->size = list->size - (end - start + 1);
	if (list->size == 0) {
		list->head = NULL;
	}

	return;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a linked list (List*)
 * 				start index (int)
 * 				end index  (int)
 * Returns: 	a linkedList (List*)
 * Description:	Constructs and returns a new linked list.
 * 				The new list contains elements from start to end (inclusive both ends)
 * 				if list is empty, print error msg and return empty list
 * 				if start/end is out of scope, print error msg and return empty list
 * 				Check if end index is greater than or requal to start index
 * Asserts:		list is not NULL
 * ---------------------------------------------------------------------
 */
List* sub_list(List *list, int start, int end) {

	assert(list);
	List *result = create_list();
	if (list->size == 0) {
		printf("Error(sub_list): Linked list is empty\n");
		return result;

	}
	if (start < 0 || start >= list->size) {
		printf("Error(sub_list): Invalid start index\n");
		return result;
	}
	if (end >= list->size || end < start) {
		printf("Error(sub_list): Invalid end index\n");
		return result;
	}

	Node *list_node = list->head;
	Node *result_node = NULL;
	int i = 0;
	int j = 0;

	for (i = 0; i < start; i++) {

		list_node = list_node->next;
	}
	result->head = copy_node(list_node);
	result_node = result->head;
	result->size++;
	list_node = list_node->next;

	for (j = i; j < end; j++) {

		result_node->next = copy_node(list_node);
		result_node = result_node->next;
		list_node = list_node->next;
		result->size++;

	}
	result_node->next = NULL;

	return result;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	a pointer to a linked list (List*)
 * 				i - index of first item (int)
 * 				j - index of second item (int)
 * Returns: 	None
 * Description:	swaps items i and j in the list
 * 				if invalid i and j, print error msg and return
 * Asserts:		asserts given linked list is not Null
 * ---------------------------------------------------------------------
 */
void swap_list(List *list, int i, int j) {

	assert(list);

	if (list->size == 0) {
		printf("Error(swap_list): list is empty\n");
		return;

	}
	if (i < 0 || j < 0 || i >= list->size || j >= list->size) {
		printf("Error (swap_list): Invalid value of i or j\n");
		return;
	}
	if (i == j)
		return;

	Node *curr1 = list->head;
	Node *curr2 = list->head;
	Node *next1 = curr1->next;
	Node *next2 = curr2->next;
	Node *prev1 = NULL;
	Node *prev2 = NULL;

	for (int k = 0; k < i; k++) {
		prev1 = curr1;
		curr1 = next1;
		next1 = next1->next;
	}

	for (int y = 0; y < j; y++) {
		prev2 = curr2;
		curr2 = next2;
		next2 = next2->next;

	}
	if (prev1 == NULL && i + 1 == j) {

		curr1->next = next2;

		curr2->next = curr1;

		list->head = curr2;

	} else if (prev1 == NULL) {
		prev2->next = curr1;
		curr1->next = next2;
		curr2->next = next1;
		list->head = curr2;

	}

	else if (i + 1 == j) {
		prev1->next = curr2;
		curr2->next = curr1;
		curr1->next = next2;

	} else {
		prev1->next = curr2;
		curr2->next = next1;
		prev2->next = curr1;
		curr1->next = next2;

	}

	return;
}

/**
 * ---------------------------------------------------------------------
 * Parameters: 	first linked list (List*)
 * 				second linked list (List*)
 * Returns: 	new list (List*)
 * Description:	Creates a new list that contains items which appear in both lists
 * 				No duplicates allowed
 * Assert:		both linked lists are not NULL
 * ---------------------------------------------------------------------
 */
List* intersection_list(List *list1, List *list2) {
	assert(list1 && list2);
	List *list3 = create_list();
	if (list1->size == 0 || list2->size == 0)
		return list3;

	Node *node1 = list1->head;

	for (int i = 0; i < list1->size; i++) {
		if ((contains_list(list2, node1->data)) == 1) {
			append_list(list3, copy_data(node1->data));

		}
		node1 = node1->next;
	}

	return list3;

}
int contains_list(List *list, Data *d) {
	Node *curr = list->head;
	for (int i = 0; i < list->size; i++) {
		if (equal_data(d, curr->data) == 1) {
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}
int equal_data(Data *d1, Data *d2) {
	if (d1->PID == d2->PID && d1->arrival == d2->arrival
			&& d1->time == d2->time)
		return 1;
	return 0;
}

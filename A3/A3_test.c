/**
 -------------------------
 CP264 (Spring 2020)
 Assignment: A3
 Testing File
 -------------------------
 **/
# include <stdio.h>
# include "A3.h"

void test_sandwich();
void test_print_array();
void test_find_avg_element();
void test_print_ptr_array();

//-------------------------------------------------------------------
int main() {

	setbuf(stdout, NULL);
	test_sandwich();
	test_print_array();
	test_find_avg_element();
	test_print_ptr_array();

	return 0;
}

void test_sandwich() {
	printf("------------------------------\n");
	printf("Start: Testing sandwich:\n\n");
	int *result;

	printf("sandwich(NULL,3) --> ");
	result = sandwich(NULL, 3);
	printf("\n");

	int array1[12] = { 10, 5, 15, 10, 2, 4, 16, 4, 8, 18, 3, 9 };
	result = sandwich(array1, 1);
	if (result == NULL)
		printf("sandwich([10],1) --> NULL\n\n");
	else
		printf("sandwich([10],1) --> %d\n\n", *result);

	result = sandwich(array1, 2);
	if (result == NULL)
		printf("sandwich([10,5],2) --> NULL\n\n");
	else
		printf("sandwich([10,5],2) --> %d\n\n", *result);

	result = sandwich(array1, 3);
	printf("sandwich([10,5,15],3) --> ");
	printf(result == NULL ? "NULL\n\n" : "%d\n\n", *result);

	result = sandwich(array1, 4);
	printf("sandwich([10,5,15,10],4) --> ");
	printf(result == NULL ? "NULL" : "%d\n\n", *result);

	result = sandwich(array1, 5);
	printf("sandwich([10,5,15,10,2],5) --> ");
	printf(result == NULL ? "NULL" : "%d\n\n", *result);

	result = sandwich(array1, 6);
	printf("sandwich([10,5,15,10,2,4],6) --> ");
	printf(result == NULL ? "NULL" : "%d\n\n", *result);

	result = sandwich(array1, 7);
	printf("sandwich([10,5,15,10,2,4,16],7) --> ");
	printf(result == NULL ? "NULL" : "%d\n\n", *result);

	result = sandwich(array1, 9);
	printf("sandwich([10,5,15,10,2,4,16,4,8],9) --> ");
	printf(result == NULL ? "NULL" : "%d\n\n", *result);

	result = sandwich(array1, 12);
	printf("sandwich([10,5,15,10,2,4,16,4,8,18,3,9],12) --> ");
	printf(result == NULL ? "NULL" : "%d\n\n", *result);

	printf("sandwich([10,5,15,10,2,4,16,4,8,18,3,9],0) --> ");
	result = sandwich(array1, 0);
	printf("\n");

	printf("End: Testing sandwich\n");
	printf("------------------------------\n\n");
	return;
}
void test_print_array() {
	printf("------------------------------\n");
	printf("Start: Testing print_array:\n\n");

	char charList[] = { 'P', 'o', 'i', 'n', 't', 'r', 's', '\0' };
	long longList[] = { 10, 20, 30, 40, 50 };
	double doubleList[] = { 0.1, 2.0, 3.3, 4.44, 5.555, 6.6666, 7.77777 };

	printf("Case 0: empty array: \n");
	print_array(longList, 0, 'L');
	printf("\n");

	printf("Case 1 char array: {'P','o','i','n','t','r','s','\\0'}:\n");
	print_array(charList, 8, 'C');
	printf("\n");

	printf("Case 2 long array: {10,20,30,40,50}\n");
	print_array(longList, 5, 'L');
	printf("\n");

	printf(
			"Case 3 double array {0.1, 2.0, 3.3, 4.44, 5.555, 6.6666, 7.77777}\n");
	print_array(doubleList, 7, 'D');
	printf("\n");

	printf("Case 4 short array: {10,20,30,40,50}\n");
	print_array(longList, 5, 'S');
	printf("\n");

	printf("End: Testing pritn_array\n");
	printf("------------------------------\n\n");
	return;
}

void test_find_avg_element() {
	printf("------------------------------\n");
	printf("Start: Testing find_avg_element:\n\n");

	int intList1[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int *ptr = NULL;

	printf("Case 0: Invalid Size:\n");
	ptr = find_avg_element(intList1, 0);

	printf("\nCase 1: NULL pointer:\n");
	ptr = find_avg_element(NULL, 5);

	printf("\nCase 2: {1,2,3,4,5,6,7}\n");
	ptr = find_avg_element(intList1, 7);
	printf("The Average Element is %d which is at index: %d\n", *ptr,
			(ptr - intList1));

	printf("\nCase 3: {1,2,3,4,5,6,7,8}\n");
	ptr = find_avg_element(intList1, 8);
	printf("The Average Element is %d which is at index: %d\n", *ptr,
			(ptr - intList1));

	printf("\nCase 4: {5,5,5,5,5}\n");
	int intList2[5] = { 5, 5, 5, 5, 5 };
	ptr = find_avg_element(intList2, 5);
	printf("The Average Element is %d which is at index: %d\n", *ptr,
			(ptr - intList2));

	printf("\nCase 5: {100,10} \n");
	int intList4[2] = { 100, 10 };
	ptr = find_avg_element(intList4, 2);
	printf("The Average Element is %d which is at index: %d\n", *ptr,
			(ptr - intList4));

	printf("\nCase 6: {1,7,9,23,44}\n");
	int intList3[5] = { 1, 7, 9, 23, 44 };
	ptr = find_avg_element(intList3, 5);
	printf("The Average Element is %d which is at index: %d\n", *ptr,
			(ptr - intList3));
	printf("\n");

	printf("End: Testing find_avg_element\n");
	printf("------------------------------\n\n");
	return;
}

void test_print_ptr_array() {
	printf("------------------------------\n");
	printf("Start: Testing print_ptr_array:\n\n");

	long *ptrs[MAX];

	printf("Case 1:\n");
	long intList1[MAX] = { 10, -4, 20, -4, 30, 40, 50, -4, 60, 70 };
	printf("Array is: ");
	print_array(intList1, MAX, 'L');
	printf("Pointer array contains pointers to elements equal to -4\n");
	printf("Calling print_ptr_array: \n");
	ptrs[0] = &intList1[1];
	ptrs[1] = &intList1[3];
	ptrs[2] = &intList1[7];
	ptrs[3] = NULL;
	print_ptr_array(intList1, ptrs);
	printf("\n");

	long intList2[MAX] = { 1, 2, 3, 1, 5, 6, 1, 7, 8, 1 };
	printf("Case 2:\n");
	printf("Array is: ");
	print_array(intList2, MAX, 'L');
	printf("Pointer array contains pointers to elements equal to 1\n");
	ptrs[0] = &intList2[0];
	ptrs[1] = &intList2[3];
	ptrs[2] = &intList2[6];
	ptrs[3] = &intList2[9];
	ptrs[4] = NULL;
	printf("Calling print_ptr_array: \n");
	print_ptr_array(intList2, ptrs);
	printf("\n");

	printf("End: Testing print_ptr_array\n");
	printf("------------------------------\n\n");
	return;
}


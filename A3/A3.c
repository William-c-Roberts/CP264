/**
 * -------------------------
 * Student Name:
 * Student ID:
 * Student email:
 * -------------------------
 */

# include <stdio.h>
# include <math.h>
# include "A3.h"

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of integers (int*)
 * 	  size: size of an array (const int)
 * returns:
 * 	  last: pointer to last element that is sandwiched between its multiples (int*)
 * Description:
 *    Searches for a number that is sandwiched between its multiples
 *    If multiple numbers exist, then a pointer to the last one is returned.
 *    prints an error message and returns a NULL pointer if array pointer is NULL
 *    	or given size is non-positive
 * -------------------------------------------------------------------
 */
int* sandwich(int *array, const int size) {
	int *ptr = NULL;
	if (size <= 0) {
		printf("Error(sandwich): Invalid array size\n");
		return ptr;
	}
	if (array == NULL) {
		printf("Error(sandwich): Input array is NULL\n");
		return ptr;
	}
	if (size < 3)
		return ptr;
	int i;
	int sand = -1;
	for (i = 1; i < size - 1; i++) {

		if (((array[i - 1] % array[i]) == 0)
				&& ((array[i + 1] % array[i]) == 0))

			sand = i;
	}

	if (sand != -1) {

		ptr = &array[sand];

	}

	return ptr;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 		array: a generic pointer to an array (void*)
 * 		size: size of an array (const int)
 * 		mode: character representing array type (char)67
 * 				'C' --> character array
 * 				'L' --> integer array
 * 				'D' --> double array
 * returns:
 * 		None
 * Description:
 *    Prints contents of an array with formatting depending on printing mode
 *    Mode 1: chars "StringAppearHere"
 *    Mode 2: long { v1 , v2 , v3 , ... }
 *    Mode 3: double { v1.000 , v2.000 , v3.000 , ... }
 *    If size is <= 0 for any type --> print { }
 *    if invalid mode --> print error
 * -------------------------------------------------------------------
 */
void print_array(void *arrayPtr, const int size, char mode) {
	if (size < 0)
		return;
	if (size == 0) {
		printf("{ }\n");
		return;
	}
	int i;

	if (mode == 'C') {
		printf("\"");
		for (i = 0; i < size - 1; i++)
			printf("%c", *((char*) arrayPtr + i));
		printf("\"\n");
	} else if (mode == 'L') {
		printf("{");
		for (i = 0; i < size; i++) {
			if ((i + 1) == size)
				printf(" %ld ", *((long*) arrayPtr + i));
			else
				printf(" %ld ,", *((long*) arrayPtr + i));

		}
		printf("}\n");
	} else if (mode == 'D') {
		printf("{");
		for (i = 0; i < size; i++) {
			if ((i + 1) == size)
				printf(" %.3f ", *((double*) arrayPtr + i));
			else
				printf(" %.3f ,", *((double*) arrayPtr + i));

		}
		printf("}\n");

	} else
		printf("Error(print_array): unsupported mode\n");

	return;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of integers (int*)
 * 	  size: size of an array (const int)
 * returns:
 * 	  ptr: pointer to the element that is equal or closest to average (int*)
 * Description:
 *    1- Finds the average of the values within the array and print it to the console.
 *    2- The average is “ceiled”, i.e. rounded to the upper integer value.
 *    3- Search the array for an element that is equal to the average,
 *      and return a pointer to that element.
 *    4- If there are multiple values equal to the average, a pointer to the
 *      first element that equals to average is returned.
 *    5- If no value is equal to the average, a pointer to the value
 *      closest to the average is returned.
 *    6- prints an error message and returns a NULL pointer if array pointer is NULL
 *    	or given size is non-positive
 * -------------------------------------------------------------------
 */
int* find_avg_element(int *array, const int size) {
	if (size <= 0) {
		printf("Error (find_avg_element): Invalid array size\n");
		return NULL;
	}
	if (array == NULL) {
		printf("Error (find_avg_element): NULL pointer\n");
		return NULL;
	}
	int i;
	double total = 0;
	int avg = 0;
	int location = 0;
	int diff = 999;

	int *index = NULL;
	for (i = 0; i < size; i++)
		total = total + array[i];
	printf("Average = %.1f\n", (total / size));
	avg = ceil(total / size);

	for (i = 0; i < size; i++) {
		if ((int) (fabs(array[i] - avg)) < diff) {

			location = i;
			diff = (int) (fabs(array[i] - avg));
		}

	}
	index = &array[location];

	return index;
}

/**
 * -------------------------------------------------------------------
 * Parameters:
 * 	  array: a pointer to an array of long integers (long*)
 * 	  ptrs: an array of long pointers (long* [])
 * returns:
 * 	  No reutrns
 * Description:
 *    The pointer array stores some pointers to elements in the array
 *    Access the pointer array to print the following:
 *    1-	The index of that element in the array
 *    2-	The value of the element it points to
 *    3-	The value of the previous element
 *    4-	The value of the next element
 *    The maximum size for the pointer array is MAX, and the last item is NULL.
 * -------------------------------------------------------------------
 */
void print_ptr_array(long *array, long *ptrs[]) {
	int i = 0;

	printf("ArrayIndex   Previous     Current      Next         \n");
	while (ptrs[i] != NULL) {
		printf("%-13d", ptrs[i] - array);
		if ((ptrs[i] - array) - 1 < 0)
			printf("%-13d", -1);
		else
			printf("%-13ld", array[(ptrs[i] - array) - 1]);
		printf("%-13ld", *ptrs[i]);
		if ((ptrs[i] - array) + 1 >= MAX)
			printf("%-13d", -1);
		else
			printf("%-13ld", array[(ptrs[i] - array) + 1]);
		printf("\n");
		i++;
	}

	return;
}

/**
 * -------------------------
 * Student Name: will roberts
 * Student ID: 191023880
 * Student email: robe3880@mylaurier.ca
 * -------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lab8.h"

/*
 * ----------------------------------------------------
 * Linear Search (Iterative Version)
 * 					Comparisons
 * Worst Case:		O(n)
 * Best Case: 		O(1)
 * Average Case: 	O(n)
 * ----------------------------------------------------
 */
int linear_search(Data *array, const int size, Data item) {
	assert(array);
	assert(size >= 1);

	int result = -1;
	for (int i = 0; i < size; i++) {
		if (compare_data(&array[i], &item) == 0) {
			result = i;
			break;
		}
	}
	return result;
}

/*
 * ----------------------------------------------------
 * Linear Search (Recursive Version)
 * ----------------------------------------------------
 */
int linear_search_r_aux(Data *array, int start, int end, Data item) {
	if (start > end)
		return -1;
	if (compare_data(&array[start], &item) == 0)
		return start;
	return linear_search_r_aux(array, start + 1, end, item);
}
int linear_search_r(Data *array, const int size, Data item) {
	assert(array);
	assert(size >= 1);
	return linear_search_r_aux(array, 0, size - 1, item);
}

/*
 * ----------------------------------------------------
 * Binary Search (Iterative Version)
 * 					Comparisons
 * Worst Case:		O(log n)
 * Best Case:		O(1)
 * Average Case:	O(log n)
 * ----------------------------------------------------
 */
int binary_search(Data *array, const int size, Data item) {
	assert(array);
	assert(size >= 1);
	int result, middle;
	int start = 0;
	int end = size - 1;
	while (start <= end) {
		middle = (start + end) / 2;
		result = compare_data(&array[middle], &item);

		if (result == 0)
			return middle;
		if (result == 1)
			end = middle - 1;
		else
			start = middle + 1;
	}
	return -1;
}

/*
 * ----------------------------------------------------
 * Binary Search (Recursive Version)
 * ----------------------------------------------------
 */
int binary_search_r_aux(Data *array, int start, int end, Data item) {
	if (start > end)
		return -1;
	int mid = start + (end - start) / 2;
	int result = compare_data(&array[mid], &item);
	if (result == 0)
		return mid;
	if (result == 1)
		return binary_search_r_aux(array, start, mid - 1, item);
	return binary_search_r_aux(array, mid + 1, end, item);
}
int binary_search_r(Data *array, const int size, Data item) {
	assert(array);
	assert(size >= 1);

	return binary_search_r_aux(array, 0, size - 1, item);
}

/*
 * ----------------------------------------------------
 * Algorithm name:		Bubble Sort
 *
 * Time Complexity:
 * 					Comparisons		Swaps
 * Worst Case:		O(n^2)			O(n^2)
 * Best Case:		O(n^2)			O(1)
 * Average Case:	O(n^2)			O(n^2)
 *
 * Memory: O(1)
 *
 * Worst sorting algorithm, but stable, can be improved a bit
 * ----------------------------------------------------
 */
void bubble_sort(Data *array, const int size) {
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (compare_data(&array[j], &array[j + 1]) == 1) {
				swap_data(&array[j], &array[j + 1]);
			}
		}
	}

	return;
}

/*
 * ----------------------------------------------------
 * Algorithm name: 		Selection Sort
 *
 * Time Complexity:
 * 					Comparisons		Swaps
 * Worst Case:		O(n^2)			O(n)
 * Best Case:		O(n^2)			O(1)
 * Average Case:	O(n^2)			O(n)
 *
 * Memory:			O(n)
 * Notes:
 * ----------------------------------------------------
 */
void selection_sort(Data *array, const int size) {
	int i, j, min_indx;
	for (i = 0; i < size - 1; i++) {
		min_indx = i;
		for (j = i + 1; j < size; j++)
			if (compare_data(&array[j], &array[min_indx]) == 2)
				min_indx = j;

		swap_data(&array[min_indx], &array[i]);
	}
	return;
}

/*
 * ----------------------------------------------------
 *  Algorithm name:	Insertion Sort
 *
 * Time Complexity:
 * 					Comparisons		Swaps
 * Worst Case:		O(n^2)			O(n^2)
 * Best Case:		O(n)			O(1)
 * Average Case:	O(n^2)			O(n^2)
 *
 * Memory: O(1)
 * Insertion sort performs better than selection sort
 * 		best when list is partially sorted
 * ----------------------------------------------------
 */
void insertion_sort(Data *array, const int size) {
	int i, j;
	Data key;
	for (i = 1; i <= size; i++) {
		key = array[i];
		j = i - 1;
		while (j >= 0 && compare_data(&array[j], &key) == 1) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;

	}
	return;
}

/*
 * ----------------------------------------------------
 * Algorithm name:	Quick Sort
 *
 * Time Complexity:
 * 					Comparisons
 * Worst Case:		O(n^2)
 * Best Case:		O(n log n)
 * Average Case:	O(n log n)
 *
 * Memory:			O(log n)
 * Notes:
 * ----------------------------------------------------
 */
int partition(Data *array, int start, int end) {
	Data pivot = array[end];
	int pivot_indx = start;
	for (int j = start; j < end; j++) {
		if (compare_data(&array[j], &pivot) == 2) {
			swap_data(&array[pivot_indx], &array[j]);
			pivot_indx++;
		}
	}
	swap_data(&array[pivot_indx], &array[end]);
	return pivot_indx;

}
void quick_sort_aux(Data *array, int start, int end) {
	if (start >= end)
		return;
	int pivot_index = partition(array, start, end);
	quick_sort_aux(array, start, pivot_index - 1);
	quick_sort_aux(array, pivot_index + 1, end);
	return;
}
void quick_sort(Data *array, const int size) {
	assert(array);
	assert(size >= 1);
	quick_sort_aux(array, 0, size - 1);
	return;
}

/*
 * ----------------------------------------------------
 * Algorithm name:		Merge Sort
 *
 * Time Complexity:
 * 					Comparisons
 * Worst Case:		O(n Log n)
 * Best Case:		O(n Log n)
 * Average Case:	O(n Log n)
 *
 * Memory: O(n)
 * Notes:
 * ----------------------------------------------------
 */
void merge(Data *array, int left, int middle, int right) {
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	Data *L = (Data*) malloc(sizeof(Data) * n1);
	Data *R = (Data*) malloc(sizeof(Data) * n1);

	for (i = 0; i < n1; i++)
		L[i] = array[left + i];
	for (j = 0; j < n2; j++)
		R[j] = array[middle + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) {
		if (compare_data(&L[i], &R[j]) == 2
				|| compare_data(&L[i], &R[j]) == 0) {
			array[k] = L[i++];
		} else {
			array[k] = R[j++];
		}
		k++;
	}

	while (i < n1)
		array[k++] = L[i++];
	while (j < n2)
		array[k++] = R[j++];

	free(L);
	L = NULL;
	free(R);
	R = NULL;
	return;
}

void merge_sort_aux(Data *array, int left, int right) {
	if (left >= right)
		return;
	int middle = (left + right) / 2;
	merge_sort_aux(array, left, middle);
	merge_sort_aux(array, middle + 1, right);
	merge(array, left, middle, right);
}
void merge_sort(Data *array, const int size) {
	assert(array);
	assert(size >= 1);
	merge_sort_aux(array, 0, size - 1);
	return;
}


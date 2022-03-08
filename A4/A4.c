/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

#include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <math.h>
# include <stdlib.h>
# include "A4.h"

//-------------------------Task 1 ----------------------------

void format_city(char *city) {
	city[0] = toupper(city[0]);

	int i;
	int check = 0;
	for (i = 0; i < strlen(city); i++) {
		if (city[i] == ' ') {
			if (check == 0) {
				city[i + 1] = toupper(city[i + 1]);
				check++;
			}
			city[i] = city[i + 1];
			city[i + 1] = ' ';

		}
	}

	return;
}

void format_cities(char city_array[][MAX], const int size) {
	if (size <= 0) {
		printf("Error(format_cities): invalid size\n");
		return;
	}
	if (!city_array) {
		printf("Error(format_cities): array is NULL\n");
		return;
	}
	for (int i = 0; i < size; i++) {
		format_city(city_array[i]);
	}
	return;
}

//-------------------------Task 2 ----------------------------

void format_str(const char *inStr, char *outStr) {
	int size = strlen(inStr);
	int i;
	char temp;
	int j;
	printf("\tString Length = %d\n", size);
	printf("\tAfter middle caps = ");
	strcpy(outStr, inStr);
	if (size >= 1) {
		if (size == 1)
			printf("%c", outStr[0]);
		else {
			outStr[0] = tolower(outStr[0]);
			printf("%c", outStr[0]);
			for (i = 1; i < size - 1; i++) {
				outStr[i] = toupper(outStr[i]);
				printf("%c", outStr[i]);
			}
			outStr[size - 1] = tolower(outStr[size - 1]);
			printf("%c", outStr[size - 1]);
		}
	}
	printf("\n");
	printf("\tAfter split = ");
	if (size >= 0) {
		if (size == 1) {
			outStr[1] = outStr[0];
			outStr[0] = ' ';
			printf("%c", outStr[0]);
			printf("%c", outStr[1]);
			size++;
		} else if (size == 1) {
			outStr[0] = ' ';
			printf("%c", outStr[0]);

			size++;
		}

		else {
			for (i = size; i > size / 2; i--)
				outStr[i] = outStr[i - 1];
			outStr[size / 2] = ' ';
			size++;

			for (i = 0; i < size; i++) {

				printf("%c", outStr[i]);
			}
		}
	}
	printf("\n");
	printf("\tAfter First half reverse = ");
	if (size >= 1) {
		if ((size / 2) == 2 && outStr[1] != ' ') {
			temp = outStr[1];
			outStr[1] = outStr[0];
			outStr[0] = temp;

		} else if (outStr[1] == ' ') {

		} else {
			j = (size / 2) - 2;
			for (i = 0; i < j; i++) {
				temp = outStr[i];
				outStr[i] = outStr[j];
				outStr[j] = temp;
				j--;
			}
		}
		for (i = 0; i < size; i++) {
			printf("%c", outStr[i]);
		}
	}
	printf("\n");
	printf("\tAfter Second half reverse = ");
	if (size >= 1) {
		if (size == 3) {
			for (i = 0; i < size; i++)
				printf("%c", outStr[i]);
		} else {

			if ((size - (size / 2)) == 2 && size != 5) {
				temp = outStr[size - 1];
				outStr[size - 1] = outStr[(size / 2)];
				outStr[(size / 2)] = temp;
			} else if (size == 5) {
				temp = outStr[size - 1];
				outStr[size - 1] = outStr[(size - 2)];
				outStr[(size - 2)] = temp;

			} else {
				j = size - 1;
				for (i = (size / 2); i < j; i++) {
					temp = outStr[i];
					outStr[i] = outStr[j];
					outStr[j] = temp;
					j--;
				}
			}
			for (i = 0; i < size; i++) {
				printf("%c", outStr[i]);
			}
		}

	}
	printf("\n");
	return;
}

//-------------------------Task 3 ----------------------------

int* get_multiples_array1(int *multiples, const int size) {
	if (size <= 0) {
		printf("Error(get_multiples_array1): invalid size\n");
		return NULL;
	}
	if (!multiples) {
		printf("Error(get_multiples_array1): invalid array\n");
		return NULL;
	}
	int *array = (int*) malloc(10 * size * sizeof(int));
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < 10; j++) {

			if (multiples[i] * (j + 1) >= 1000)
				*(array + i * 10 + j) = 0;
			else
				*(array + i * 10 + j) = (multiples[i] * (j + 1));
		}

	return array;
}

void print_multiples1(int *array, const int size) {
	if (size <= 0) {
		printf("Error(print_multiples1): invalid size\n");
		return;
	}
	if (!array) {
		printf("Error(print_multiples1): invalid array\n");
		return;
	}
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < 10; j++) {
			printf("%3d", *(array + i * 10 + j));
			if (j < 9)
				printf(" ");
		}
		printf("\n");
	}

	return;
}

//-------------------------Task 4 ----------------------------
int** get_multiples_array2(int *multiples, const int size) {
	if (size <= 0) {
		printf("Error(get_multiples_array2): invalid size\n");
		return NULL;
	}
	if (!multiples) {
		printf("Error(get_multiples_array2): invalid array\n");
		return NULL;
	}
	int i, j;
	int **arr = (int**) malloc(size * sizeof(int*));
	for (i = 0; i < size; i++)
		arr[i] = (int*) malloc(10 * sizeof(int));

	for (i = 0; i < size; i++) {
		for (j = 0; j < 10; j++) {

			if (multiples[i] * (j + 1) >= 1000)
				arr[i][j] = 0;
			else

				arr[i][j] = multiples[i] * (j + 1);

		}
	}
	return arr;
}

void print_multiples2(int **array, const int size) {
	if (!array) {
		printf("Error(print_multiples2): invalid array\n");
		return;
	}
	if (size <= 0) {
		printf("Error(print_multiples2): invalid size\n");
		return;
	}
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < 10; j++) {
			printf("%3d", (array[i][j]));
			if (j < 9)
				printf(" ");
		}
		printf("\n");
	}

	return;
}

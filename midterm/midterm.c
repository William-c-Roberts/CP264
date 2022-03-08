/* CP264 Spring 2021 Midterm */

/*
 * ---------------------------------
 * Student Name:Will Roberts
 * Student ID:191023880
 * Student Email:robe3880@mylaurier.ca
 * ---------------------------------
 */

/**
 * ---------------------------------
 *	I certify that I completed this midterm according to academic honesty guidelines
 *	I attest that i did not use any external help, neither in person nor virtually. I
 *	understand that plagiarizing will lead to my failure in the course, in addition to
 *	other penalties according to the University polices.
 *
 *
 * ---------------------------------
 */

/**
 * ---------------------------------
 *
 * the task one and two works in a linux vm
 *
 *
 * ---------------------------------
 */

//---- Do not change imports -----------------
#include "midterm.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//---------------------------------------------

//----------------- Task 1 ---------------------
int replace_char(char *file_name, char letter1, char letter2) {
	FILE *in_file = fopen(file_name, "r+");

	if (in_file != NULL) {
		if (isalpha(letter1) == 0) {
			printf("a");
			fprintf(in_file,
					"Error (remove_letter): invalid input characters\n");
			return -1;
		} else if (isalpha(letter2) != 0) {
			fprintf(in_file,
					"Error (remove_letter): invalid input characters\n");
			return -1;
		}

		char ch;
		int count = 0, i = 0;

		while ((ch = getc(in_file)) != EOF) {
			i++;
			if (ch == letter1) {
				count++;
				fseek(in_file, -1, SEEK_CUR);
				fputc((int) letter2, in_file);

			}
		}

		fclose(in_file);
		return count;

	} else {
		printf("Error (remove_letter): unable to open file %s\n", file_name);
		return -1;
	}
}

//----------------- Task 2 ---------------------
void update_array(int **array, const int size, int multiplier) {
	int old_array[size];
	int i = 0;
	for (i = 0; i < size; i++) {
		old_array[i] = (*array)[i];
	}

	*array = (int*) realloc(*array, size * multiplier);
	for (i = 0; i < size; i++) {
		int value = old_array[i];
		for (int j = 0; j < multiplier; j++) {

			(*array)[i * multiplier + j] = value;
		}
	}

	return;
}

//----------------- Task 3 ---------------------
char* sentence_to_words(char *sentence) {
	int i = 2;
	if (sentence == NULL) {
		printf("Error (sentence_to_words): invalid input\n");
		return "";

	} else if (strlen(sentence) == 0) {
		printf("This is an empty sentence\nNo words found\n");
		return "";

	} else {
		char *first = strtok(sentence, " ");
		char *token = strtok(NULL, " ");

		if (token == NULL) {
			printf("This is a single word sentence\n");
			printf("word : %s\n", first);

		} else {
			printf("This is a multi-word sentence:\n");
			printf("word 1: %s\n", first);

			while (token != NULL) {
				printf("word %d: %s\n", i, token);
				i++;
				first = token;
				token = strtok(NULL, " ");
			}

		}

		return first;
	}
}

//----------------- Task 4 ---------------------
void update_pointers(float *array, const int size, float **ptr1, float **ptr2,
		char mode) {
	if (!array) {
		printf("Error (update_pointers): Null array\n");
		return;
	}
	if (size <= 0) {
		printf("Error (update_pointers): invalid size\n");
		return;
	}
	if (!ptr1 || !ptr2) {
		printf("Error (update_pointers): invalid pointer\n");
		printf("Error (update_pointers): invalid pointer\n");
		return;
	}

	int i, max = 0, min = 0;
	if (mode == 'a') {
		for (i = 1; i < size; i++) {
			if (array[i] > array[max])
				max = i;
			if (array[i] < array[min])
				min = i;
		}
		*ptr2 = &array[max];
		*ptr1 = &array[min];
	} else if (mode == 'z') {
		for (i = 1; i < size; i++) {
			if (array[i] > array[max])
				max = i;
			if (array[i] < array[min])
				min = i;
		}
		*ptr1 = &array[max];
		*ptr2 = &array[min];
	} else
		printf("Error (update_pointers): invalid mode\n");
	return;
}

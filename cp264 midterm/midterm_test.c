/* CP264 Spring 2021 Midterm */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "midterm.h"

void copy_file(const char *in_file, const char *out_file);
void wipe_files();
void file_to_console(char *filename);
void print_array(int *array, const int size);
void print_array2(float *array, const int size);

void test_replace_char();
void test_update_array();
void test_sentence_to_words();
void test_update_pointers();

int main() {
	setbuf(stdout, NULL);

	//test_replace_char();
	//test_update_array();
	//test_sentence_to_words();
	test_update_pointers();

	return 0;
}

//----------------- Task 1: replace_char ---------------------
void test_replace_char() {
	int counter = 0;
	wipe_files();

	printf("--------------Testing replace_char --------------\n\n");

	printf("Case 1: Replacing a with _\n");
	copy_file("input1.txt", "input11.txt");
	counter = replace_char("input11.txt", 'a', '_');
	printf("Number of matches = %d\n", counter);
	file_to_console("input11.txt");
	printf("\n");

	printf("Case 2: Replacing g with $\n");
	copy_file("input1.txt", "input12.txt");
	counter = replace_char("input12.txt", 'g', '$');
	printf("Number of matches = %d\n", counter);
	file_to_console("input12.txt");
	printf("\n");

	printf("Case 3: Replacing N with *\n");
	copy_file("input1.txt", "input13.txt");
	counter = replace_char("input13.txt", 'N', '*');
	printf("Number of matches = %d\n", counter);
	file_to_console("input13.txt");
	printf("\n");

	printf("Case 4: Error scenarios:\n");
	copy_file("input1.txt", "input14.txt");
	counter = replace_char("input14.txt", '.', '&');
	printf("Number of matches = %d\n", counter);
	counter = replace_char("input14.txt", 'y', 'u');
	printf("Number of matches = %d\n", counter);
	counter = replace_char("nothing.txt", 'g', '$');
	printf("Number of matches = %d\n\n", counter);

	printf("--------------End of Testing replace_char --------------\n\n");

	return;
}

//----------------- Task 2: update_array ---------------------
void test_update_array() {
	int i, j, size = 0, multiplier = 0, *array = NULL;
	printf("--------------Testing update_array --------------\n\n");

	int cases[4][2] = { { 6, 2 }, { 4, 3 }, { 10, 1 }, { 5, 0 } };
	for (j = 0; j < 4; j++) {
		size = cases[j][0];
		multiplier = cases[j][1];
		printf("Case %d: size = %d, multiplier = %d\n", (j + 1), size,
				multiplier);
		array = (int*) malloc(sizeof(int) * size);
		for (i = 0; i < size; i++)
			array[i] = (i + 1) * 10;
		printf("Array Before update:\n");
		print_array(array, size);
		update_array(&array, size, multiplier);
		printf("Array after update:\n");
		if (multiplier > 0)
			size = size * multiplier;
		print_array(array, size);
		free(array);
		printf("\n");
	}
	printf("--------------End of Testing update_array --------------\n\n");
	return;
}

//----------------- Task 3: sentence_to_words ---------------------
void test_sentence_to_words() {
	printf("------------ Testing sentence_to_words --------------\n\n");

	char sentence[100], *last_word;

	printf("Case 1: sentence with 2 words:\n");
	strcpy(sentence, "Good luck!");
	printf("sentence = %s\n", sentence);
	last_word = sentence_to_words(sentence);
	printf("last word is: %s\n", last_word);
	free(last_word);
	printf("\n");

	printf("Case 2: sentence with 1 word:\n");
	strcpy(sentence, "Fantastic!");
	printf("sentence = %s\n", sentence);
	last_word = sentence_to_words(sentence);
	printf("last word is: %s\n", last_word);
	free(last_word);
	printf("\n");

	printf("Case 3: sentence with 5 words:\n");
	strcpy(sentence, "Best wishes for the midterm");
	printf("sentence = %s\n", sentence);
	last_word = sentence_to_words(sentence);
	printf("last word is: %s\n", last_word);
	free(last_word);
	printf("\n");

	printf("Case 4: empty sentence:\n");
	strcpy(sentence, "");
	printf("sentence = %s\n", sentence);
	last_word = sentence_to_words(sentence);
	printf("last word is: %s\n", last_word);
	free(last_word);
	printf("\n");

	printf("Case 5: NULL sentence:\n");
	last_word = sentence_to_words(NULL);
	printf("last word is: %s\n", last_word);
	free(last_word);
	printf("\n");

	printf("----------- End of Testing sentence_to_words --------------\n\n");
	return;
}

//----------------- Task 3: sentence_to_words ---------------------
void test_update_pointers() {
	printf("------------ Testing update_pointers --------------\n\n");

	float array[10] = { 10.2, 7.3, 5.6, 9.8, 11.2, 7.5, 3.7, 11.1, 5.8, 9.1 };
	float *p1 = NULL, *p2 = NULL;
	int size = 0;

	int cases[4] = { 6, 4, 10, 1 };
	for (int i = 0; i < 4; i++) {
		printf("Case %d:\n", (i + 1));
		size = cases[i];
		p1 = &array[0];
		p2 = &array[size - 1];
		print_array2(array, size);
		printf("Before:         p1 = %.2f , p2 = %.2f\n", *p1, *p2);
		printf("Using mode 'a': ");
		update_pointers(array, size, &p1, &p2, 'a');
		printf("p1 = %5.2f , p2 = %.2f\n", *p1, *p2);
		printf("Using mode 'z': ");
		p1 = &array[0];
		p2 = &array[size - 1];
		update_pointers(array, size, &p1, &p2, 'z');
		printf("p1 = %5.2f , p2 = %.2f\n", *p1, *p2);
		printf("\n");
	}

	printf("Case 5: Error cases:\n");
	update_pointers(NULL, size, &p1, &p2, 'a');
	update_pointers(array, 0, &p1, &p2, 'a');
	update_pointers(array, 5, &p1, &p2, 'r');
	update_pointers(array, 5, NULL, &p2, 'a');
	float *ptr1 = NULL;
	float **ptr2 = &ptr1;
	update_pointers(array, 5, &p1, ptr2, 'a');
	printf("\n");

	printf("----------- End of Testing update_pointers --------------\n\n");
	return;
}
//----------------- Utility files --------------------------------
void copy_file(const char *in_file, const char *out_file) {
	FILE *source = NULL, *destination = NULL;
	source = fopen(in_file, "r");
	if (source == NULL) {
		printf("Error(copy_file2): Could not open file %s\n", in_file);
		return;
	}

	destination = fopen(out_file, "w");
	if (destination == NULL) {
		printf("Error (copy_file2): Could not open file %s\n", out_file);
		return;
	}

	char line[MAX];
	while (fgets(line, sizeof(line), source) != NULL)
		fprintf(destination, "%s", line);

	fclose(source);
	fclose(destination);
	return;
}

void wipe_files() {
	char filename[4][30] = { "input11.txt", "input12.txt", "input13.txt",
			"input14.txt" };
	FILE *fptr = NULL;
	for (int i = 0; i < 4; i++) {
		fptr = fopen(filename[i], "w");
		if (fptr == NULL) {
			printf("Error(wipe_files): Could not open file %s\n", filename[i]);
			return;
		}
		fclose(fptr);
		fptr = NULL;
	}
	return;
}

void file_to_console(char *filename) {
	FILE *fptr;
	fptr = fopen(filename, "r");
	if (fptr == NULL) {
		printf("Error(file_to_console): Could not open file %s\n", filename);
		return;
	}

	char c;
	fscanf(fptr, "%c", &c);
	while (!feof(fptr)) {
		printf("%c", c);
		fscanf(fptr, "%c", &c);
	}
	fclose(fptr);
	return;
}

void print_array(int *array, const int size) {
	int i;
	printf("[ ");
	for (i = 0; i < size - 1; i++)
		printf("%d , ", array[i]);
	printf("%d ]\n", array[i]);
	return;
}

void print_array2(float *array, const int size) {
	int i;
	printf("[ ");
	for (i = 0; i < size - 1; i++)
		printf("%.2f , ", array[i]);
	printf("%.2f ]\n", array[i]);
	return;
}

#include <stdio.h>
#include <string.h>
#include "A5.h"

void test_analyze_file(FILE *fptr);
void test_format_file1(FILE *fptr);
void test_format_file2(FILE *fptr);
void test_get_city_details(FILE *fptr);
void test_replace_is(FILE *fptr);

void copy_file(const char *in_file, FILE *destination);
void copy_file2(const char *in_file, const char *out_file);
void wipe_files();

int main() {
	setbuf(stdout, NULL);

	wipe_files();

	char out_file[] = "my_output.txt";
	FILE *destination = NULL;
	destination = fopen(out_file, "w");
	if (out_file == NULL) {
		printf("Error(analyze_file): Could not open file %s\n", out_file);
		return 0;
	}

	test_analyze_file(destination);
	test_format_file1(destination);
	test_format_file2(destination);
	test_get_city_details(destination);
	test_replace_is(destination);

	fclose(destination);
	return 0;
}

void test_analyze_file(FILE *fptr) {

	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: analyze_file:\n\n");

	char filename[30];

	strcpy(filename, "cIntro.txt");
	analyze_file(filename, "analyze_file_output.txt");

	strcpy(filename, "chistory.txt");
	analyze_file(filename, "analyze_file_output.txt");

	strcpy(filename, "nothing.txt");
	analyze_file(filename, "analyze_file_output.txt");

	copy_file("analyze_file_output.txt", fptr);

	fprintf(fptr, "\nEnd Testing: analzye_file\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}

void test_format_file1(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: format_file1:\n\n");

	char filename[30];

	strcpy(filename, "cIntro.txt");
	fprintf(fptr, "Case 1: formatting %s:\n\n", filename);
	format_file1(filename, "format_file1_output.txt");
	copy_file("format_file1_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	strcpy(filename, "chistory.txt");
	fprintf(fptr, "Case 2: formatting %s:\n\n", filename);
	format_file1(filename, "format_file1_output.txt");
	copy_file("format_file1_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	strcpy(filename, "nothing.txt");
	fprintf(fptr, "Case 3: formatting %s:\n\n", filename);
	format_file1(filename, "format_file1_output.txt");
	copy_file("format_file1_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	fprintf(fptr, "\nEnd Testing: format_file1\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}

void test_format_file2(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: format_file2:\n\n");

	char filename[30];

	strcpy(filename, "cIntro.txt");
	fprintf(fptr, "Case 1: formatting %s:\n\n", filename);
	format_file2(filename, "format_file2_output.txt");
	copy_file("format_file2_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	strcpy(filename, "chistory.txt");
	fprintf(fptr, "Case 2: formatting %s:\n\n", filename);
	format_file2(filename, "format_file2_output.txt");
	copy_file("format_file2_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	strcpy(filename, "nothing.txt");
	fprintf(fptr, "Case 3: formatting %s:\n\n", filename);
	format_file2(filename, "format_file2_output.txt");
	copy_file("format_file2_output.txt", fptr);
	fprintf(fptr, "\n----\n");

	fprintf(fptr, "\nEnd Testing: format_file2\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}

void test_get_city_details(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: get_city_details:\n\n");

	char city[30], in_file[30], out_file[] = "get_city_details_output.txt";

	strcpy(in_file, "ontario.txt");
	strcpy(city, "Toronto");
	get_city_details(in_file, out_file, city);
	fprintf(fptr, "\n");

	strcpy(city, "Barrie");
	get_city_details(in_file, out_file, city);

	strcpy(city, "Sherbrooke");
	get_city_details(in_file, out_file, city);

	strcpy(in_file, "Quebec.txt");
	strcpy(city, "Sherbrooke");
	get_city_details(in_file, out_file, city);

	strcpy(in_file, "BC.txt");
	strcpy(city, "Vancouver");
	get_city_details(in_file, out_file, city);

	copy_file(out_file, fptr);

	fprintf(fptr, "\nEnd Testing: get_city_details\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}

void test_replace_is(FILE *fptr) {
	fprintf(fptr, "------------------------------\n");
	fprintf(fptr, "Start testing: replace_is:\n\n");

	//create a copy of "ontario.txt" and "Quebec.txt" in order not to destroy original files
	char file1[] = "ontario.txt", file2[] = "Quebec.txt";
	char file11[] = "ontario2.txt", file22[] = "Quebec2.txt";
	copy_file2(file1, file11);
	copy_file2(file2, file22);

	fprintf(fptr, "Replacing \"is\" with \"==\" in file %s\n", file11);
	replace_is(file11, "==");
	copy_file(file11, fptr);
	fprintf(fptr, "\n");

	fprintf(fptr, "Replacing \"is\" with \":=\" in file %s\n", file22);
	replace_is(file22, ":=");
	copy_file(file22, fptr);
	fprintf(fptr, "\n");

	fprintf(fptr, "End Testing: replace_is\n");
	fprintf(fptr, "------------------------------\n\n");

	return;
}
//------------- utility functions --------------------
void copy_file(const char *in_file, FILE *destination) {
	FILE *source = NULL;
	source = fopen(in_file, "r");
	if (source == NULL) {
		printf("Error(copy_file): Could not open file %s\n", in_file);
		return;
	}
	char character = fgetc(source);
	while (character != EOF) {
		fprintf(destination, "%c", character);
		character = fgetc(source);
	}
	fclose(source);
	return;
}

void copy_file2(const char *in_file, const char *out_file) {
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
	char filename[4][30] = { "analyze_file_output.txt",
			"format_file1_output.txt", "format_file2_output.txt",
			"get_city_details_output.txt", };
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

/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

#include <stdio.h>
# include <stdlib.h>
#include<ctype.h>
#include "A5.h"

//---------------------- Task 1 ---------------------------------
void analyze_file(const char *filename, const char *filename2) {

	int num_parg = 0, num_lines = 0, num_words = 0, num_letters = 0,
			num_digits = 0, num_other = 0, prev_space = 1, prev_newline = 1;

	FILE *in_file = fopen(filename, "r");
	FILE *out_file = fopen(filename2, "a");

	if (in_file != NULL) {

		char ch;

		for (ch = getc(in_file); ch != EOF; ch = getc(in_file)) {
			if (isspace(ch) == 0 && (prev_space == 1)) {
				num_words++;
				prev_space = 0;
			}
			if (ch == '\n' && (prev_newline == 1)) {
				num_parg++;
				prev_newline = 0;
			}

			if (ch == '\n') {
				num_lines++;
				prev_space = 1;
				prev_newline = 1;

			} else if (isalpha(ch) != 0) {
				num_letters++;
				prev_newline = 0;
				prev_space = 0;
			} else if (ch == ' ')
				prev_space = 1;
			else if (isdigit(ch) != 0) {
				num_digits++;
				prev_newline = 0;
				prev_space = 0;
			} else if (ispunct(ch) != 0) {
				num_other++;
				prev_newline = 0;
				prev_space = 0;
			}

		}
		num_lines++;
		num_parg++;

		fprintf(out_file, "Analyzing file %s\n", filename);
		fprintf(out_file, "#Paragraphs = %d\n", num_parg);
		fprintf(out_file, "#lines = %d\n", num_lines);

		fprintf(out_file, "#Words = %d\n", num_words);
		fprintf(out_file, "#Characters = %d\n",
				num_letters + num_digits + num_other);
		fprintf(out_file, "Alpha = %d\n", num_letters);
		fprintf(out_file, "Numerical = %d\n", num_digits);
		fprintf(out_file, "Other = %d\n\n", num_other);
	} else
		fprintf(out_file, "Error(analyze_file): Could not open file %s\n",
				filename);

	fclose(in_file);
	fclose(out_file);

	return;
}

//---------------------- Task 2 ---------------------------------
void format_file1(const char *in_file, const char *out_file) {

	FILE *infile = fopen(in_file, "r");
	FILE *outfile = fopen(out_file, "w");

	if (infile != NULL) {

		char ch;
		int i = 0;
		int nl = 0;

		for (ch = getc(infile); ch != EOF; ch = getc(infile)) {
			if (ch == '\n' && nl == 0) {
				i++;
				nl = 1;
			}
			if (ch == ' ' && nl == 0)
				i++;
			if (i == 4) {
				fprintf(outfile, "\n");
				i = 0;

			} else if (ch == '.') {
				fprintf(outfile, "%c ", ch);

			} else {
				if (ch != '\n') {
					fprintf(outfile, "%c", ch);
					nl = 0;
				}

			}

		}
	} else {
		fprintf(outfile, "Error(format_file1): Could not open file %s\n",
				in_file);
	}
	fclose(infile);
	fclose(outfile);

	return;
}
//---------------------- Task 3 ---------------------------------
void format_file2(const char *in_file, const char *out_file) {
	FILE *infile = fopen(in_file, "r");
	FILE *outfile = fopen(out_file, "w");

	if (infile != NULL) {

		char ch;
		int i = 0;
		int nl = 0;

		for (ch = getc(infile); ch != EOF; ch = getc(infile)) {
			if (ch == '\n' && nl != 1) {
				fprintf(outfile, ".");
				nl = 1;
			}
			if (isdigit(ch) != 0 || isalpha(ch) != 0 || ch == '\n'
					|| ch == ' ') {
				if (nl == 1 && isalpha(ch) != 0) {
					fprintf(outfile, "%c", toupper(ch));
					nl = 0;
				} else
					fprintf(outfile, "%c", ch);
			}
		}
		fprintf(outfile, ".\n");
	} else
		fprintf(outfile, "Error(format_file2): Could not open file %s\n",
				in_file);

	fclose(infile);
	fclose(outfile);

	return;
}

//---------------------- Task 4 ---------------------------------
void get_city_details(const char *in_file, const char *out_file, char *city) {
	FILE *infile = fopen(in_file, "r");
	FILE *outfile = fopen(out_file, "a");
	char line[256];
	char *token;

	while (fgets(line, sizeof(line), infile)) {
		token = strtok(line, " ");
		printf("%s\n", token);

		while (token != NULL) {
			token = strtok(NULL, " ");
			printf("%s\n", token);
		}
	}

	return;
}

//---------------------- Task 5 ---------------------------------
void replace_is(const char *filename, char *new_str) {
//your code here
	return;
}


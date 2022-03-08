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
# include <string.h>
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

		fprintf(out_file, "Analyzing file %s:\n", filename);
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
				fprintf(outfile, " \n");
				i = 0;

			} else if (ch == '.') {
				fprintf(outfile, "%c", ch);

			} else {
				if (nl == 1 && i > 0 && ch != '\n') {
					fprintf(outfile, " %c", ch);
					nl = 0;
				}

				else if (ch != '\n') {
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
	char *token, *results[4];
	int found = 0;
	fprintf(outfile, "Searching for %s in \"%s\":\n", city, in_file);
	if (infile != NULL) {

		while (fgets(line, sizeof(line), infile) != NULL && found == 0) {
			token = strtok(line, " ");
			token = strtok(NULL, " ");
			token = strtok(NULL, " ");

			if (strcmp(city, token) == 0) {
				found = 1;
				results[0] = token;
				token = strtok(NULL, " ");
				token = strtok(NULL, " ");
				results[1] = token;
				token = strtok(NULL, " ");
				token = strtok(NULL, " ");
				token = strtok(NULL, " ");
				token = strtok(NULL, " ");
				token = strtok(NULL, " ");
				results[2] = token;

				if (strcmp(in_file, "ontario.txt") == 0)
					fprintf(outfile, "Province = Ontario\n");
				else if (strcmp(in_file, "Quebec.txt") == 0)
					fprintf(outfile, "Province = Quebec\n");
				fprintf(outfile, "Population = %s\n", results[1]);
				fprintf(outfile, "Area = %s\n", results[2]);

			}

		}

		if (found == 0)
			fprintf(outfile, "Could not find %s in \"%s\"\n\n", city, in_file);
	} else
		fprintf(outfile, "Error(get_city_details): Could not open file %s\n",
				in_file);

	fclose(infile);
	fclose(outfile);

	return;
}

//---------------------- Task 5 ---------------------------------
void replace_is(const char *filename, char *new_str) {
	FILE *infile = fopen(filename, "r+");

	char line[256];
	char *token;
	int l1 = 0, l2 = 0, l3 = 0, i = 0, temp = 0;
	int num[12][3];

	if (infile != NULL) {

		while (fgets(line, sizeof(line), infile) != NULL) {
			l1 = 0;
			l2 = 0;
			temp = 0;
			token = strtok(line, " ");
			l1 = l1 + strlen(token);
			token = strtok(NULL, " ");
			l1 = l1 + strlen(token);
			token = strtok(NULL, " ");
			l1 = l1 + strlen(token);
			l2 = l1;
			token = strtok(NULL, " ");
			if (strcmp(token, "City") == 0) {
				l1 = l1 + strlen(token) + 1;
				l2 = l1;
				token = strtok(NULL, " ");
			}

			l2 = l2 + strlen(token);
			token = strtok(NULL, " ");
			l2 = l2 + strlen(token);
			token = strtok(NULL, " ");
			l2 = l2 + strlen(token);
			token = strtok(NULL, " ");
			l2 = l2 + strlen(token);
			token = strtok(NULL, " ");
			l2 = l2 + strlen(token);
			token = strtok(NULL, " ");
			temp = temp + strlen(token);
			token = strtok(NULL, " ");
			temp = temp + strlen(token);
			l1 = l1 + 3;
			l2 = l2 + 8;
			l3 = l3 + temp + l2;
			num[i][0] = l1;
			num[i][1] = l2;
			num[i][2] = l3;
			i++;

		}

		fseek(infile, num[0][0], SEEK_SET);
		fprintf(infile, "%s", new_str);
		fseek(infile, num[0][1], SEEK_SET);
		fprintf(infile, "%s", new_str);
		for (int j = 1; j < i; j++) {

			fseek(infile, num[j - 1][2] + num[j][0] + (2 * j), SEEK_SET);

			fprintf(infile, "%s", new_str);
			fseek(infile, num[j - 1][2] + num[j][1] + (2 * j), SEEK_SET);
			fprintf(infile, "%s", new_str);
		}

	}

	fclose(infile);

	return;
}


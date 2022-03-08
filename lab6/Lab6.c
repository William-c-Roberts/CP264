/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void count_letters(const char *filename, int counters[26]);
void write_results(const char *filename, int counters[26]);
void append_sum(const char *filename, int counters[26]);

int main() {
	setbuf(stdout, NULL);

	char filename[20] = "text1.txt";
	int counters[26] = { 0 };

	count_letters(filename, counters);

	filename[4] = '2';
	write_results(filename, counters);

	append_sum(filename, counters);

	printf("Check text2.txt for output\n");

	return 0;
}

void count_letters(const char *filename, int counters[26]) {
	FILE *in_file = fopen(filename, "r");

	if (in_file != NULL) {

		char ch;

		for (ch = getc(in_file); ch != EOF; ch = getc(in_file)) {
			if (isalpha(ch) != 0) {
				counters[(int) tolower(ch) - 97]++;
			}

		}

	} else {
		printf("error(count_letters): invalid file");
	}

	return;
}

void write_results(const char *filename, int counters[26]) {
	FILE *out_file = fopen(filename, "w");
	if (out_file != NULL) {
		for (int i = 0; i < 26; i++) {
			fprintf(out_file, "count(%c) = %d\n", ((char) i + 97), counters[i]);
		}
	} else {
		printf("error(write_results): invalid file");
	}
	return;

}

void append_sum(const char *filename, int counters[26]) {
	FILE *out_file = fopen(filename, "a");
	if (out_file != NULL) {
		int sum = 0;
		for (int i = 0; i < 26; i++) {
			sum = sum + counters[i];
		}
		fprintf(out_file, "Total = %d", sum);
	} else {
		printf("error(append_sum): invalid file");
	}
	return;
}


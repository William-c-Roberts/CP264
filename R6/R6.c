/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */

# include<stdio.h>
# include <stdlib.h>
# include <string.h>

void write_nums(const char *filename, int start, int end) {
	FILE *out_file = NULL;

	out_file = fopen(filename, "w");
	if (out_file == NULL) {
		printf("Error(write_nums): could not open file %s\n", filename);
		return;
	}
	for (int i = start; i <= end; i++) {
		fprintf(out_file, "%d\n", i);
	}

	fclose(out_file);
	return;
}

int read_nums(const char *filename, int *array) {
	FILE *fptr = NULL;

	fptr = fopen(filename, "r");
	if (fptr == NULL) {
		printf("Error(read_nums): could not open file %s\n", filename);
		return -1;
	}
	int i = 0, temp;
	fscanf(fptr, "%d", &temp);
	array[i++] = temp;
	while (!feof(fptr)) {

		fscanf(fptr, "%d", &temp);
		array[i++] = temp;
	}
	fclose(fptr);
	return i - 1;
}

int extract_minutes(char *filename, unsigned int *minutes_array, const int size) {
	FILE *in_file = NULL;

	in_file = fopen(filename, "r");
	if (in_file == NULL) {
		fprintf(in_file, ",Error(extract_minutes): could not open file %s\n",
				filename);
		return -1;
	}
	char line[10], mm[3], *end_ptr = NULL;
	int counter = 0;
	mm[2] = '\0';
	while (fgets(line, sizeof(line), in_file) != NULL && counter < size) {
		mm[0] = line[3];
		mm[1] = line[4];
		minutes_array[counter++] = (unsigned int) strtol(mm, &end_ptr, 10);
	}
	fclose(in_file);
	return counter;
}

void print_record_info1(char *record) {
	char *token = NULL, *results[5];
	int i = 0, length = 0;
	record++;

	token = strtok(record, "-");
	results[i++] = token;
	while (token != NULL) {
		token = strtok(NULL, "-");
		results[i++] = token;
	}
	length = strlen(results[4]);
	results[4][length - 1] = '\0';

	printf("Registration year = %s\n", results[0]);
	printf("Birthday = %s %s-%s\n", results[1], results[2], results[3]);
	printf("Name = %s\n", results[4]);
	return;
}

void print_record_info2(char *record) {
	int reg_year, day, year;
	char month[11], first[20], last[20];

	record++;
	sscanf(record, "%d %s %d %d %s %s", &reg_year, month, &day, &year, first,
			last);
	last[strlen(last) - 1] = '\0';
	printf("Registration year = %d\n", reg_year);
	printf("Birthday = %d %s-%d\n", year, month, day);
	printf("Name = %s %s\n", first, last);
	return;
}

void print_record_info3(char *record) {
	int reg_year, day, year;
	char month[11], first[20], last[20];
	char *buffer1 = NULL, *buffer2 = NULL, *buffer3 = NULL;
	buffer1 = strtok(record, ":");
	buffer1 = strtok(NULL, "-");
	sscanf(buffer1, "%d", &reg_year);
	buffer1 = strtok(NULL, "-");
	buffer3 = strtok(NULL, "-");

	buffer2 = strtok(buffer1, ",");
	strcpy(month, buffer2);
	buffer2 = strtok(NULL, ",");
	sscanf(buffer2, "%d", &day);
	buffer2 = strtok(NULL, ",");
	sscanf(buffer2, "%d", &year);

	sscanf(++buffer3, "%s %s", first, last);
	last[strlen(last) - 1] = '\0';
	printf("Registration year = %d\n", reg_year);
	printf("Birthday = %d %s-%d\n", year, month, day);
	printf("Name = %s %s\n", first, last);

	return;
}

void modify_grades(char *filename, int bonus) {
	FILE *in_file;

	in_file = fopen(filename, "r+");
	if (in_file == NULL) {
		printf("Error(modify_grades): could not open file %s\n", filename);
		return;
	}

	char record[20], *grade_str, *end_ptr;
	int grade, record_num = 0;
	while (fgets(record, 15, in_file) != NULL) {
		grade_str = strtok(record, ",");
		grade_str = strtok(NULL, "]");
		grade = ((int) strtol(grade_str, &end_ptr, 10)) + bonus;

		fseek(in_file, 11 + (14 * record_num), SEEK_SET);
		fprintf(in_file, "%d", grade);
		fseek(in_file, 1, SEEK_CUR);
		record_num++;

	}

	fclose(in_file);

	return;
}


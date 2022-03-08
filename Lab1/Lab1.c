/**
 -------------------------
 Student Name:Will Roberts
 Student ID:191023880
 Student email:robe3880@mylaueier.ca
 -------------------------
 **/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void t2();
void t3();
void t1();

int main() {
	int stop;
	int result;
	int a;
	int b;

	scanf("%d", &stop);
	result = 0;

	for (a = 0; a < 4; ++a) {
		printf("%d: ", a);
		for (b = 0; b < 2; ++b) {
			result += a + b;
			if (result > stop) {
				printf("_ ");
				continue;
			}
			printf("%d,", result);
		}
		printf("\n");
	}

	return 0;
}

void t1() {
	int tall;
	int vshort;
	int total;
	double avg_height;
	char symbol = 84;
	const int val = 43;

	printf("Enter number of tall trees: ");
	scanf("%d", &tall);

	printf("Enter number of short trees: ");
	scanf("%d", &vshort);

	total = tall + vshort;
	avg_height = (double) val / total;

	//printing report
	printf("Number of %c trees = %d\n", symbol, tall);
	printf("Number of %c trees = %d\n", (symbol - 1), vshort);
	printf("Average height = %.2lf", avg_height);
	return;
}

void t2() {
	unsigned int year;
	short month;
	int day;
	char university[30];

	printf("Enter year: ");
	scanf("%d", &year);
	printf("Enter month: ");
	scanf("%hu", &month);
	printf("Enter day: ");
	scanf("%d", &day);
	printf("Enter University: ");
	scanf("%s", university);
	printf("\n");
	printf("This is %s University\nToday is :%d/%hu/%d", university, day, month,
			year);

	return;
}

void t3() {
	printf("Hints for C Language:\n");
	printf("Insert \\n at end of printf for newline.\n");
	printf("Use \"double quote\" not 'single quotes' for strings.\n");
	printf("Use %%d for integer, %%f for float and %%lf for double.\n");
	return;
}

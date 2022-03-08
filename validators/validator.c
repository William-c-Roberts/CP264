//---------------------------
// Course:        CP264 Spring 2020
// File Type:     Code Validator
// Author:        Qutaiba Albluwi
// Modified Date: May 14, 2020 (2:30 pm)
//---------------------------

/**
 Tool for validating submissions and detecting errors.
 1- Place the output file, e.g. lab1_output.txt under a project
 2- Run your code, and copy your solution to a file called: my_output.txt
 3- Make sure that my_output.txt and lab1_output.txt are on the same folder
 4- Change the first line to reflect the file that you want to compare to
 5- Run this file. The output will either show that you have 100% matching
 Or will display the line number which the mismatch occurred.
 6- If you want to skip some lines from comparison, then list line numbers
 in the skip array (can skip up to 5 lines)
 You can also skip a range (inclusive both ends)
 #-------------------------
 **/

# include<stdio.h>
# include <stdlib.h>

char file1[] = "A9_output.txt"; 	//<------ edit this line
char file2[] = "my_output.txt";
int skip[5] = { -1, -1, -1, -1, -1 }; //<---- edit this with lines you want to skip
int skip_range[2] = { -1, -1 };	//<--- edit this if you want to skip a range

int is_skip(int line_num) {
	if (line_num == skip[0] || line_num == skip[1] || line_num == skip[2]
			|| line_num == skip[3] || line_num == skip[4])
		return 1;
	if (line_num >= skip_range[0] && line_num <= skip_range[1])
		return 1;
	return 0;
}

void file_match() {
	int counter = 1, mismatch = 0;
	char char1, char2;

	FILE *infile1 = fopen(file1, "r");
	FILE *infile2 = fopen(file2, "r");

	if (infile1 == NULL || infile2 == NULL) {
		printf("Error(file_match): Unable to open one of the files");
		return;
	}

	char1 = fgetc(infile1);
	while (char1 != EOF) {
		char2 = fgetc(infile2);
		if (is_skip(counter)) {
			while (char1 != '\n')
				char1 = fgetc(infile1);
			while (char2 != '\n')
				char2 = fgetc(infile2);
			counter++;
			char1 = fgetc(infile1);
			continue;
		} else if ((char2 != char1) || (char2 == EOF && char1 != EOF)) {
			mismatch = counter;
			break;
		}
		if (char1 == '\n')
			counter++;
		char1 = fgetc(infile1);
	}

	if (mismatch)
		printf("Fail: mismatch at line %d\n with char %c", mismatch, char1);
	else
		printf("Pass: 100%% match");

	fclose(infile1);
	fclose(infile2);
	return;
}

int main() {
	setbuf(stdout, NULL);
	file_match();
	return 0;
}

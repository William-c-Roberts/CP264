/* CP264 Spring 2021 Midterm */

#ifndef MIDTERM_H_
#define MIDTERM_H_

# define True 1
# define False 0
# define MAX 100

int replace_char(char* fileName, char letter1, char letter2);
void update_array(int** array, const int size, int multiplier);
char* sentence_to_words(char* sentence);
void update_pointers(float* array, const int size, float** ptr1, float** ptr2, char mode);

#endif /* MIDTERM_H_ */

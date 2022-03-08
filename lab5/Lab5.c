/*
 * ---------------------------------
 * Student Name:
 * Student ID:
 * Student Email:
 * ---------------------------------
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

char* encrypt(char *plaintext, int key) {
	int length = strlen(plaintext);

	int i = 0;
	char *new = malloc(sizeof(char) * length);
	for (i = 0; i < length; i++) {
		if (isalpha(plaintext[i]) != 0) {

			if ((int) plaintext[i] + key > 122)
				new[i] = ((int) plaintext[i] - 26 + key);
			else
				new[i] = (int) plaintext[i] + key; /* Print each character of the string. */
		} else {
			new[i] = plaintext[i];
		}
	}
	return new;
}

char* decrypt(char *ciphertext, int key) {
	int length = strlen(ciphertext);

	int i = 0;
	char *new = malloc(sizeof(char) * length);
	for (i = 0; i < length; i++) {
		if (isalpha(ciphertext[i]) != 0) {
			if ((int) ciphertext[i] >= 65 && (int) ciphertext[i] <= 90) {
				new[i] = (int) ciphertext[i] - key;
			} else if ((int) ciphertext[i] - key < 97)
				new[i] = ((int) ciphertext[i] + 26 - key);
			else
				new[i] = (int) ciphertext[i] - key; /* Print each character of the string. */
		} else {
			new[i] = ciphertext[i];
		}
	}
	return new;
}

#include "otherfunc2.h"


int Proverka(char letter)
{
	if (isalpha(letter)) {
			if (islower(letter)) {
				return 1;
			} else {
				letter = tolower(letter);
				return 1;
			}
	} else {
		return 0;
	}
}

int Povtor(char letter, int *C, int kol, char *A)
{
	int i;
	for (i = 0; i < kol; i++) {
		if ((letter == A[i]) && (C[i] == 1)) {
			C[i] = 0;
			return 1;
		}
	}
	return 0;
}

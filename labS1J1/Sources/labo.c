#include"labo.h"
#include <stdbool.h>
#include <string.h>


char* sousTexte(char* texte, int from, int to) {
	int i = 0;
	static char str[512] = {0};
	while (i + from < to) {
		str[i] = texte[from + i];
		i++;
	}
	str[i] = '\0';
	return str;
};


void set_String(char* text, String* s) {

	for (int i = 0; i <= strlen(text); i++) {
		 s->characters[i] = text[i];
	}

};


int String_is_palindrome(String* s) {

	for (int i = 0;i < sizeof(s);i++) {

		if (s->characters[i] == s->characters[sizeof(s) - i]) {
			return 1;
		}

	}
	return 0;
};


void bubbleSort(int elements[], int n) {

	bool �changer = false;

	for (int i = 0; i <= strlen(elements) - 1; i++) {
		if (elements[i] > elements[i + 1]) {
			�changer = true; 
			elements[i] = elements[i + 1];
			elements[i + 1] = elements[i];
		}

		if (i >= sizeof(elements) - 1 && �changer == true) {

			�changer = false;
			i = -1;

		}
	}

};
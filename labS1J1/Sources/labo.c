#include <stdio.h>
#include <stdbool.h>
#include "labo.h"

/*
* Faire une fonction qui retourne un sous-tableau de character a partir de celui passer(paramètre texte).
*/
char* sousTexte(char* texte, int from, int to) {

	static char sub[64] ={0};

	for (int i = 0; i < to - from; i++) {
		sub[i] = texte[from+i];
	}
	return sub;
}

/*
* Faire une fonction qui copie le contenu du tableau de character dans la propriété de data
* de la structure string.
*/
void set_String(char* text, String* s) {
	
	int i = 0;

	for (i = 0; i < sizeof(text); i++) {
		s->characters[i] = text[i];
	}
}

/*
* Faire une fonction qui vérifie si un mot est un palindrome i.e. kayak, racecar...
* Si le mot est un palindrome retourner 1 sinon 0
*/
int String_is_palindrome(String* s) {

	int i = 0;

	for (i = 0; i < s->length; i++) {

		if (s->characters[i] != s->characters[s->length-i-1]) {
			return 0;
		}
	}
	return 1;
}

/*
* Implémenter la fonction bubble sort et trier le tableau
*/
void bubbleSort(int elements[], int n) {
	int temp = 0;
	bool echanger;
	int i, j = 0;

	for (i = 0; i < n-1; i++) {
		echanger = false;
		for (j = 0; i < n - i - 1; j++) {

			if (elements[j] > elements[j+ 1]) {
				temp = elements[j];
				elements[j] = elements[j + 1];
				elements[j + 1] = temp;
				echanger = true;
			}
		}
		if (echanger == false)
			break;
		
	}
	printf(elements[i]);
}
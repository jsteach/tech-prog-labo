#include <stdio.h>
#include <stdbool.h>
#include "labo.h"

/*
* Faire une fonction qui retourne un sous-tableau de character de celui passer.
*/
char* sousTexte(char* texte, int from, int to) {
	static char subList[512];
	int i;

	for (i = from; i < to; i++) {
		subList[i - from] = texte[i];
	}
	return subList;
}


/*
* Faire une fonction qui copie le contenu du tableau de character dans la propriété de data
* de la structure string.
*/
void set_String(char* text, String* s) {
	int i;

	for (i = 0; i <= s->length; i++) {
		text[i] = s->characters[i];
	}
}

/*
* Faire une fonction qui vérifie si un mot est un palindrome i.e. kayak, racecar...
* Si le mot est un palindrome retourner 1 sinon 0
*/
int String_is_palindrome(String* s) {
	int i;
	bool palindrome = true;

	for (i = 0; i <= s->length; i++) {
		if (!(s->characters[i] == s->characters[s->length - i])) {
			palindrome = false;
		}
	}
	if (palindrome) {
		return 1;
	}
	else {
		return 0;
	}
}

/*
* Implémenter la fonction bubble sort et trier le tableau
*/
void bubbleSort(int elements[], int n) {
	int i;
	int x;
	int temp;

	for (x = 0; x < n; x++) {
		for (i = 0; i < n-1; i++) {
			if (elements[i + 1] < elements[i]) {
				temp = elements[i + 1];
				elements[i + 1] = elements[i];
				elements[i] = temp;
			}
		}
	}
}
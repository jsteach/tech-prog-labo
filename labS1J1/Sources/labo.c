#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "labo.h"


/*
* Faire une fonction qui retourne un sous-tableau de character à partir de celui passer.
*/
char* sousTexte(char* texte, int from, int to) {
	static char subchar[64];
	int n = 0;

	for (int i = from; i < to; i++) {
		subchar[n] = texte[i];
		n++;
	}
	return subchar;
}


/*
* Faire une fonction qui copie le contenu du tableau de character dans la propriété de data
* de la structure string.
*/
void set_String(char* text, String* s) {
	s->length = strlen(text);

	for (int i = 0; i < s->length; i++) {
		s->characters[i] = text[i];
	}
}

/*
* Faire une fonction qui vérifie si un mot est un palindrome i.e. kayak, racecar...
* Si le mot est un palindrome retourner 1 sinon 0
*/
int String_is_palindrome(String* s) {
	
	int _isPalindrome = 1;

	for (int i = 0; i < s->length; i++) {
		if (s->characters[i] != s->characters[s->length - i - 1]) {
			_isPalindrome = 0;
			break;
		}
	}
	return _isPalindrome;
}

/*
* Implémenter la fonction bubble sort et trier le tableau
*/
void bubbleSort(int elements[], int n) {
	
	int j;
	int _temporary;

	for (int i = 0; i < n - 1; i++) {
			
			for (j = 0; j < n - i - 1; j++) {
				if (elements[j] > elements[j + 1]) {
					_temporary = elements[j];
					elements[j] = elements[j + 1];
					elements[j + 1] = _temporary;
				}
			}
		}
	}


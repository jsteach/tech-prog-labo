#include <stdio.h> 
#include "labo.h"
#include <string.h>
#include <stdlib.h>
/*
* Faire une fonction qui retourne a sous-tableau de character de celui passer.
*/
char* sousTexte(char* texte, int from, int to) {
	static char sublist[512];
	for (int i = from; i < to; i++) {
		sublist[i - from] = texte[i];
	}
	return sublist;
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
	int palindrome = 1;
	for (int i = 0; i < s->length; i++) {
		if (s->characters[i] != s->characters[s->length - i - 1])
		{
			palindrome = 0;
			break;
		}
	}
	return palindrome;
}

/*
* Implémenter la fonction bubble sort et trier le tableau
*/
void bubbleSort(int elements[], int n) {
	int x = 0;
	int echanger = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (elements[j] > elements[j + 1]) {
				echanger = elements[j];
				elements[j] = elements[j + 1];
				elements[j + 1] = echanger;
				
			}
			//if (j >= (n - 1)) {
			//	echanger = 0;
			//	j = -1;
			//}
		}
	}
}
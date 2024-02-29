#include <stdint.h>
#include <assert.h>
#include "labo.h"

/*
* Creer la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size) {
	Stack* s = allocate(sizeof(Stack));
	s->top = -1;
	s->max_size = max_size;
	s->data = allocate(sizeof(void*) * s->max_size);
	memset(s->data, 0, sizeof(void*) * s->max_size);
	return s;
}

/*
* Ajouter l'element sur la stack. Prevener "l'overflow" de la stack.
*/
void push(Stack* s, void* newData) {
	if (s->top + 1 < s->max_size) {
		s->top += 1;
		s->data[s->top] = newData;
	}
}

/*
* Enlever l'element de la stack et retourner l'information. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* pop(Stack* s) {
	void* out = NULL;
	if (s->top > -1) {
		out = s->data[s->top];
		s->top -= 1;
	}
	return out;
} 

/*
* Retourner l'element du top sans l'enlever de la stack. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* peek(Stack* s) {
	void* out = pop(s);
	if (out != NULL && s != NULL) {
		push(s, out);
	}
	return out;
}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilise la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s) {
	void* temp[32];
	void* out = 1;
	int i = -1;

	while (out != NULL) {
		i++;
		out = pop(s);
		temp[i] = out;
	}

	for (int i = 0; i <= s->max_size - 1; ++i) {
		push(s, temp[i]);
	}

	printf("\n");

	return s;
}

/*
* Triee la stack.La personne sur le haut/top est la plus jeune. Vous ne pouvez pas modifier la propriete data directement. Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s) {
	void* tempList[32];
	void* temp;
	void* out = 1;
	int i = -1;
	while (out != NULL) {
		i++;
		out = pop(s);
		tempList[i] = out;
	}

	for (int j = 0; j < 16; ++j) {
		for (int x = 0; x < i-1; ++x) {		
			if (*(int*)tempList[x] < *(int*)tempList[x + 1]) {
				temp = tempList[x];
				tempList[x] = tempList[x + 1];
				tempList[x + 1] = temp;
			}
		}
	}

	for (int x = 0; x < i; ++x) {
		push(s, tempList[x]);
	}
}
#include <stdio.h>
#include <stdlib.h>

#include "labo.h"

/*
* Creer la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
void* allocate(size_t size);

Stack* new_stack(size_t max_size) {

	Stack* s = (Stack*)allocate(sizeof(Stack));
	s->top = -1;
	s->max_size = max_size;
	s->data = allocate(sizeof(void*) * max_size);

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
	else {
		printf("Stack Overflow");
	}

}

/*
* Enlever l'element de la stack et retourner l'information. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* pop(Stack* s) {
	
	void* out = NULL;
	if (s->top - 1 >= 0) {
		out = s->data[s->top];
		s->top -= 1;
		return out;
	}
}

/*
* Retourner l'element du top sans l'enlever de la stack. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* peek(Stack* s) {
	void* out = pop(s);

	if (out != NULL) {
		push(s, out);
	}
	return out;
}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilise la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s) {

	int MAX = s->max_size;

	int arr[MAX];

}

/*
* Triee la stack.La personne sur le haut/top est la plus jeune. Vous ne pouvez pas modifier la propriete data directement. Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s) {

}
#include <stdio.h>
#include "labo.h"


/*
* Creer la fonction d'initialization. Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size) {

	Stack* s=allocate(sizeof(Stack));
	s->max_size = max_size;
	s->top = -1;
	s->data = allocate(sizeof(void*) * s->max_size);
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
	else
	{
		printf("Stack overflow: La fonction demande pour la stack %d alors que la grandeur maximale est de %d. \n", s->top + 1, s->max_size);
		
	}

}

/*
* Enlever l'element de la stack et retourner l'information. Si jamais il n'y a pas d'element, retourner NULL.
*/
void* pop(Stack* s) {

	void* out = NULL;
	if (s->top - 1 >= -1) {

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
	if (out != NULL) {

		push(s, out);
	}
	else {

		return NULL;
	}
	return out;
}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.Vous ne devez pas utilise la variable temp qui est une autre Stack.
*/
void reverseStack(Stack* s) {


}

/*
* Triee la stack.La personne sur le haut/top est la plus jeune. Vous ne pouvez pas modifier la propriete data directement. Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s) {


}
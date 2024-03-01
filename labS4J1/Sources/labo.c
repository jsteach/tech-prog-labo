#include <stdint.h>
#include <assert.h>
#include "labo.h"



/*
* Creer la fonction d'initialization.
  Utiliser la fonction allocate au lieu de malloc.
*/
Stack* new_stack(size_t max_size) {
	Stack* s = (Stack*)allocate(sizeof(Stack));
	s->max_size = max_size;
	s->top = -1;
	s->data = allocate(sizeof(void*) * max_size);

	return s;
}

/*
* Ajouter l'element sur la stack. Prevener l'overflow de la stack.
*/
void push(Stack* s, void* newData) {
	
	if (s->top + 1 < s->max_size) {
		s->top += 1;
		s->data[s->top] = newData;
	}
}

/*
* Enlever l'element de la stack et retourner l'information.
  Si jamais il n'y a pas d'element, retourner NULL.
*/
void* pop(Stack* s) {
	void* out = NULL;

	if (s->top - 1 >= 0) {
		out = s->data[s->top];
		s->data[s->top] = NULL;
		s->top -= 1;
	}
	return out;
}

/*
* Retourner l'element du top sans l'enlever de la stack.
  Si jamais il n'y a pas d'element, retourner NULL.
*/
void* peek(Stack* s) {
	void* out = pop(s);

	if (out != NULL) {
		push(s, out);
	}
	return out;
}

/*
* Inverser l'ordre de la stack i.e. le haut va devenir le bas.
  Vous ne devez pas utilise la variable temp qui est un autre Stack.
*/
void reverseStack(Stack* s) {
	void* tempArr[1024];
	int index = 0;

	while (s->top >= 0) {
		tempArr[index++] = pop(s);
	}
	for (int i = index - 1; i >= 0; i--) {
		push(s, tempArr[i]);
	}
}

/*
* Trier la stack. La personne sur le haut/top est la plus jeune.
  Vous ne pouvez pas modifier la propriete data directement.
  Vous devez utiliser push,pop et/ou peek.
*/
void sortStack(Stack* s) {
	Stack* t = new_stack(s->max_size);
	Person* currPers = NULL;

	while (s->top >= 0) {
		currPers = (Person*)peek(s);
		pop(s);

		while (t->top >= 0 && ((Person*)peek(t))->age < currPers->age) {
			push(s, pop(t));
		}
		push(t, currPers);
	}

	while (t->top >= 0) {
		push(s, pop(t));
	}
}


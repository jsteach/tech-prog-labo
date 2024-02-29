#include <stdint.h>
#include <assert.h>
#include "labo.h"

/*
* Ajouter l'element sur la queue/file.
*/
void push(Queue* q, Node* n) {
	if (q->next == NULL) {
		q->next = q->prev = n;
	} else {
		Node* last = q->next;
		n->next = last;
		last->prev = n;
		q->next = n;
	}
}

/*
* Enlever l'element de la queue/file et retourner le noeud. Si jamais il n'y a pas de noeud, retourner NULL.
*/
Node* pop(Queue* q) {
	if (q == NULL) {
		return NULL;
	}

	Node* n = q->prev;
	if (q->prev != NULL) {
		if (q->prev == q->next) {
			q->next = q->prev = NULL;
		}
		else {
			q->prev = q->prev->prev;
		}
	}
	return n;
}



/*
* Retourner l'element de la fin de la queue/file sans l'enlever de la queue. Si jamais il n'y a pas d'element, retourner NULL.
*/
Node* peek(Queue* q) {
	return q->prev;
}

/*
* Ajouter l'element sur la queue/file comme si elle serait une priority queue. Utiliser l'age afin de "trie" a chaque push.La personne au premier pop() est la plus jeune.
* On utilise pas une fonction de tri.
*/
void pushAsPriorityQueue(Queue* q, Node* n){
	int popAmount = 0;
	if (q->prev == NULL) {
	push(q, n);
	return 0;
	}
	else {
		Node* temp = q->prev;
		while (1) {
			if (((Person*)temp->data)->age > ((Person*)n->data)->age) {
				popAmount++;
				if (temp->prev != NULL) {
					temp = temp->prev;
					if (temp->next == q->prev) {
						break;
					}
				} else {
					break;
				}
			} else {
				break;
			}
		}
		Node* templist[16];
		for (int i = 0; i < popAmount; i++) {
			templist[i] = pop(q);
		}
		push(q, n);
		for (int i = popAmount; i > 0; i--) {
			push(q, templist[i-1]);
		}
	}
}


/*
* Triee la queue. La personne au premier pop() est la plus jeune.Vous devez utiliser push,pop et/ou peek.
* Vous ne pouvez pas utiliser le meme algorithme de tri que celui utiliser lors du labo sur la stack
*/
void sortQueue(Queue* q){
	Node* list[16];
	Node* n = NULL;
	int index = 0;

	while (q->prev != NULL){ // pop la queue entière et met les données dans un tableau
		n = pop(q);
		list[index] = n;
		index++;
	}

	int listLength = index; 

	for (int i = 0; i < listLength; i++) { // insertion sort		
		int y = i;
		while (y > 0 && list[y] < list[y-1])
		{
			Node* n = list[y];
			list[y] = list[y - 1];
			list[y - 1] = n;
			--y;
		}
	}

	for (int i = 0; i < listLength; i++) { // push le tableau trié dans la queue
		push(q, list[i]);
	}	
}
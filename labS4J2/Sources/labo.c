#include <stdio.h>
#include <stdlib.h>

#include "labo.h"

/*
* Ajouter l'element sur la queue/file.
*/
void push(Queue* q, Node* n) {
	
	if (q->next == NULL) {
		q->next = q->prev = n; 
	}
	else {
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

}



/*
* Retourner l'element de la fin de la queue/file sans l'enlever de la queue. Si jamais il n'y a pas d'element, retourner NULL.
*/
Node* peek(Queue* q) {

}

/*
* Ajouter l'element sur la queue/file comme si elle serait une priority queue. Utiliser l'age afin de "trie" a chaque push.La personne au premier pop() est la plus jeune.
* On utilise pas une fonction de tri.
*/
void pushAsPriorityQueue(Queue* q, Node* n) {

}


/*
* Triee la queue. La personne au premier pop() est la plus jeune.Vous devez utiliser push,pop et/ou peek.
* Vous ne pouvez pas utiliser le meme algorithme de tri que celui utiliser lors du labo sur la stack
*/
void sortQueue(Queue* q) {

}
#include <assert.h>
#include <stdint.h>
#include "labo.h"


/*
* Creer un noeud et l'ajouter apres le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData) {
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	n->next = NULL;
	currNode->next = n;
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	n->next = NULL;
	head->next = n;
	if (head->data == NULL) {
		head->data = newData;
	}
}

/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData. Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByData(Node* head, void* rmData) {
	Node* last = NULL;
	while (head->data != rmData) {
		last = head;
		head = head->next;
	}
	memset(head, 0, sizeof(Node));
	return last;
}

/*
* Supprimer le noeud ayant le nom passer par name.Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByName(Node* head, char* name) {
	Node* last = NULL;
	while (head->data != name) {
		last = head;
		head = head->next;
	}
	memset(head, 0, sizeof(Node));
	return last;
}

/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head) {
	Node* last = NULL;
	Node* temp = NULL;
	for (int i = 0; i < 32; i++) {
		while (head != NULL) {
			last = head;
			head = head->next;
			if (last > head) {
				temp = head;
				head = last;
				last = temp;
			}
		}
	}
}
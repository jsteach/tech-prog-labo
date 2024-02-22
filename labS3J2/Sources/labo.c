#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "labo.h"

/*
* Creer un noeud et l'ajouter apres le noeud currNode. Considerer la propriete next et prev.
*/
void insert(Node* currNode, void* newData) {
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	n->next = currNode->next;
	n->prev = currNode;
	currNode->next = n;
}

/*
* Creer un noeud et l'ajouter apres le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData) {
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	n->next = head;
	if (head->prev != NULL) {
		n->prev = head->prev; // **head->prev == nullptr** ???
		head->prev = n;
		head->prev->next = n;
	}
	if (head->data == NULL) {
		head->data = newData;
	}
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	n->next = head->next;
	n->prev = head;
	head->next = n;
	if (head->data == NULL) {
		head->data = newData;
	}
}
/*
* Enlever le noeud de la liste et retourner le noeud avec aucune reference(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode) {
	if (currNode != NULL) {
		currNode->next->prev = currNode->prev; // **currnode == nullptr** ???
		currNode->prev->next = currNode->next;
		currNode->next = NULL;
		currNode->prev = NULL;
	}
	return currNode;
}

/*
* Ajouter dans le tableau le nom de chacun en ordre alphabetic. Par simplicite, considerer seulement les deux premiere lettre.
*/
void alphabetise(Node* head, char* names[]) {
	Node* tempNode = allocate(sizeof(Node));
	tempNode = head;
	char* tempChar = { 0 };
	for (int x = 0; x < 32; x++) {
		for (int i = 0; i < sizeof(names) - 1; i++) {
			if (atoi(names[i][0]) > atoi(names[i + 1][0])) {
				names[i] = tempChar;
				names[i] = names[i + 1];
				names[i + 1] = tempChar;
			}
			else if (atoi(names[i][0]) == atoi(names[i + 1][0])) {
				if (atoi(names[i][1]) > atoi(names[i + 1][1])) {
					names[i] = tempChar;
					names[i] = names[i + 1];
					names[i + 1] = tempChar;
				}
			}
		}
	}

	for (int i = 0; i < sizeof(names); i++) {
		tempNode->data = names[i];
		tempNode = tempNode->next;
	}
}
#include <stdio.h>
#include "labo.h"


/*
* Creer un noeud et l'ajouter apres le noeud currNode. Considerer la propriete next et prev.
*/
void insert(Node* currNode, void* newData) {

	Node* n = { 0 };
	n->data = newData;
	n->prev = NULL;
	n->next = NULL;
	if (currNode->next != NULL) {

		n->next = currNode->next;
		currNode->next->prev = n;

	}
	currNode->next = n;
	n->prev = currNode;
}

/*
* Creer un noeud et l'ajouter apres le noeud de fin. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData) {

	if (head->data == NULL) {

		head->data = newData;
	}
	else
	{

		insert(head, newData);
	}


}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {


}

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune reference(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode) {


}

/*
* Ajouter dans le tableau le nom de chacun en ordre alphabetic. Par simplicite, considerer seulement les deux premiere lettre.
*/
void alphabetise(Node* head, char* names[]) {


}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "labo.h"

/*
* Creer un noeud et l'ajouter apres le noeud currNode. Considerer la propriete next et prev.
*/
void insert(Node* currNode, void* newData) {
	Node* n = allocate(sizeof(Node));
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
* Creer un noeud et l'ajouter apres le noeud de fin. 
  Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertTail(Node* head, void* newData) {
	Node* currNode = head->prev;

	if (head != NULL) {
		insert(currNode, newData);
	}
	else {
		head = newData;
	}
}

/*
* Creer un noeud et l'ajouter apres le noeud head. 
  Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {
	Node* n = allocate(sizeof(Node));
	n->data = newData;

	if (head != NULL) {
		head->next = n;
	}
	else {
		head = n;
	}
}

/*
* Enlever le noeud de la liste et retourner le noeud avec aucune reference(i.e. next et prev == NULL)
*/
Node* removeNode(Node* currNode) {
	
	//currNode = memset(currNode,0,sizeof(Node))
	//Attacher currNode.prev.next avec currNode.next.prev (??)
	//currNode next et prev = NULL

}

/*
* Ajouter dans le tableau le nom de chacun en ordre alphabetic. 
  Par simplicite, considerer seulement les deux premiere lettre.
*/
void alphabetise(Node* head, char* names[]) {

	//Person* p = (Person*)head->data;

}
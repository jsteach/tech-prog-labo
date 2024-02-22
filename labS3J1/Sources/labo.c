#include <stdio.h>
#include <stdlib.h>
#include "labo.h"



/*
* Creer un noeud et l'ajouter apres le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData) {

	Node* n = (Node*)allocate(sizeof(Node));
	n->data = newData;
	n->next = NULL;
	if (currNode->next != NULL) {
		n->next = currNode->next;
	}
	
	currNode->next = n;
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {

	if (head->data == NULL) {

		head->data = newData;
	}
	else {

		insert(head, newData);
	}
}


/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData. Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByData(Node* head, void* rmData) {

	Node* temp = head;
	Node* last = NULL;
	While(temp != NULL && (int)temp->data != rmData); {
		
		last = temp;
		temp = temp->next;
	}
	if (temp == NULL) {

		printf("Error: Couldn't find the value");
		return;
	}
	last->next = temp->next;
}

/*
* Supprimer le noeud ayant le nom passer par name.Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/
Node* removeByName(Node* head, char* name) {


}

/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head) {


}
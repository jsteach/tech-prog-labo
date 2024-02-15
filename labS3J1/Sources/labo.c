#include <assert.h>
#include <stdint.h>
#include "labo.h"

/*
* Creer un noeud et l'ajouter apres le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData) {
	Node* n = (Node*)allocate(sizeof(Node));
	n->data = newData;
	n->next = NULL;

	if (currNode->next != NULL) {
		Node* temp = currNode->next;
		currNode->next = n;
		n->next = temp;
	}
	else {
		currNode->next = n;
	}
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/

void insertHead(Node * head, void* newData){
	
	if (head != NULL) {
		insert(head, newData);
	}
	else {
		head->data = newData;
	}
}

/*
* Supprimer le noeud ayant la valeur de pointeur de data i.e. node->data == rmData. Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/

Node* removeByData(Node* head, void* rmData){
	Node* temp = head;
	Node* last = NULL;

	while (temp != NULL && temp->data != rmData) {
		last = temp;
		temp = temp->next;
	}
	if (temp == NULL) {
		return NULL;
	}
	if (last == NULL) {
		head = temp->next;
	}
	else {
		last->next = temp->next; 
	}
	return head;
}

/*
* Supprimer le noeud ayant le nom passer par name. 
* Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/

Node* removeByName(Node* head, char* name){
	

}

/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/

//void sort(Node* head){}
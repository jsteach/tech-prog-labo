
#include <stdio.h>
#include <stdlib.h>

#include "labo.h"


void* allocate(size_t size);


/*
* Creer un noeud et l'ajouter apres le noeud currNode. Utiliser la fonction allocate pour allouer de la memoire.
*/
void insert(Node* currNode, void* newData) {
	Node* ptr = NULL;	
	
	ptr = (Node*)allocate(sizeof(Node));
	

	ptr->data = newData;
	ptr->next = NULL;
	
	

	if (currNode->next != NULL) 
	{
		ptr->next = currNode->next;
	}
	currNode->next = ptr;
}

/*
* Creer un noeud et l'ajouter apres le noeud head. Si le noeud head est vide(data) lui donner la nouvelle valeur passer.
*/
void insertHead(Node* head, void* newData) {
	
	if (head->data != NULL) {
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
Node* removeByData(Node* head, void* rmData) {

	Node* temp = head;
	
	while(temp != NULL)
	{
		temp = temp->next;
	}

	if (head->data == rmData) {
		memset(temp, 0, sizeof(Node));
	}
}

/*
* Supprimer le noeud ayant le nom passer par name.Par simplicite, pour supprimer faite un memset(node,0,sizeof(Node));
* Retourner le noeud juste avant celui supprimer
*/

Node* removeByName(Node* head, char* name) {

	if (head->data == name) {
		
		memset(head, 0, sizeof(Node));

	}

}

/*
* Trier par l'age. Utiliser l'algorithme que vous connaissez le mieux.
*/
void sort(Node* head) {

	Node* temp = NULL;
	int t = 0;

	while(temp != NULL)
	{
		temp = temp->next;
		
		if (temp > temp->next) {
			t = temp;
			temp = temp->next;
			temp->next = t;
		}
	}
}
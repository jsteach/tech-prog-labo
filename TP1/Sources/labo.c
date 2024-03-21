#include <stdint.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "labo.h"

void insert(Node* currNode, void* newData) {
	Node* n = allocate(sizeof(Node));
	n->data = newData;
	n->next = currNode->next;
	n->prev = currNode;
	currNode->next = n;
}

void insertTail(Node* head, void* newData) {
	Node* n = allocate(sizeof(Node));
	Node* temp = head;
	n->data = newData;
	n->next = NULL;

	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
	n->prev = temp;
}

void removeNode(Node* head, int nodeIndex) {
	Node* n = head;

	for (int i = 0; i <= nodeIndex; i++) {
		if (n->next != NULL) {
			n = n->next;
		}
		else {
			return;
		}
	}

	if (n->prev != NULL) {
		n->prev->next = n->next;
	}
	if (n->next != NULL) {
		n->next->prev = n->prev;
	}
}

void sortList(Node* head, int maxNodes) {
	Node* temp = head->next;
	void* tempData = NULL;
	bool sorted = false;

	while (!sorted) {
		for (int i = 0; i <= maxNodes; i++) {
			sorted = true;
			while (temp->next != NULL)
			{
				if (((Item*)temp->data)->value > ((Item*)temp->next->data)->value) {
					tempData = temp->data;
					temp->data = temp->next->data;
					temp->next->data = tempData;
					sorted = false;
				}
				temp = temp->next;
			}
			temp = head->next;
		}
	}
}

Node* searchNodeIndex(Node* head, int nodeIndex) {
	Node* temp = head;
	int i = 0;

	for (i; i <= nodeIndex; i++) {
		if (temp->next != NULL) {
			temp = temp->next;
		}
		else {
			printf("Il n'y a aucun item a cet index...\n");
			return NULL;
		}
	}
	if (temp->data != NULL) {
		printf("\nNode %d : %s, %d\n", i - 1, ((Item*)temp->data)->name, ((Item*)temp->data)->value);
		return temp;
	}
}

void searchNodeName(Node* head, char name[64]) {
	Node* temp = head;
	int nodeIndex = 0;

	while (temp->next != NULL)
	{
		temp = temp->next;
		nodeIndex++;
		if (strcmp(((Item*)temp->data)->name, name) == 0) {
			printf("\nNode %d : %s, %d\n", nodeIndex - 1, ((Item*)temp->data)->name, ((Item*)temp->data)->value);
			return;
		}
	}
	printf("\nIl n'y a aucun item avec ce nom...\nSoyez sure de ne pas oublier pas les majuscules.\n");
}

void printList(Node* head) {
	Node* temp = head;
	int nodeIndex = 0;

	while (temp->next != NULL)
	{
		temp = temp->next;
		printf("Node %d : %s, %d\n", nodeIndex, ((Item*)temp->data)->name, ((Item*)temp->data)->value);
		nodeIndex++;
	}
}
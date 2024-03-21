#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <Windows.h>

#include "labo.h"

#define HEAP_SIZE 2048 * 2048 * 4
static uint8_t* heap = NULL;
static size_t heap_top = 0;
void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}

int Randomizer(int lower, int upper) {
	int num = (rand() % (upper - lower + 1)) + lower;
	return num;
}

int main() {
	heap = (uint8_t*)malloc(HEAP_SIZE);
	assert(heap != NULL);

	srand(time(0));

	Node inventoryHead = { NULL };
	Node possibleItemsHead = { NULL };


	FILE* data;
	data = fopen("data.csv", "r");

	if (data == NULL) {
		printf("! Data file not found !\nMake sure the data file is in ./Vince-tech-prog-labo/Deployment\n");
		return 1;
	}

	// v READ THE DATA FILE v //
	char buffer[256];
	char* temp;
	int numItems = 0;
	int numItemsInventory = 0;

	while (true) {
		fgets(buffer, sizeof(buffer), data);
		printf("%s\n", buffer);

		temp = strtok(buffer, ", ");						// First token ("Name")

		temp = strtok(NULL, ", ");							// Second token (<Name Of Item>)
		if (temp == NULL) {
			break;											// If the line is empty, stop the loop
		}

		Item* readItem = allocate(sizeof(Item));			// Create the item
		strcpy(readItem->name, temp);						// Put in the items name

		temp = strtok(NULL, ", ");							// Third token ("Value")

		temp = strtok(NULL, ", ");							// Fourth token (<Value Of Item>)
		readItem->value = atoi(temp);						// Put in the items value by converting the string "temp" to integer

		insertTail(&possibleItemsHead, readItem);			// Insert the item inside the possibleItems list
		numItems++;											// Count up how many items are in the data file
	}
	// ^ READ THE DATA FILE ^ //

	fclose(data);

	bool end = false;
	while (!end) {
		int input;
		char textInput[64];
		system("cls");
		printf("Bienvenue au systeme d'inventaire.\nVoulez-vous faire des modifications?\n( 0 ) Quitter\n( 1 ) Inventaire\n( 2 ) Liste d'items\n");
		scanf("%d", &input);
		system("cls");
		if (input == 0) {
			end = true;
		}
		else if (input == 1) {
			/*
			inventaire
			*/
			printf("Que voulez-vous faire avec l'invetaire?\n( 0 ) Retourner au menu\n( 1 ) Ajouter un item dans l'inventaire\n( 2 ) Enlever un item de l'inventaire\n( 3 ) Ajouter des items aleatoires dans l'inventaire\n( 4 ) Voir les items dans l'inventaire\n( 5 ) Trier l'inventaire\n");
			scanf("%d", &input);
			system("cls");
			switch (input)
			{



			case 1:
				printf("Entrez l'index de l'item que vous voulez ajouter dans l'inventaire:\n\n");
				printList(&possibleItemsHead);
				scanf("%d", &input);
				if (input > numItems - 1) {
					printf("\nIl n'y a aucun item a cet index...\n");
					printf("\n( 0 ) Retourner au menu\n");
					scanf("%d", &input);
					break;
				}
				Node* itemToAdd = searchNodeIndex(&possibleItemsHead, input);
				insertTail(&inventoryHead, itemToAdd->data);
				numItemsInventory++;
				break;



			case 2:
				printf("Items dans la liste:\n\n");
				printList(&inventoryHead);
				printf("\nEntrez le nom de l'item que vous voulez enlever:\n");
				scanf("%s", &textInput);
				Node* temp = &inventoryHead;
				int nodeIndex = 0;
				while (temp->next != NULL)
				{
					temp = temp->next;
					if (strcmp(((Item*)temp->data)->name, textInput) == 0) {
						removeNode(&inventoryHead, nodeIndex);
						break;
					}
					nodeIndex++;
				}
				printf("\nIl n'y a aucun item avec ce nom...\nSoyez sure de ne pas oublier pas les majuscules.\n");
				break;



			case 3:
				printf("Entrez le nombre d'items aleatoires que vous voulez ajouter dans l'inventaire:\n\n");
				scanf("%d", &input);
				if (input >= 0) {
					for (int i = 0; i < input; i++) {
						int rng = Randomizer(0, numItems - 1);
						Node* itemToAdd = searchNodeIndex(&possibleItemsHead, rng);
						insertTail(&inventoryHead, itemToAdd->data);
						numItemsInventory++;
					}
				}
				break;



			case 4:
				printList(&inventoryHead);
				printf("\n( 0 ) Retourner au menu\n");
				scanf("%d", &input);
				break;



			case 5:
				sortList(&inventoryHead, numItems);
				break;



			default:
				break;
			}
		}
		else if (input == 2) {
			/*
			liste d'items
			*/
			printf("Que voulez-vous faire avec la liste d'items?\n( 0 ) Retourner au menu\n( 1 ) Ajouter un item dans la liste d'items\n( 2 ) Enlever un item de la liste d'items\n( 3 ) Trier la liste d'items\n( 4 ) Trouver un item relatif a sa position\n( 5 ) Trouver un item relatif à son nom\n( 6 ) Voir le nombre d'items dans la liste\n");
			scanf("%d", &input);
			system("cls");
			switch (input)
			{



			case 1:
				printf("Entrez le nom de l'item que vous creez: ( ! aucun espaces ! )\n");
				scanf("%s", &textInput);
				printf("\nEntrez la valeur de vente de l'item que vous creez:\n");
				scanf("%d", &input);
				numItems++;
				Item* newItem = allocate(sizeof(Item));
				strcpy(newItem->name, textInput); newItem->value = input;
				insertTail(&possibleItemsHead, newItem);
				break;



			case 2:
				printf("Items dans la liste:\n\n");
				printList(&possibleItemsHead);
				printf("\nEntrez l'index (chiffre du Node) de l'item que vous voulez enlever:\n");
				scanf("%d", &input);
				if (input <= numItems - 1) {
					removeNode(&possibleItemsHead, input);
					numItems--;
				}
				break;



			case 3:
				sortList(&possibleItemsHead, numItems);
				break;



			case 4:
				printf("Entrez la position de l'item que vous voulez trouver:\n(Max index : %d)\n", numItems - 1);
				scanf("%d", &input);
				searchNodeIndex(&possibleItemsHead, input);
				printf("\n( 0 ) Retourner au menu\n");
				scanf("%d", &input);
				break;



			case 5:
				printf("Entrez le nom de l'item que vous voulez trouver: ( ! aucun espaces ! )\n");
				scanf("%s", &textInput);
				searchNodeName(&possibleItemsHead, textInput);
				printf("\n( 0 ) Retourner au menu\n");
				scanf("%d", &input);
				break;



			case 6:
				printList(&possibleItemsHead);
				printf("\nNombre d'items : %d\n", numItems);
				printf("\n( 0 ) Retourner au menu\n");
				scanf("%d", &input);
				break;



			default:
				break;
			}
		}
	}
	printf("Goodbye\n");
}
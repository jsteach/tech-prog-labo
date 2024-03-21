#include <stdint.h>
#include <assert.h>



void* allocate(size_t size);

typedef struct Node Node;

struct Node {
	void* data;
	Node* prev;
	Node* next;
};

typedef struct item_t {
	char name[64];
	int value;
} Item;


void insert(Node* currNode, void* newData);

void insertTail(Node* head, void* newData);

void removeNode(Node* head, int nodeIndex);

void sortList(Node* head, int maxNodes);

Node* searchNodeIndex(Node* head, int nodeIndex);

void searchNodeName(Node* head, char name[64]);

void printList(Node* head);
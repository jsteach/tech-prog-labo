#include <stdio.h>
#include "labo.h"


void insertionSort(int elements[], int n) {

	int i, y;
	int temp;

	for (int i = 0; i < n; i++) {
		y = i;
		while (y > 0 && elements[y] < elements[y - 1]) {
			temp = elements[y];
			elements[y] = elements[y - 1];
			elements[y - 1] = temp;
			--y;
		}
	}
}

void quickSort(int* elements, int left, int right) {
	
	int pivot = left + right / 2;
	int temp = 0;
	int L = left;
	int R = right;

	
	if (left >= right) {
		while (elements[left] < pivot) {
			left++;
		}
		while (elements[right > pivot]) {
			right--;
		}
		if (left <= right) {
			temp = elements[left];
			elements[left] = elements[right];
			elements[right] = temp;
			left++;
			right--;
		}
	}
	int index = left;
	quickSort(elements, L, index - 1);
	quickSort(elements, index, R);
}

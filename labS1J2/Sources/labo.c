#include <stdio.h>
#include "labo.h"


void insertionSort(int elements[], int n) {
	int x;
	int temp;
	for (int i = 1; i < n; i++) {
		x = i;
		while (x > 0 && elements[x] < elements[x - 1]) {
			temp = elements[x];
			elements[x] = elements[x - 1];
			elements[x - 1] = temp;
			--x;
		}
	}
}


void quickSort(int* elements, int left, int right) {
	
	if (left >= right) {
		return;
	}

	int L = left;
	int R = right;
	int pivot = elements[((left + right) / 2)];
	

	while (left <= right) {

		while (elements[left] < pivot) {
			left++;
		}

		while (elements[right] > pivot) {
			right--;
		}

		if (left <= right) {

			int temp;
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
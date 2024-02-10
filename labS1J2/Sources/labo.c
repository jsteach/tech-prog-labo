#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "labo.h"

void insertionSort(int elements[], int n) {
	int temp;
	for (int i = 1; i < n; i++) {
		int y = i;
		while (y > 0 && elements[y] < elements[y - 1]) {
			temp = elements[y];
			elements[y] = elements[y - 1];
			elements[y - 1] = temp;
			--y;
		}

	}
}

void quickSort(int* elements, int left, int right) {
	int pivot = elements[(left + right) / 2];
	int temp;
	while (left <= right) {
		while (elements[left] < pivot) { left++; }
		while (elements[right] > pivot) { right--; }
		if (left <= right) {
			temp = elements[left];
			elements[left] = elements[right];
			elements[right] = temp;
			left++; right--;
		}

	}
	int L;
	int R;
	int i;
	if (left >= right) { return; }
	L = left;
	R = right;
	i = left;
	quickSort(elements, L, i - 1);
	quickSort(elements, i, R);
	
	
}
	
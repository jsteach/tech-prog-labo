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


	if (left < right) {

		int pivot = elements[(left + right) / 2];
		int temp = 0;
		int L = left;
		int R = right;

		while (L <= R) {

			while (elements[L] < pivot) {
				L++;
			}
			while (elements[R] > pivot) {
				R--;
			}

			if (L <= R) {

				temp = elements[L];
				elements[L] = elements[R];
				elements[R] = temp;

				L++;
				R--;
			}
		}

		quickSort(elements, left, R);
		quickSort(elements, L, right);
	}
}
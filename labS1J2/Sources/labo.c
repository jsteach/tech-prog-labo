#include <stdio.h>
#include "labo.h"

void insertionSort(int elements[], int n) {
	int j;
	int _temporary;

	for (int i = 0; i < n; i++) {
		j = i;
		while (j > 0 && elements[j] < elements[j - 1]) {
			_temporary = elements[j];
			elements[j] = elements[j - 1];
			elements[j - 1] = _temporary;
			j--;
		}
	}
}

void quickSort(int* elements, int left, int right) {

	if (left < right) {

		int _pivot = elements[(left + right) / 2];
		int L = left;
		int R = right;
		int _temporary;

		while (L <= R) {
			
			while (elements[L] < _pivot) {
				L++;
			}
			while (elements[R] > _pivot) {
				R--;
			}
			if (L <= R) {
				_temporary = elements[L];
				elements[L] = elements[R];
				elements[R] = _temporary;

				L++;
				R--;
			}
		}
		quickSort(elements, left, R);
		quickSort(elements, L, right);
	}
}
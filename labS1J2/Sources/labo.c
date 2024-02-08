#include <stdio.h>




void insertionSort(int elements[], int n) {

	int temp = 0;
	int y;
	for (int i = 0; i < 256; i++) {

		if (elements[i] == NULL) {

			n = i;
			break;
		}
	}


	for (int i = 1; i < n; i++) {

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

	if (left >= right) {

		return;
	}

	int L = left;
	int R = right;
	int pivot = elements[(left + right) / 2];

	while (left <= right) {

		while (elements[left] < pivot) {

			left++;
		}
		while (elements[right] > pivot) {

			right--;
		}

		if (left <= right) {

			int temp = elements[left];
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
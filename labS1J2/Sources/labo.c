#include <stdio.h>




void insertionSort(int elements[], int n) {

	int count = 0;
	for (int i = 0; i < 256; i++) {

		if (elements[i] == NULL) {

			count = i;
			break;
		}
	}


	for (int i = 1; i < count - 1; i++) {

		while (i > 0 && elements[i] < elements[i - 1]) {

			n = elements[i];
			elements[i] = elements[i - 1];
			elements[i - 1] = n;
			--i;
		}
	}

	

}




void quickSort(int* elements, int left, int right) {

	//Check avec le prof (Image, Ce qui est note ou vrai code, visualisation)

}
#include "Algo.h"
#include "pch.h"

void SelectionSort(int arr[], int size) {
	long i, j, k;
	int tmp;

	for (i = 0; i < size; i++) {
		k = i;
		tmp = arr[i];

		for (j = i + 1; j < size; j++) {
			if (arr[j] < tmp) {
				k = j; 
				tmp = arr[j];
			}

			arr[k] = arr[i];
			arr[i] = tmp;
		}
	}
}

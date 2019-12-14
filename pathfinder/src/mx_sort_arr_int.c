#include "../inc/pathfinder.h"

void mx_sort_arr_int(int *arr, int size) {
	int swap = 0;

	for (int j = 0; j < size - 1; j++) {
		for (int i = 0; i < size - 1; i++) {
			if (arr[i] == -1 || arr[i + 1] == -1) {
				i++;
			}
			if (arr[i] > arr[i + 1]) {
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
			}
		}
	}
}


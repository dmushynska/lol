#include "../inc/pathfinder.h"

static int **create(int i) {
	int **n = (int **)malloc(sizeof(int *) * (i + 1));

	for(int j = 0; j < i + 1; j++) {
		n[j] = (int *)malloc(sizeof(int) * (i));
	}
	for (int h = 0; h < i + 1; h++) {
		for (int j = 0; j < i; j++) {
			if (h > 2)
				n[h][j] = -1;
			else 
				n[h][j] = 2147483647;
		}
	}
	return n;
}

static int func(int **n, int j) {
	int min = 2147483647;
	int check;

	for (int i = 0; i < j; i++) {
		if (n[1][i] != 1) {
			if (n[0][i] < min) {
				min = n[0][i];
				check = i;
			}
		}
	}
	n[1][check] = 1;
	return check;
}

static int **matrix(int **n, int i, int **new, int l) {
    int check = l;
    int v;

	for (int j = 0; j < i; j++) {
		for (int s = 0; s < i; s++) {
			if (n[0][s] == new[check][s] + n[0][check] && new[check][s] != -1)
			{
				v = 0;
				while (n[++v][s] != -1) {}
				n[v][s] = check;
			}
			if (n[0][s] > new[check][s] + n[0][check] && new[check][s] != -1)
			{
				n[0][s] = new[check][s] + n[0][check];
				n[2][s] = check;
			}
		}
		check = func(n, i);
	}
	return n;
}

int ***mx_creat_second_arr(int i, int **new) {
	int **n;
	int ***ser;

	ser = malloc(sizeof(int **) * (i));
	for (int k = 0; k < i; k++) {
		n = create(i);
		n[0][k] = 0;
		n[1][k] = 1;
		n[2][k] = k;
		ser[k] = matrix(n, i, new, k);
	}
	return ser;
}

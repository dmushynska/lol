#include "../inc/pathfinder.h"

int mx_search_j(int **ser, int k) {
	int j = 0;

	for (int i = 0; i < k; i++) {
		if (ser[0][i] == 0) {
			j = i;
			break;
		}
	}
	return j;
}

char *mx_rewrite_str(char *n) {
	int j = mx_strlen(n);

	for (int i = 0; i < j; i++) {
		if (n[i] == ',')
			n[i] = '-';
	}
	return n;
}

void mx_create_arr(t_hehx *heh) {
	heh->new_arr = (char **)(malloc)(sizeof(char *) * (heh->k + 1));
	heh->lol = 0;
	for(int i = 0; i < heh->k + 1; i++)
		heh->new_arr[i] = NULL;
}

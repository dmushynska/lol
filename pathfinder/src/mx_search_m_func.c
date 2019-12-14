#include "../inc/pathfinder.h"

int *mx_search_m_func(t_hehx *heh, int **ser) {
	int *search_m = (int *)(malloc)(sizeof(int) * (heh->k - 2));

	for (int l = 0; l < heh->k - 2; l++)
		search_m[l] = ser[l + 2][heh->i];
	mx_sort_arr_int(search_m, heh->k - 2);
	return search_m;
}


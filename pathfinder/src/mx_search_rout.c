#include "../inc/pathfinder.h"

// static void save_result(int *str_result, t_hehx *heh) {
// 	heh->str_result = (int *)(malloc)(sizeof(int) * (heh->k));

// 	for (int n = 0; n < heh->k; n++)
// 		heh->str_result[n] = -1;
// 	for (int i = 0; i < heh->k; i++)
// 		heh->str_result[i] = str_result[i];
// }

static int index_return(int *str_result, int new, t_hehx *heh, int **ser) {
	int index = 0;

	for (int j = 0; j < heh->k; j++)
		str_result[j] = -1;
	new = new - ser[0][heh->h];
	str_result[index++] = new;
	mx_create_arr(heh);
	return index;
}

// static void auditor(int **ser, t_hehx *heh, int* str_result, int h) {
// 	while (ser[heh->new_m][h] != -1 && ser[heh->new_m][h] != heh->j) {
// 		save_result(str_result, heh);
// 		mx_search_rout_2(ser, heh->new_m++, heh, h);
// 	}
// 	while (ser[heh->new_m][h] >= 0) {
// 		save_result(str_result, heh);
// 		mx_search_rout_2(ser, heh->new_m++, heh, h);
// 	}
// }

static void search_distance(int **ser, t_hehx *heh, int j) {
	int h = heh->h;
	int new = ser[0][heh->i];
	int *str_result = (int *)(malloc)(sizeof(int) * (heh->k));
	int index = index_return(str_result, new, heh, ser);

	heh->new_arr[heh->lol++] = mx_strdup(heh->arr[h]);
	// auditor(ser, heh, str_result, h);
	while (ser[2][h] != j) {
			// auditor(ser, heh, str_result, h);
		new = ser[0][h];
		h = ser[2][h];
		heh->new_arr[heh->lol++] = mx_strdup(heh->arr[h]);
		new = new - ser[0][h];
		str_result[index++] = new;
	}
	// auditor(ser, heh, str_result, h);
	if (ser[0][h] != 0)
		str_result[index++] = ser[0][h];
	mx_print_result(heh->k, str_result, ser[0][heh->i], heh);
	free(str_result);
}

void mx_search_rout(int ***ser, t_hehx *heh, int j, int i) {
	int *search_m = NULL;
	int m = 2;
	int p = 0;

	heh->i = i;
	heh->p = 2;
	heh->y = 0;
	heh->new_arr_2 = NULL;
	search_m = mx_search_m_func(heh, ser[j]);
	while (search_m[p] != -1) {
		heh->new_m = 3;
		heh->h = search_m[p];
		search_distance(ser[j], heh, j);
		if (search_m[p] == search_m[p + 1])
			break;
		m++;
		p++;
	}
	free(search_m);
}

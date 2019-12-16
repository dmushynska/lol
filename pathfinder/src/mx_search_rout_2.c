#include "../inc/pathfinder.h"

static void new_arr_2(t_hehx *heh) {
	int l = heh->k;

	if (heh->new_arr == NULL)
		return;
	while (heh->new_arr[--l] == NULL) {}
	for (int kek = heh->kek + 1; kek < heh->k; kek++, l--) {
		heh->new_arr_2[kek] = mx_strdup(heh->new_arr[l]);
		if (l == 0)
			break;
	}
}

static void create_new_arr_2(t_hehx *heh, int h, int *str_result) {
		heh->new_arr_2 = (char **)(malloc)(sizeof(char *) * (heh->k + 1));
	for (int g = 0; g < heh->k + 1; g++)
		heh->new_arr_2[g] = NULL;
	heh->new_arr_2[heh->kek++] = mx_strdup(heh->arr[h]);
	for (int n = 0; n < heh->k; n++)
		str_result[n] = -1;
}

static int *search_distance_th(int **ser, int i, t_hehx *heh, int j) {
	int index = 0;
	int new = ser[0][i];
	int h = i;
	int *str_result = (int *)(malloc)(sizeof(int) * (heh->k));

	create_new_arr_2(heh, h, str_result);
	if (ser[0][h] != i)
		str_result[index++] = new;
	while (h != j) {
		new = ser[0][h];
		h = ser[2][h];
		new = new - ser[0][h];
		str_result[index++] = new;
	}
	if (ser[0][h] != 0)
		str_result[index++] = ser[0][h];
	return str_result;
}

static void int_dub(int *str_new_result, int next, t_hehx *heh, int *int_str) {
	int lol = 0;
	int kek = 0;

	for (int n = 0; n < heh->k * 2; n++)
		int_str[n] = -1;
	for (int i = 0; i < heh->k; i++, lol++) {
		if (heh->str_result[lol] == -1)
			break;
		int_str[lol] = heh->str_result[lol];
	}
	int_str[lol++] = next;
	for (heh->y = lol; heh->y < heh->k + lol 
		&& str_new_result[kek] > 0; heh->y++, kek++) {
		int_str[lol] = str_new_result[kek];
	}
	free(str_new_result);
	free(heh->str_result);
}

void mx_search_rout_2(int **ser, int m, t_hehx *heh, int h) {
	int j = mx_search_j(ser, heh->k);
	int *str_new_result = search_distance_th(ser, ser[m][h], heh, j);
	int new;
	int *int_str = (int *)(malloc)(sizeof(int) * (2 * heh->k));

	heh->kek = 0;
	heh->y = 0;
	new = ser[0][h] - ser[0][ser[m][h]];
	int_dub(str_new_result, new, heh, int_str);
	new_arr_2(heh);
	mx_print_result(heh->k, int_str, ser[0][heh->i], heh);
	free(heh->new_arr_2);
	free(int_str);
}



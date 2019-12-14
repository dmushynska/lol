#include "../inc/pathfinder.h"

static void print_arr(t_hehx *heh) {
	int i = heh->k;

	mx_printstr(heh->arr[heh->j]);
	mx_printstr(" -> ");
	mx_printstr(heh->arr[heh->i]);
	mx_printstr("\nRout: ");
	mx_printstr(heh->arr[heh->j]);
	mx_printstr(" -> ");
	while (heh->new_arr[--i] == NULL) {}
	for (int j = i; j >= 0; j--) {
		mx_printstr(heh->new_arr[j]);
			mx_printstr(" -> ");
	}
	mx_printstr(heh->arr[heh->i]);
	mx_printchar(10);
	mx_del_strarr(&heh->new_arr);
}

static void print_arr_2(t_hehx *heh) {
	mx_printstr(heh->arr[heh->j]);
	mx_printstr(" -> ");
	mx_printstr(heh->arr[heh->i]);
	mx_printstr("\nRout: ");
	mx_printstr(heh->arr[heh->j]);
	mx_printstr(" -> ");
	for (int i = 0; heh->new_arr_2[i] != NULL && i < heh->k - 1; i++) {
		mx_printstr(heh->new_arr_2[i]);
			mx_printstr(" -> ");
	}
	mx_printstr(heh->arr[heh->i]);
	mx_printchar(10);
	mx_del_strarr(&heh->new_arr_2);
}

void mx_print_result(int k, int *str_result, int res, t_hehx *heh) {
	mx_printstr("========================================\n");
	mx_printstr("Path: ");
	if (heh->new_arr_2 != NULL)
		print_arr_2(heh);
	else
		print_arr(heh);
	mx_printstr("Distance: ");
	for (int j = k - 1; j >= 0; j--) {
		if (str_result[j] > 0) {
			mx_printint(str_result[j]);
			if (j != 0)
				mx_printstr(" + ");
		}
	}
	mx_printstr(" = ");
	mx_printint(res);
	mx_printchar(10);
	mx_printstr("========================================\n");
}

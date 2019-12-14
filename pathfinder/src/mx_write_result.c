#include "../inc/pathfinder.h"

static void print_first_line(int ***ser,char **arr, int j, int i) {
	mx_printstr("========================================\n");
	mx_printstr("Path: ");
	mx_printstr(arr[j]);
	mx_printstr(" -> ");
	mx_printstr(arr[i]);
	mx_printchar('\n');
	mx_printstr("Rout: ");
	mx_printstr(arr[j]);
	mx_printstr(" -> ");
	mx_printstr(arr[i]);
	mx_printchar('\n');
	mx_printstr("Distance: ");
	mx_printint(ser[j][0][i]);
	mx_printchar('\n');
	mx_printstr("========================================\n");
}

static void save_arr(char **arr, t_hehx *heh) {
	heh->arr = (char **)(malloc)(sizeof(char *) * (heh->k + 1));

	for(int i = 0; i < heh->k + 1; i++)
		heh->arr[i] = NULL;
	for (int i = 0; i < heh->k; i++)
		heh->arr[i] = mx_strdup(arr[i]);
}

void mx_write_result(int ***ser, char **arr, int k) {
	int p = 2;
	t_hehx *heh = (t_hehx *)malloc(sizeof(t_hehx));

	heh->k = k;
	save_arr(arr, heh);
	for (int j = 0; j < k; j++) {
		for (int i = j + 1; i < k; i++) {
			if (ser[j][2][i] == j)
				print_first_line(ser, arr, j, i);
			if (ser[j][p][i] != j && ser[j][p + 1][i] != j) {
				heh->i = i;
				heh->j = j;
				mx_search_rout(ser, heh, j, i);
				p++;
			}
			p = 2;
		}
	}
	mx_del_strarr(&heh->arr);
	free(heh);
}

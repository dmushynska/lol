#include "../inc/pathfinder.h"

static void check_G(char ***s1, char **n, int i) {
	*s1 = mx_strsplit(mx_rewrite_str(n[i]), '-');
	if (mx_strcmp((*s1)[0], (*s1)[1]) == 0) {
			mx_printerr("error: line ");
			mx_printinterr(i + 1);
			mx_printerr(" is not valid \n");
		exit(0);
	}
}

static bool check(char **arr, char *s, int j) {
	int i = 0;

	for (i = 0; i < j; i++) {
		if (mx_strcmp(arr[i], s) == 0)
			return true;
	}
	return false;
}

static void check_first_line(char **arr, int j) {
	if (j == 0)
		exit(0);
	if ((arr[j] != NULL) || (arr[j - 1] == NULL)) {
		if (j == 0)
			mx_del_strarr(&arr);
		mx_printerr("error: invalid number of islands \n");
		exit(0);
	}
}

static char **create_arr(int j) {
	char **arr = (char **)(malloc)(sizeof(char*) * (j + 1));

	if (j == 0)
		exit(0);
	for(int i = 0; i <= j; i++)
		arr[i] = NULL;
	return arr;
}

int **mx_test_countwords(char **n, int **new, char ***ar) {
	int k = 0;
	int j = mx_count(&n[0][0]);
	char **s1 = NULL;
	char **arr = create_arr(j);

	for (int i = 1; n[i] != NULL; i++) {
		check_G(&s1, n, i);
		if (check(arr, s1[0], k) == 0)
			arr[k++] = mx_strdup(s1[0]);
		if (check(arr, s1[1], k) == 0)
			arr[k++] = mx_strdup(s1[1]);
		if (k == j + 1)
			break;
		mx_write_matrix(s1, new, arr);
		mx_del_strarr(&s1);
	}
	mx_del_strarr(&n);
	check_first_line(arr, j);
	*ar = arr;
	return new;
}

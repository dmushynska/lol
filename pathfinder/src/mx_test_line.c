#include "../inc/pathfinder.h"

static void firstline(char *str) {
	int i = 0;

	while (i < mx_strlen(str)) {
		if (mx_isdigit(str[i]) == 1) {
			i++;
		}
		else {
			mx_printerr("error: line 1 is not valid \n");
			exit(0);
		}
	}
}

static void check_zero(char *s1, char s2) {
	if (mx_strcmp(s1 , "0") == 0  && !s2) {
		mx_printerr("error: line 1 is not valid \n");
		exit(0);
	}
}

static void check_n(const char *str) {
	int j = 0;
	int k = mx_strlen(str);

	for (int i = 0; i < k; i++) {
		if (str[i] == '\n' && str[i + 1] == '\n') {
			j++;
			mx_printerr("error: line ");
			mx_printinterr(j + 1);
			mx_printerr(" is not valid \n");
			exit(0);
		}
		if (str[i] == '\n')
			j++;
	}
	if (str[k - 1] != '\n') {
		mx_printerr("error: line ");
		mx_printinterr(j + 1);
		mx_printerr(" is not valid \n");
		exit(0);
	}
}

static void check(const char *str) {
	if (str[0] == '\n') {
		mx_printerr("error: line 1 is not valid \n");
		exit(0);
	}
	check_n(str);
}

char **mx_test_line(const char *str) {
	int i = 0;
	int k = 0;
	char **new;
	
	check(str);
	new = mx_strsplit(str, '\n');
	firstline(&new[i][k]);
	i = 1;
	check_zero(&new[k][k], new[k][i]);
	while (new[i] != NULL) {
		if (mx_allline(&new[i][k]) == 0) {
			mx_printerr("error: line ");
			mx_printinterr(i + 1);
			mx_printerr(" is not valid \n");
			mx_del_strarr(&new);
			exit(0);
		}
		i++;
	}
	return new;
}

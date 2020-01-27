#include "pathfinder.h"

static int str_to_int(const char *str) {
    unsigned int n = 0;

    for (int i = 0; i < mx_strlen(str); i++) {
        n = n * 10;
        n = n + (str[i] - 48);
    }
    return n;
}

static void write_int(int i, int j, int **new, char **n) {
    if (new[i][j] == -1 && new[j][i] == -1 && n[2] != 0) {
        new[i][j] = str_to_int(n[2]);
        new[j][i] = str_to_int(n[2]);
    }
    else if (new[i][j] > str_to_int(n[2])) {
        new[i][j] = str_to_int(n[2]);
        new[j][i] = str_to_int(n[2]);
    }
}

void mx_write_matrix(char **n, int **new, char **arr) {
    int i = 0;
    int j = 0;

    if (arr[i] == NULL)
        return;
    if (mx_strcmp(n[1], n[0]) == 0)
        new[0][0] = 0;
    while (arr[i]) {
        if (mx_strcmp(arr[i], n[0]) == 0)
            break;
        i++;
    }
    while (arr[j]) {
        if (mx_strcmp(arr[j], n[1]) == 0)
            break;
        j++;
    }
    write_int(i, j, new, n);
}

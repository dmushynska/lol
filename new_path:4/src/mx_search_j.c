#include "pathfinder.h"

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


void mx_create_arr_for_heh(t_hehx *heh) {
    heh->new_arr = (char **)malloc(sizeof(char *) * (heh->k + 1));
    heh->lol = 0;
    for (int i = 0; i < heh->k + 1; i++)
        heh->new_arr[i] = NULL;
}


void mx_copy_int(int *arr, int **arr2, t_hehx *heh) {
    int *str_copy = (int *)malloc(sizeof(int) * (heh->k + 1));

    for (int u = 0; u < heh->k + 1; u++)
        str_copy[u] = arr[u];
    *arr2 = str_copy;
}


void mx_copy(char **arr, char ***arr2, t_hehx *heh) {
    char **new_arr = (char **)malloc(sizeof(char *) * (heh->k + 1));
    int u = 0;

    for (u = 0; u < heh->k + 1; u++)
        new_arr[u] = NULL;
    for (u = 0; arr[u] != NULL && u < heh->k + 1; u++)
        new_arr[u] = mx_strdup(arr[u]);
    *arr2 = new_arr;
}

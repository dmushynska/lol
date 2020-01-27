#include "pathfinder.h"

static void index_return(t_hehx *heh, int **ser) {
    heh->new = ser[0][heh->i];
    heh->str_result = (int *)malloc(sizeof(int) * (heh->k + 1));
    heh->index = 0;
    for (int j = 0; j < heh->k + 1; j++)
        heh->str_result[j] = -1;
    heh->new = heh->new - ser[0][heh->h];
    heh->str_result[heh->index++] = heh->new;
    mx_create_arr_for_heh(heh);
    heh->new_arr[heh->lol++] = mx_strdup(heh->arr[heh->i]);
    heh->new_arr[heh->lol++] = mx_strdup(heh->arr[heh->h]);
}

static void auditor(int **ser, t_hehx *heh, t_result **struct_result) {
    t_hehx *new_heh;

    for (int m = 3; ser[m][heh->h] != -1; m++) {
        new_heh = (t_hehx *)malloc(sizeof(t_hehx));
        new_heh->k = heh->k;
        new_heh->i = heh->i;
        new_heh->j = heh->j;
        new_heh->index = heh->index;
        new_heh->new = ser[0][heh->h];
        new_heh->h = ser[m][heh->h];
        new_heh->new = new_heh->new - ser[0][new_heh->h];
        new_heh->lol = heh->lol;
        mx_copy_int(heh->str_result, &new_heh->str_result, heh);
        new_heh->arr = heh->arr;
        mx_copy(heh->new_arr, &new_heh->new_arr, heh);
        new_heh->new_arr[new_heh->lol++] = mx_strdup(new_heh->arr[new_heh->h]);
        new_heh->str_result[new_heh->index++] = new_heh->new;
        mx_search_distance(ser, new_heh, heh->j, struct_result);
        free(new_heh);
    }
}

void mx_search_distance(int **ser, t_hehx *heh, int j,
t_result **struct_result) {
    while (ser[2][heh->h] != j) {
        auditor(ser, heh, struct_result);
        heh->new = ser[0][heh->h];
        heh->h = ser[2][heh->h];
        heh->new = heh->new - ser[0][heh->h];
        heh->new_arr[heh->lol++] = mx_strdup(heh->arr[heh->h]);
        heh->str_result[heh->index++] = heh->new;
    }
    auditor(ser, heh, struct_result);
    if (ser[0][heh->h] != 0)
        heh->str_result[heh->index++] = ser[0][heh->h];
    heh->new_arr[heh->lol++] = mx_strdup(heh->arr[j]);
    mx_push_front_new(struct_result, heh->str_result, heh->new_arr, heh);
    free(heh->str_result);
    mx_del_strarr(&heh->new_arr);
}

static void print_first_line(int ***ser, t_hehx *heh,
t_result **struct_result) {
    int *str_result = (int *)malloc(sizeof(int) * (heh->k + 1));
    char **new_arr = (char **)malloc(sizeof(char *) * (heh->k + 1));

    for (int u = 0; u < heh->k + 1; u++) {
        str_result[u] = -1;
        new_arr[u] = NULL;
    }
    new_arr[0] = mx_strdup(heh->arr[heh->i]);
    new_arr[1] = mx_strdup(heh->arr[heh->j]);
    str_result[0] = ser[heh->j][0][heh->i];
    mx_push_front_new(struct_result, str_result, new_arr, heh);
    free(str_result);
    mx_del_strarr(&new_arr);
}

void mx_search_rout(int ***ser, t_hehx *heh, int j) {
    int m = 2;
    t_result *struct_result = NULL;

    while (ser[j][m][heh->i] != -1) {
        heh->m = 3;
        heh->h = ser[j][m][heh->i];
        if (ser[j][m][heh->i] != j && ser[j][m][heh->i] != 2147483647) {
            index_return(heh, ser[j]);
            mx_search_distance(ser[heh->j], heh, j, &struct_result);
        }
        if (ser[j][m][heh->i] == j)
            print_first_line(ser, heh, &struct_result);
        m++;
    }
    mx_print_list(struct_result, heh, ser[j]);
}

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
    for (int m = 3; ser[m][heh->h] != -1 && ser[m][heh->h] != heh->j; m++) {
        t_hehx *new_heh = (t_hehx *)malloc(sizeof(t_hehx));

        new_heh->k = heh->k;
        new_heh->i = heh->i;
        new_heh->j = heh->j;
        new_heh->index = heh->index;
        new_heh->new = ser[0][heh->h];
        new_heh->h = ser[m][heh->h];
        new_heh->new = new_heh->new - ser[0][new_heh->h];
        new_heh->lol = heh->lol;
        mx_copy_int(heh->str_result, &new_heh->str_result, heh);
        mx_copy(heh->arr, &new_heh->arr, heh);
        mx_copy(heh->new_arr, &new_heh->new_arr, heh);
        new_heh->new_arr[new_heh->lol++] = mx_strdup(new_heh->arr[new_heh->h]);
        new_heh->str_result[new_heh->index++] = new_heh->new;
        mx_search_distance(ser, new_heh, heh->j, struct_result);
        mx_del_strarr(&new_heh->arr);
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
    int *search_m = NULL;
    int p = 0;
    t_result *struct_result = NULL;

    search_m = mx_search_m_func(heh, ser[j]);
    while (search_m[p] != -1) {
        heh->m = 3;
        heh->h = search_m[p];
        if (search_m[p] != j && search_m[p] != 2147483647) {
            index_return(heh, ser[j]);
            mx_search_distance(ser[heh->j], heh, j, &struct_result);
        }
        if (search_m[p] == j)
            print_first_line(ser, heh, &struct_result);
        p++;
    }
    mx_print_list(struct_result, heh, ser[j]);
    free(search_m);
}

#include "pathfinder.h"

static int index_return(int *str_result, int new, t_hehx *heh, int **ser) {
    int index = 0;

    for (int j = 0; j < heh->k + 1; j++)
        str_result[j] = -1;
    new = new - ser[0][heh->h];
    str_result[index++] = new;
    mx_create_arr_for_heh(heh);
    return index;
}

static void auditor(int **ser, t_hehx *heh, int* str_result, t_result **struct_result) { // 5
    if (ser[heh->m][heh->try] != -1 && ser[heh->m][heh->try ] != heh->j)
        heh->m = 3;
    while (ser[heh->m][heh->try] != -1 && ser[heh->m][heh->try] != heh->j) {
        mx_search_rout_2(ser, heh, str_result, struct_result);
        heh->m++;
    }
}

static void search_distance(int **ser, t_hehx *heh, int j, t_result **struct_result) {
    int h = heh->h;
    int new = ser[0][heh->i];
    int *str_result = (int *)malloc(sizeof(int) * (heh->k + 1));
    int index = index_return(str_result, new, heh, ser);

    heh->new_arr[heh->lol++] = mx_strdup(heh->arr[heh->i]);
    heh->new_arr[heh->lol++] = mx_strdup(heh->arr[h]);
    heh->try = h;
    auditor(ser, heh, str_result, struct_result);
    while (ser[2][h] != j) {
        new = ser[0][h];
        h = ser[2][h];
        heh->try = h;
        new = new - ser[0][h];
        heh->next = new;
        heh->new_arr[heh->lol++] = mx_strdup(heh->arr[h]);
        str_result[index++] = new;
        auditor(ser, heh, str_result, struct_result);
    }
    if (ser[0][h] != 0)
        str_result[index++] = ser[0][h];
    heh->new_arr[heh->lol++] = mx_strdup(heh->arr[j]);
    mx_push_front_new(struct_result, str_result, heh->new_arr, heh);
    free(str_result);
    mx_del_strarr(&heh->new_arr);
}

static void print_first_line(int ***ser, t_hehx *heh, t_result **struct_result) {
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
        if (search_m[p] != j && search_m[p] != 2147483647)
            search_distance(ser[heh->j], heh, j, &struct_result);
        if (search_m[p] == j)
            print_first_line(ser, heh, &struct_result);
        if (search_m[p] == search_m[p + 1])
            break;
        p++;
    }
    mx_print_list(struct_result, heh, ser[j]);
    free(search_m);
}

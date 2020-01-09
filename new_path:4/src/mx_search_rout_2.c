#include "pathfinder.h"

static int create_new_arr_2(t_hehx *heh, int h, int *str_result, int *str_copy) {
    int index = 0;
    for (int u = 0; u < heh->k + 1; u++)
        str_copy[u] = str_result[u];
    while (str_copy[++index] != -1);
    str_copy[index++] = heh->next;
    heh->new_arr_2 = (char **)malloc(sizeof(char *) * (heh->k + 1));
    for (int g = 0; g < heh->k + 1; g++)
        heh->new_arr_2[g] = NULL;
    for (int l = 0; heh->new_arr[l] != NULL && l < heh->k; l++)
        heh->new_arr_2[heh->kek++] = mx_strdup(heh->new_arr[l]);
    heh->new_arr_2[heh->kek++] = mx_strdup(heh->arr[h]);
    return index;
}

static void search_distance_th(int **ser, t_hehx *heh, int *str_result, t_result **struct_result) {
    int h = heh->save_h;
    int new = ser[0][heh->save_h];
    int *str_copy = (int *)malloc(sizeof(int) * (heh->k + 1));
    int index = create_new_arr_2(heh, h, str_result, str_copy);

    while (h != heh->j) {
        new = ser[0][h];
        h = ser[2][h];
        heh->new_arr_2[heh->kek++] = mx_strdup(heh->arr[h]);
        new = new - ser[0][h];
        str_copy[index++] = new;
    }
    if (ser[0][h] != 0)
        str_copy[index++] = ser[0][h];
    mx_push_front_new(struct_result, str_copy, heh->new_arr_2, heh);
    free(str_copy);
    mx_del_strarr(&heh->new_arr_2);
}

void mx_search_rout_2(int **ser, t_hehx *heh, int *str_result, t_result **struct_result) {
    heh->next = ser[0][heh->try] - ser[0][ser[heh->m][heh->try]];
    heh->kek = 0;
    heh->save_h = ser[heh->m][heh->try];
    search_distance_th(ser, heh, str_result, struct_result);
}

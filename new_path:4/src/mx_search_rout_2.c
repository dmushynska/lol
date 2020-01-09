#include "pathfinder.h"

static void search_distance_rec(int **ser, t_hehx *heh, int *str_result, t_result **struct_result);
static int create_new_arr_2(t_hehx *heh, int h, int *str_result, int *str_copy) {
    int index = 0;
    int u = 0;

    for (; u < heh->k + 1; u++)
        str_copy[u] = str_result[u];
    while (str_copy[++index] != -1);
    str_copy[index++] = heh->next;
    heh->new_arr_2 = (char **)malloc(sizeof(char *) * (heh->k + 1));
    for (u = 0; u < heh->k + 1; u++)
        heh->new_arr_2[u] = NULL;
    for (u = 0; heh->new_arr[u] != NULL && u < heh->k + 1; u++) {
        heh->new_arr_2[heh->kek++] = mx_strdup(heh->new_arr[u]);
    }
    heh->new_arr_2[heh->kek++] = mx_strdup(heh->arr[h]);
    return index;
}

// static void auditor(int **ser, t_hehx *heh, int* str_copy, t_result **struct_result) {
//     int m = 3;

//     while (ser[m][heh->vlad] != -1) {
//         heh->new = heh->kek;
//         heh->kek = 0;
//         heh->next = ser[0][heh->vlad] - ser[0][ser[m][heh->vlad]];
//         heh->save_h = ser[m][heh->vlad];
//         heh->save_arr = heh->new_arr;
//         heh->new_arr = heh->new_arr_2;
//         search_distance_rec(ser, heh, str_copy, struct_result);
//         heh->new_arr = heh->save_arr;
//         heh->kek = heh->new;
//         m++;
//     }
// }

static void search_distance_rec(int **ser, t_hehx *heh, int *str_result, t_result **struct_result) {
    int new = ser[0][heh->save_h];
    int *str_copy = (int *)malloc(sizeof(int) * (heh->k + 1));
    int index = create_new_arr_2(heh, heh->save_h, str_result, str_copy);

    heh->vlad = heh->save_h;
    // auditor(ser, heh, str_copy, struct_result);
    while (heh->vlad != heh->j) {
        new = ser[0][heh->vlad];
        heh->vlad = ser[2][heh->vlad];
        heh->new_arr_2[heh->kek++] = mx_strdup(heh->arr[heh->vlad]);
        new = new - ser[0][heh->vlad];
        str_copy[index++] = new;
        // auditor(ser, heh, str_copy, struct_result);
    }
    if (ser[0][heh->vlad] != 0)
        str_copy[index++] = ser[0][heh->vlad];

    mx_push_front_new(struct_result, str_copy, heh->new_arr_2, heh);
    free(str_copy);
    mx_del_strarr(&heh->new_arr_2);
}

void mx_search_rout_2(int **ser, t_hehx *heh, int *str_result, t_result **struct_result) {
    heh->next = ser[0][heh->try] - ser[0][ser[heh->m][heh->try]];
    heh->kek = 0;
    heh->save_h = ser[heh->m][heh->try];
    search_distance_rec(ser, heh, str_result, struct_result);
}

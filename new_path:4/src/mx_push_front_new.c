#include "pathfinder.h"

t_result *mx_create_node_new(int *str_result, char **new_arr, t_hehx *heh) {
    t_result *struct_result = (t_result *)malloc(sizeof(t_result));

    struct_result->result = (int *)malloc(sizeof(int) * (heh->k + 1));
    struct_result->arr_result = (char **)malloc(sizeof(char *) * (heh->k + 1));
    for (int u = 0; u < heh->k + 1; u++)
        struct_result->result[u] = str_result[u];
    for (int u = 0; u < heh->k + 1; u++)
        struct_result->arr_result[u] = NULL;
    for (int u = 0; new_arr[u] != NULL; u++)
        struct_result->arr_result[u] = mx_strdup(new_arr[u]);
    struct_result->next = NULL;
    return struct_result;
}

void mx_push_front_new(t_result **list, int *str_result, char **new_arr,
t_hehx *heh) {
    t_result *tmp = *list;

    if (*list == 0) {
        *list = mx_create_node_new(str_result, new_arr, heh);
        return;
    }
    *list = mx_create_node_new(str_result, new_arr, heh);
    (*list)->next = tmp;
}

#include "pathfinder.h"

t_result *mx_create_node_new(int *str_result, char **new_arr, t_hehx *heh) {
    t_result *head = NULL;

    head = malloc(sizeof(t_result));
    if (head == NULL)
        return 0;
    head->result = (int *)malloc(sizeof(int) * (heh->k + 1));
    head->arr_result = (char **)malloc(sizeof(char *) * (heh->k + 1));
    for (int u = 0; u < heh->k + 1; u++)
        head->result[u] = str_result[u];
    for (int u = 0; u < heh->k + 1; u++)
        head->arr_result[u] = NULL;
    for (int u = 0; new_arr[u] != NULL; u++)
        head->arr_result[u] = mx_strdup(new_arr[u]);
    head->next = NULL;
    return head;
}

void mx_push_front_new(t_result **list, int *str_result, char **new_arr, t_hehx *heh) {
    t_result *tmp = *list;

    if (*list == 0) {
        *list = mx_create_node_new(str_result, new_arr, heh);
        return;
    }
    // mx_printstr(" kek2 ");
    *list = mx_create_node_new(str_result, new_arr, heh);
    (*list)->next = tmp;
}

#include "pathfinder.h"

static bool cmp(char **s1, char **s2, char **arr, t_hehx *heh) {
    int i = heh->k;
    int m = heh->k;
    int j = 0;
    int k = 0;

    while (s1[--i] == NULL);
    while (s2[--m] == NULL);
    while (mx_strcmp(s1[--i], s2[--m]) == 0);
    while (mx_strcmp(s1[i], arr[j]) != 0)
        j++;
    while (mx_strcmp(s2[m], arr[k]) != 0)
        k++;
        if (j - k > 0)
            return true;
        else
            return false;
}

static void sort_list(t_result **struct_result,
bool (*cmp)(char **s1, char **s2, char **arr, t_hehx *heh), t_hehx *heh) {
    t_result *i;
    t_result *j;
    char **new_arr;
    int *new;

    for (i = *struct_result; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next)
            if ((*cmp)(i->arr_result, j->arr_result, heh->arr, heh) > 0) {
                new_arr = i->arr_result;
                new = i->result;
                i->arr_result = j->arr_result;
                i->result = j->result;
                j->arr_result = new_arr;
                j->result = new;
            }
    }
}

static void print_path_rout(t_hehx *heh, t_result *struct_result, int vlad) {
    mx_printstr("Path: ");
    mx_printstr(heh->arr[heh->j]);
    mx_printstr(" -> ");
    mx_printstr(heh->arr[heh->i]);
    mx_printstr("\nRoute: ");
    while (struct_result->arr_result[--vlad] == NULL);
    while (vlad > -1) {
        mx_printstr(struct_result->arr_result[vlad--]);
        if (vlad >= 0)
            mx_printstr(" -> ");
        }
}

static void print__distance(t_hehx *heh, t_result *struct_result, int v1,
int **ser) {
    mx_printstr("\nDistance: ");
    while (struct_result->result[--v1] == -1);
    if (v1 >= 1) {
    while (v1 > -1) {
            mx_printint(struct_result->result[v1--]);
            if (v1 >= 0)
            mx_printstr(" + ");
        }
        mx_printstr(" = ");
    }
        mx_printint(ser[0][heh->i]);
        mx_printchar(10);
}

void mx_print_list(t_result *struct_result, t_hehx *heh, int **ser) {
    int vlad = heh->k + 1;
    int vlad1 = heh->k + 1;
    t_result *new = struct_result;

    sort_list(&struct_result, cmp, heh);
    while (struct_result != NULL) {
        mx_printstr("========================================\n");
        print_path_rout(heh, struct_result, vlad);
        print__distance(heh, struct_result, vlad1, ser);
        free(struct_result->result);
        mx_del_strarr(&struct_result->arr_result);
        struct_result = struct_result->next;
        free(new);
        new= struct_result;
        vlad = heh->k + 1;
        vlad1 = heh->k + 1;
        mx_printstr("========================================\n");
    }
    struct_result = NULL;
}

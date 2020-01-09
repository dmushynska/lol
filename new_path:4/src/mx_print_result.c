#include "pathfinder.h"

static bool cmp(char **s1, char **s2, char **arr, t_hehx *heh) {
    int i = 0;
    int j = 0;
    int k = 0;

    while (mx_strcmp(s1[i], s2[i]) == 0)
        i++;
    while (mx_strcmp(s1[i], arr[j]) != 0)
        j++;
    while (mx_strcmp(s2[i], arr[k]) != 0)
        k++;
    return j - k;
}

static void sort_list(t_result **struct_result, bool (*cmp)(char **s1, char **s2, char **arr, t_hehx *heh), t_hehx *heh) {
    t_result *i;
    t_result *j;
    t_result *l;

    for (l = *struct_result; l != NULL; l = l->next)
        for (i = *struct_result; i != NULL; i = i->next)
            for (j = i->next; j != NULL; j = j->next) {
                // for (int u = 0; u < heh->k; u++)
                //     printf("№ %s №", i->arr_result[u]);
                // mx_printchar(10);
                if ((*cmp)(i->arr_result, j->arr_result, heh->arr, heh) > 0) {
                    char **new = i->arr_result;
                    // int *new1 = i->result;
                    i->arr_result = j->arr_result;
                    // i->result = j->result;
                    j->arr_result = new;
                    // j->result = new1;
                    new = NULL;
                    // for (int u = 0; u < heh->k; u++)
                    //     printf("* %s *", i->arr_result[u]);
                    // mx_printchar(10);
                }
            }
}

void mx_print_list(t_result *struct_result, t_hehx *heh, int **ser) {
    int vlad = heh->k + 1;
    int vlad1 = heh->k + 1;

    // sort_list(&struct_result, cmp, heh);
    while (struct_result != NULL) {
        sort_list(&struct_result, cmp, heh);
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
        mx_printstr("\nDistance: ");
        while (struct_result->result[--vlad1] == -1);
        while (vlad1 > -1) {
            mx_printint(struct_result->result[vlad1--]);
            if (vlad1 >= 0)
            mx_printstr(" + ");
        }
        mx_printstr(" = ");
        mx_printint(ser[0][heh->i]);
        mx_printchar(10);
        free(struct_result->result);
        mx_del_strarr(&struct_result->arr_result);
        free(struct_result);
        struct_result = struct_result->next;
        vlad = heh->k + 1;
        vlad1 = heh->k + 1;
        mx_printchar('\n');
    }
}

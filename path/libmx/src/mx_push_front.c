#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *tmp = *list;

    if (*list == 0) {
        *list = mx_create_node(data);
        return;
    }
    *list = mx_create_node(data);
    (*list)->next = tmp;
}

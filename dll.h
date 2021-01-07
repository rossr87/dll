#ifndef DLL_H
#define DLL_H

typedef struct dll_node_ {
    void *data;
    struct dll_node_ *left;
    struct dll_node_ *right;
} dll_node_t;

typedef struct dll_ {
    dll_node_t *head;
} dll_t;

dll_t *get_new_dll();
int append_item(dll_t *list, void *app_data);
int prepend_item(dll_t *list, void *app_data);

#endif

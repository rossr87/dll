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
int remove_data_from_dll_by_data_ptr(dll_t list*, void *app_data);	/* return 0 on success, -1 on failure */
int is_dll_empty(dll_t *list);						/* return 0 if empty, -1 if non-empty */
void drain_dll(dll_T *list);						/* delete all nodes from dll, but do not free the data */
#endif

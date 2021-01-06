typedef struct dll_node_ {
    void *data;
    struct dll_node_ *left;
    struct dll_node_ *right;
} dll_node_t;

typedef struct dll_ {
    dll_node_t *head;
} dll_t;

/*
 * allocate a new list on the heap.
 * this is merely a pointer to a dll_node_t (dll node)
 * then return the address of this pointer.
 */
dll_t *get_new_dll();

/*
 * append data to list.
 * inputs: pointer to the list: the list is on the heap and we need to know where it is
 */
int append_item(dll_t *list, void *app_data);
int prepend_item(dll_t *list, void *app_data);

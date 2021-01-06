#include <stdio.h>
#include <string.h>
#include <stdlib.h>

dll_t *get_new_dll() {
    dll_t *new_list = (dll_t*)malloc(sizeof(dll_t));
    return new_list;
}

int append_item(dll_t *list, void *app_data) {
    
    dll_node_t *new_node = (dll_node_t*)malloc(sizeof(dll_node_t));
    if (!new_node) {
        return -1;
    }
    else {
        new_node->data = app_data;
        new_node->right = NULL;
        new_node->left = NULL;
    }

    if (!list->head) {
        list->head = new_node;
        return 0;
    }
    else {
        dll_node_t *current_node;
        
        current_node = list->head;
        while (current_node->right) {
            current_node = current_node->right;
        }
        current_node->right = new_node;
        new_node->left = current_node;
        new_node->right = NULL;
        
        return 0;
    }
}

int prepend_item(dll_t *my_list, void *app_data) {
    
    dll_node_t *new_node = (dll_node_t*)malloc(sizeof(dll_node_t));
    if (new_node) {
        fprintf(stderr, "New node allocated.\n");
    }
    else {
        fprintf(stderr, "Error allocating new node !\n");
        return -1;
    }

    new_node->right = NULL;
    new_node->left = NULL;

    new_node->data = app_data;

    new_node->right = my_list->head;
    if (!new_node->right) {
        my_list->head = new_node;
    }
    else {
        my_list->head->left = new_node;
        my_list->head = new_node;
    }

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * allocate a new list on the heap.
 * this is merely a pointer to a dll_node_t (dll node)
 * then return the address of this pointer.
 */
dll_t *get_new_dll() {
    dll_t *new_list = (dll_t*)malloc(sizeof(dll_t));
    return new_list;
}

/*
 * append data to list.
 * inputs: pointer to the list: the list is on the heap and we need to know where it is
 * output: list with new data at the final node.
 */
int append_item(dll_t *list, void *app_data) {
    
    dll_node_t *new_node = (dll_node_t*)malloc(sizeof(dll_node_t));
    if (!new_node) {
        fprintf(stderr, "Error allocating a new node!\n");
        return -1;
    }
    else {
        new_node->data = app_data;
    }

    if (!list->head) {
        fprintf(stderr, "List is empty, exiguously appending\n");
        list->head = new_node;
        return 0;
    }
    else {
        fprintf(stderr, "List is not empty\n");
        
        dll_node_t *current_node;
        
        /*
         * Setting current node to point to the same node that the list head is
         * pointing to.
         */
        fprintf(stderr, "Starting at the head.\n\n");
        current_node = list->head;
        while (current_node->right) {
            current_node = current_node->right;
            fprintf(stderr, "Moving one node ahread\n\n");
        }
        fprintf(stderr, "Have a reference to the final node in the list.\n\n");
        fprintf(stderr, "Appending the new node to the list.\n\n");
        current_node->right = new_node;
        fprintf(stderr, "Setting the new final node to point to the penaltimate node.\n\n");
        new_node->left = current_node;

        new_node->right = NULL;
        if (!new_node->right) {
            fprintf(stderr, "Final node is now pointing to NULL\n\n");
        }
        return 0;
    }
}

/*
 * input: list, item
 * output: list with new item as its first element.
 *         that is, the head of the list now points to the 
 *         new item and the new item points to the item
 *         that the head pointed to before the new item was added, this item
 *         also pointing (through it's left ptr) to the new node.
 */

int prepend_item(dll_t *my_list, void *app_data) {
    
    if (!my_list->head) {
        fprintf(stderr, "List is empty\n");
    }
    else {
        fprintf(stderr, "List is not empty.\n");
    }

    /*
     * Allocating a new node
     */
    dll_node_t *new_node = (dll_node_t*)malloc(sizeof(dll_node_t));
    if (new_node) {
        fprintf(stderr, "New node allocated.\n");
    }
    else {
        fprintf(stderr, "Error allocating new node !\n");
        return -1;
    }

    /*
     * Set payload of the new node.
     */
    new_node->data = app_data;

    /*
     * set the new node (through it's right ptr) to point to the first node in the list.
     * set the first node in the list to point to the new node (via it's left ptr)
     * set the head of the list to point to the new node.
     * new node is now the first node in the list.
     */
    new_node->right = my_list->head;

    if (!new_node->right) {
        fprintf(stderr, "Empty list.\n");
        my_list->head = new_node;
    }
    else {
        fprintf(stderr, "Non-empty list.");
        my_list->head->left = new_node;
        my_list->head = new_node;
    }

    return 0;
}

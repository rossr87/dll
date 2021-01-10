#include "dll.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 *  Test application for DLL
 */

typedef struct person_ {
    char name[32];
    int age;
    int weight;
} person_t;

/*
 * the generic dll was defined
 * in this section we make use of this to construct
 * our specific list
 */


void print_person(person_t *person) {

    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Weight: %d\n", person->weight);
}

/*
 * Since this is the derived list, we *know* what kind of
 * data we're dealing with (with respect to the fact that
 * we declared the user data to be of type void). We let 
 * it be void in the generic library and when we make use
 * of it in our more specific/derived case we cast it, 
 * knowing the kind of data we are using.
 */
void print_list(dll_t *my_list) {
    if (!my_list->head) {
        printf("Empty\n");
        return;
    }
    printf("Non-empty\n");
    dll_node_t *current_node;
    current_node = my_list->head;
    while (current_node) {
        printf("Person:\n");
        if (current_node->data) {
            print_person((person_t*)current_node->data);
        }
        else {
            printf("-------n/a------\n\n");
        }
        current_node = current_node->right;
    }
    return;
}

void remove_person_from_list(dll_t *person_list, person_t *person) {
   

    int result = 0;
 
    result = remove_data_from_dll_by_data_ptr(person_list, (void*)person);
   
    if (result == 0) {
        fprintf(stderr, "Person removed from list.\n");
    }
    else {
        fprintf(stderr, "Person: %s could not be removed from the list.\n", person->name);
    }
}

int main(int argc, char **argv()) {
    person_t *mickey = (person_t*)malloc(sizeof(person_t));
    
    if (!mickey) {
        fprintf(stderr, "Error! Can not allocate a person!\n");
    }

    strncpy(mickey->name, "Mickey", sizeof("Mickey"));
    mickey->age = 123133;
    mickey->weight = 12333;

    person_t *terry = (person_t*)malloc(sizeof(person_t));
   
    if (!terry) {
        fprintf(stderr, "Error! Can not allocate a person!\n");
    }
    strncpy(terry->name, "terry", sizeof("terry"));
    terry->age = 4234;
    terry->weight = 341;

    person_t *pat = (person_t*)malloc(sizeof(person_t));

    if (!pat) {
        fprintf(stderr, "Error! Can not allocate a person!\n");
    }
    strncpy(pat->name, "pat", sizeof("pat"));
    pat->age = 4204;
    pat->weight = 241;

    /*
     * Create person list
     */  
    dll_t *person_list;
    person_list = get_new_dll();
   
    if (!person_list) {
        fprintf(stderr, "Error allocating person list!\n");
        return -1;
    }


    if (is_dll_empty(person_list) == 0) {
        fprintf(stderr, "DLL is empty.\n");
    }

    printf("Appending Mickey..........\n");
    append_item(person_list, mickey);
    printf("Printing List:.............\n");
    print_list(person_list);

    if (is_dll_empty(person_list) == 0) {
        fprintf(stderr, "I should not be here!\n\n");
    }
    printf("Appending Terry:\n\n");
    append_item(person_list, terry);
    printf("Appending Pat:\n\n");
    append_item(person_list, pat);
    printf("Printing List:\n\n");
    print_list(person_list);

    printf("Removing Pat....\n\n");
    remove_person_from_list(person_list, pat);
    printf("Printing List:\n\n");
    print_list(person_list);

    printf("Draining List........\n");
    drain_dll(person_list);
    print_list(person_list);

    return 0;
}

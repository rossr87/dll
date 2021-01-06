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


print_person(person_t *person) {
    printf("Name: %s\n", person->name);
    printf("Age: %d\n", person->age);
    printf("Weight: %d\n", person->weight);
}

int main(int argc, char **argv()) {
    person_t *mickey = (person_t*)malloc(sizeof(person_t));
    
    if (!mickey) {
        fprintf(stderr, "Error! Can not allocate a person!\n");
    }

    strncpy(mickey->name, "Mickey", sizeof("Mickey"));
    mickey->age = 123133;
    mickey->weight = 12333;

    print_person(mickey);

    person_t *terry = (person_t*)malloc(sizeof(person_t));
   
    if (!terry) {
        fprintf(stderr, "Error! Can not allocate a person!\n");
    }
    strncpy(terry->name, "terry", sizeof("terry"));
    terry->age = 4234;
    terry->weight = 341;

    print_person(terry);
    
    person_t *pat = (person_t*)malloc(sizeof(person_t));

    if (!pat) {
        fprintf(stderr, "Error! Can not allocate a person!\n");
    }
    strncpy(pat->name, "pat", sizeof("pat"));
    pat->age = 4204;
    pat->weight = 241;

    print_person(pat);
    return 0;
}

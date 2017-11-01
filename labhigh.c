#include <stdio.h>
#include <stdlib.h>
#include "lab.h"

void foreach(struct node_s* list, void(*func)(int32_t arg)){
    struct node_s* counter = list;
    while (counter) {
        func(counter->element);
        counter = counter->next_node;
    }
}


struct node_s* map(struct node_s* list, int32_t(*func)(int32_t)){
    struct node_s* counter = list;
    struct node_s* new_list = list_create(func(counter->element));
    counter = counter->next_node;
    while (counter) {
        list_add_back(func(counter->element), &new_list);
        counter = counter->next_node;
    }

    return new_list;
}


void map_mut(struct node_s* list, int32_t(*func)(int32_t)){
    struct node_s* counter = list;
    while(counter){
        counter->element = func(counter->element);
        counter = counter->next_node;
    }
}


int32_t foldl(int32_t a, int32_t(*func)(int32_t, int32_t), struct node_s* list){
    struct node_s* counter = list;
    while(counter){
        a = func(counter->element, a);
        counter = counter->next_node;
    }

    return a;
}


struct node_s* iterate(int32_t s, int32_t n, int32_t(*f)(int32_t)){
    struct node_s* new_list = list_create(s);
    struct node_s* counter = new_list;
    int i;

    for (i = 1; i < n; i++) {
        list_add_back(f(counter->element), &new_list);
        counter = counter->next_node;
    }

    return new_list;
}

/*====================taskfuncs*/

void print_space(int32_t arg){
    printf("%d ", arg);
}

void print_newline(int32_t arg){
    printf("%d\n", arg);
}

int32_t square(int32_t a){
    a *= a;
    printf("%d ", a);

    return a;
}

int32_t cube(int32_t a){
    a *= a;
    a *= a;
    printf("%d ", a);

    return a;
}

int32_t find_smallest(int32_t a, int32_t b){
    int c;
    if (b > a){
        c = a;
    }

    return c;
}

int32_t find_biggest(int32_t a, int32_t b){
    int c;
    if (b < a) {
        c = a;
    }

    return c;
}

int32_t abs(int32_t a){
    if (a < 0) {
        a = -a;
    }
    printf("%d ", a);

    return a;
}

int32_t mul_2(int32_t a){
    a *= 2;

    return a;
}


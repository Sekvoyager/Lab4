#include <stdio.h>
#include <stdlib.h>
#include "lab.h"

struct node_s* list_create(__int32_t value){
    struct node_s* node_pointer = (malloc(sizeof(struct node_s)));

    node_pointer->element = value;
    node_pointer->next_node = NULL;

    return node_pointer;
}


struct node_s* list_add_front(__int32_t value, struct node_s** header){
    struct node_s* first_node = malloc(sizeof(struct node_s));

    first_node->element = (*header)->element;
    first_node->next_node = (*header)->next_node;
    (*header)->element = value;
    (*header)->next_node = first_node;

    return *header;
}


struct node_s* list_add_back(__int32_t value, struct node_s** header){
    struct node_s* node_pointer = malloc(sizeof(struct node_s));
    struct node_s* node_counter = *header;

    while(node_counter->next_node != NULL){
        node_counter = node_counter->next_node;
    }
    node_counter->next_node = node_pointer;
    node_pointer->next_node = NULL;
    node_pointer->element = value;

    return node_pointer;
}


__int32_t list_get(__int32_t index, struct node_s* list){ /* mne ne nrav */
    __int32_t element = 0, counter;
    struct node_s* node_counter = list;

    for (counter = 0; counter <= index; counter++){
        if (node_counter->next_node == NULL){
            break;
        }
        else {
            if (counter == index){
                element = node_counter->element;
            }
            else{
                node_counter = node_counter->next_node;
            }
        }
    }

    return element;
}

void list_free(struct node_s* list){
    struct node_s* counter = list;
    struct node_s* next_counter;

    while (counter->next_node != NULL){
        next_counter = counter->next_node;
        free(counter);
        counter = next_counter;
    }
    free(counter);
}


__int32_t list_sum(struct node_s* list){
    __int32_t  sum = 0;
    struct node_s* counter = list;

    while (counter) {
        sum += counter->element;
        counter = counter->next_node;
    }

    return sum;
}


__int32_t list_length(struct node_s* list){
    __int32_t  length = 0;
    struct node_s* counter = list;

    do {
        length++;
        counter = counter->next_node;
    } while (counter->next_node != NULL);
    length++;

    return length;
}


struct node_s* list_node_at(__int32_t index, struct node_s* list){ /* mne ne nrav */
    __int32_t counter;
    struct node_s* node_at = NULL;
    struct node_s* node_counter = list;

    for (counter = 0; counter <= index; counter++){
        if (node_counter->next_node == NULL){
            break;
        }
        else {
            if (counter == index){
                node_at = node_counter;
            }
            else{
                node_counter = node_counter->next_node;
            }
        }
    }

    return node_at;
}

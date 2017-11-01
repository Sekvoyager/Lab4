#include <stdio.h>
#include <stdlib.h>
#include "lab.h"

int main(){
    __int32_t i, n, get_n;
    __int32_t min, max;

    struct node_s* list = NULL;

    while (scanf("%d", &i) == 1) {          /*achtung*/
        if (list == NULL){
            list = list_create(i);
        }
        else {
            list_add_front(i, &list);
        }
    }

    printf("Sum is: \n");
    printf("%d\n", list_sum(list));

    scanf("%d", &n);
    get_n = list_get(n, list);
    if (!get_n){
        printf("List is too short\n");
    }
    else {
        printf("Element is: %d\n", get_n);
    }

    /*second part*/

    foreach(list, &print_space);
    printf("\n");
    foreach(list, &print_newline);

    struct node_s* f_list = map(list, &square);
    list_free(f_list);
    printf("\n");
    struct node_s* s_list = map(list, &cube);
    list_free(s_list);

    printf("\n");

    min = foldl(2147483647, &find_smallest, list);
    max = foldl(-2147483647, &find_biggest, list);
    printf("%d", min + max);
    printf("\n");

    map_mut(list, &abs);
    printf("\n");

    struct node_s* n_list = iterate(1, 10, &mul_2);
    foreach(n_list, &print_space);
    free(n_list);
    printf("\n");

    if (save(list, "input.txt")){
        printf("Saving done\n");
    }
    else {
        printf("Error while saving\n");
    }

    if (load(&list, "input.txt")){
        printf("Loading done\n");
    }
    else {
        printf("Error while loading\n");
    }

    if (serialize(list, "input.txt")){
        printf("Serialized\n");
    }
    else {
        printf("Error while serializing\n");
    }

    if (deserialize(&list, "input.txt")){
        printf("Deserialized\n");
    }
    else {
        printf("Error while deserializing\n");
    }

    list_free(list);

    return 0;
}


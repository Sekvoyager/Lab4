#include <stdio.h>
#include <stdlib.h>
#include "lab.h"
#include <stdbool.h>

bool save(struct node_s* lst, const char* filename){
    struct node_s* counter = lst;
    FILE* otp = fopen("input.txt", "w");
    if (!otp){
        return false;
    }
    else {
        while(counter){
            fprintf(otp, "%d ", counter->element);
            counter = counter->next_node;
        }
    }
    fclose(otp);
    return true;
}


bool load(struct node_s** lst, const char* filename){
    int num;
    struct node_s* new_list;
    struct node_s* counter;
    list_free(*lst);
    FILE* inp = fopen(filename, "r");
    if (inp){
        new_list = list_create(fscanf(inp, "%d", &num));
    }
    else{
        return false;
    }
    while(fscanf(inp, "%d", &num) != EOF){
        list_add_back(num, &new_list);
    }
    fclose(inp);

    return true;
}

bool serialize(struct node_s* lst, const char* filename){
    FILE* file=fopen(filename,"wb");
    if(!file) {
        return false;
    }
    struct node_s* counter=lst;
    while(counter){
        (fwrite(&(counter->element), sizeof(int), 1, file));
        counter = counter->next_node;
    }
    fclose(file);

    return true;
}

bool deserialize(struct node_s** lst, const char* filename){
    int num;
    list_free(*lst);
    FILE* file = fopen(filename, "r");
    if (file){
        *lst = list_create(fscanf(file, "%d", &num));
    }
    else{
        return false;
    }
    while(fread(&num, sizeof(int),(size_t)1, file) != 0){
        list_add_back(num, lst);
    }
    fclose(file);

    return true;
}

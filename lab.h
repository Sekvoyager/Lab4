#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

struct node_s{
    __int32_t element;
    struct node_s* next_node;
};

struct node_s* list_create(__int32_t);                                  /* +checked */
struct node_s* list_add_front(__int32_t, struct node_s**);              /* +checked */
struct node_s* list_add_back(__int32_t, struct node_s**);               /* +checked */
__int32_t list_get(__int32_t, struct node_s*);                          /* +checked i krivo */
void list_free(struct node_s*);                                         /* +checked */
__int32_t list_sum(struct node_s*);                                     /* +checked */
__int32_t list_length(struct node_s*);                                  /* checked */
struct node_s* list_node_at(__int32_t, struct node_s*);                 /* checked i krivo */
void foreach(struct node_s*, void(*)(int32_t));                         /* checked */
struct node_s* map(struct node_s*, int32_t(*)(int32_t));                /* checked */
void map_mut(struct node_s*, int32_t(*)(int32_t));                      /* checked */
int32_t foldl(int32_t, int32_t(*)(int32_t, int32_t), struct node_s*);   /* checked */
struct node_s* iterate(int32_t, int32_t, int32_t(*)(int32_t));          /* checked */
void print_space(int32_t);
void print_newline(int32_t);
int32_t square(int32_t);
int32_t cube(int32_t);
int32_t find_smallest(int32_t, int32_t);
int32_t find_biggest(int32_t, int32_t);
int32_t abs(int32_t);
int32_t mul_2(int32_t);
bool save(struct node_s*, const char*);
bool load(struct node_s**, const char*);
bool serialize(struct node_s*, const char*);
bool deserialize(struct node_s**, const char*);

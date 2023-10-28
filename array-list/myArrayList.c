#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ArrayList {
    void **array;
    int size;
    int max_size;
} LIST_t,*LIST;

LIST init_list(int max_size) {
    LIST array = (LIST) malloc(sizeof(LIST_t));
    if(array == NULL) {
        return NULL;
    }
    array->array = NULL;
    array->size = 0;
    array->max_size = max_size;
}

void add(LIST array_list, void *data) {
    if(array_list->size >= array_list->max_size) {
        return;
    }
    if(array_list->size == 0) {
        array_list-> array = (void **) malloc(sizeof(void *));   
    }
    array_list-> array = (void **) realloc(array_list->array, sizeof(void *) * (array_list->size+1));
    
    array_list->array[array_list->size] = data;
    array_list->size++;
}

void insert(LIST array_list, void *data, int index) {
    if(array_list->size >= array_list->max_size) {
        return;
    }
    if(array_list->size == 0) {
        array_list-> array = (void **) malloc(sizeof(void *));   
        return;
    }
    array_list-> array = (void **) realloc(array_list->array, sizeof(void *) * (array_list->size+1) * sizeof(void *));
    
    if(array_list->size == index) {
        array_list->array[index] = data;
        return;
    }
    memmove(array_list->array + index + 1, array_list->array + index, (array_list->size - index) * sizeof(void *));
    array_list->array[index] = data;
    array_list->size++;
}

void *remove_node(LIST array_list, int index) {
    if(array_list->size == 0) {
        return NULL;
    }
    void *deleted_element = array_list->array[index];
    memmove(array_list->array + index, array_list->array + index + 1, (array_list->size - index - 1) * sizeof(void *));
    array_list->array = (void **) realloc(array_list->array,sizeof(void *) * (array_list->size - 1));
    array_list->size -= 1;
    return deleted_element;
}

void update(LIST array_list, void *data, int index) {
    if(array_list->size == 0) {
        return;
    }
    
    free(array_list->array[index]);
    array_list->array[index] = data;
}

int size(LIST array_list) {
    return array_list->size;
}

void clear(LIST array_list) {
    for(int i = 0; i < array_list->size; i++) 
        free(array_list->array[i]);
    free(array_list);
}

bool contains(LIST array_list, void *data) {
    for(int i = 0; i < array_list->size; i++) {
        if(array_list->array[i] == data)
            return true;
    }
    return false;
}

void *get_index(LIST array_list, int index) {
    if(array_list->size == 0 || index >= array_list->size)
        return NULL;
    return array_list->array[index];
}

void expand(LIST array_list) {
    array_list->max_size *= 2; 
}

void shrink(LIST array_list) {
    if(array_list->size < 2) {
        if(array_list->size != 0) 
            clear(array_list);
        return;
    }     
    for(int i = array_list->size / 2; i < array_list->size; i++) {
        free(array_list->array[i]);
    }
    
    array_list->size = array_list->size / 2;
}

void print(LIST array_list, char *type) {
    for(int i = 0; i < array_list->size; i++) {
        if(strcmp(type, "int") == 0)
            printf("%d ",*((int *)(array_list->array[i])));
        else if(strcmp(type, "string") == 0) {
            printf("%s ",((char *)(array_list->array[i])));
        } else if(strcmp(type, "double") == 0) {
            printf("%lf ",*((double *)(array_list->array[i])));
        } else {
            printf("\n");
            return;
        }
    }
    printf("\n");

}

int *p_int(int data) {
    int *value = (int *) malloc(sizeof(int));
    *value = data;
    return value;
}

int main() {
    LIST array_list = init_list(500);
    int *data = p_int(10);
    add(array_list, (void *) data);
    print(array_list,"int");
    data = p_int(15);
    add(array_list, (void *) data);
    print(array_list,"int");
    data = p_int(20);
    insert(array_list, (void *) data, 1);
    print(array_list,"int");
    remove_node(array_list, 1);
    print(array_list,"int");
    data = p_int(40);
    insert(array_list, (void *) data, 0);
    print(array_list,"int");
    printf("%d\n",contains(array_list, data));
    printf("%d\n", size(array_list));
    printf("%d ",*((int *)get_index(array_list, 1)));
    clear(array_list);
    printf("%d ",*((int *)get_index(array_list, 1)));
    
}
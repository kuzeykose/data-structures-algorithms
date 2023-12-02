#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct ArrayList {
    void **array;
    int size;
    int max_size;
} LIST_t,*LIST;

/*
   Development Notes for people who are not familiar with C Language
   - The Malloc function is used to allocate memory for new list initialization. Java, Python, JS languages, etc. make this automatically, so you don't have to allocate in these languages.
   - You have to cascade after every memory allocation and reallocation step.
   - sizeof function helps find the size of the variable to allocate with the correct size.
   - Cascading in print has caught your attention. The reason is that we store data with (void *) data type. This situation allows us to store the data as a generic type. 
   Actually, we only store the address of this variable. If you want to print this void * type address of data, you have to cascade the correct type. This cascading gives you access to data of address. 
   To make this process you should use * character. you can get more information in this link = https://www.w3schools.com/c/c_pointers.php
   - The last things about C are memmove and free functions. There is no garbage collection in c, so you have to free memory using the free function on your own. Memmove function takes three parameters:
      -> first parameter is destination memory address,
      -> second parameter is source memory address that you want to move memory blocks,
      -> last parameter is size. It determines how many bytes to move forward from the source address.

      Example usage => MA is the short name of memory address you allocate it and [] is the memory block if there is no inside it, that means no allocated block. 
          memory allocation is like [MA][MA][MA][MA][MA]
                                     0   1   2   3   4
          when you call memmove like memmove(2, 1, 3), it will move 4 memory blocks after the source(source also included) to destination memory(2. indexed block) . The last version of the memory block is: 
                                    [MA] []  [MA][MA][MA][MA]
                                     0   1   2   3   4
          NOTE!!: after movement, the empty blocks are actually allocated to you. so you can write and read them easily.
       MORE INFO ABOUT MEMMOVE: https://cplusplus.com/reference/cstring/memmove/
*/

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

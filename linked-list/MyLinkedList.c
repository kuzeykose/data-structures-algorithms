#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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


typedef struct NODE_s *NODE;
typedef struct NODE_s {
    NODE next;
    void *data;
} NODE_t[1], *NODE;

typedef struct LINKED_LIST_s {
    NODE head;
} LINKED_LIST_t[1], *LINKED_LIST;

LINKED_LIST init_list() {
    LINKED_LIST list = (LINKED_LIST) malloc(sizeof(LINKED_LIST_t));
    list->head = NULL;
    return list;
}

NODE init_node(void *data) {
    NODE node = (NODE) malloc(sizeof(NODE_t));
    node->next = NULL;
    node->data = data;
    return node;
}

void add(LINKED_LIST list, void *data) {
    if(list == NULL) {
        printf("ERROR: init list!!\n");
        return;
    } 
    
    if(list->head == NULL) {
        list->head = init_node(data);
        return;
    }
    
    NODE new_node = init_node(data);
    NODE current = list->head;

    while(current->next != NULL) {
        current = current->next;
    }
    
    current->next = new_node;
}


void insert(LINKED_LIST list, int index, void *data) {
    if(list == NULL) {
        printf("ERROR: init list!!\n");
        return;
    } 
    
    if(list->head == NULL) {
        if(index != 0){
            printf("Out of bound!!\n");
            return;
        }
        list->head = init_node(data);
        return;
    }
    
    NODE new_node = init_node(data);
    NODE current = list->head;
    
    if(index == 0) {
        current->next = list->head;
        list->head = current;
        return;
    }
    int counter = 0;
    while(current->next != NULL && counter+1 < index) {
        current = current->next;
        counter++;
    }
    
    if(current->next == NULL && index != counter + 1) {
        printf("Out of bound!!\n");
        return;
    }
    NODE tmp = current->next;
    current->next = new_node;
    new_node->next = tmp;
}

void removeIndex(LINKED_LIST list, int index) {
    if(list == NULL) {
        printf("ERROR: init list!!\n");
        return;
    } 
    
    if(list->head == NULL) {
        printf("ERROR: list is empty!!\n");
        return;
    }
    
    NODE current = list->head;
    
    if(index == 0) {
        list->head = list->head->next;
        return;
    }
    int counter = 0;
    while(current->next != NULL && counter+1 < index) {
        current = current->next;
        counter++;
    }
    
    if(current->next == NULL && index != counter + 1) {
        printf("Out of bound!!\n");
        return;
    }
    NODE tmp = current->next;
    current->next = tmp->next;
    free(tmp);
}

bool contains(LINKED_LIST list, void *data) {
    if(list == NULL) {
        printf("ERROR: init list!!\n");
        return false;
    } 
    
    if(list->head == NULL) {
        printf("ERROR: list is empty!!\n");
        return false;
    }
    
    NODE current = list->head;
    while(current != NULL) {
        if(current->data == data) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void print_list(LINKED_LIST list) {
    if(list == NULL) {
        printf("ERROR: init list!!\n");
        return;
    } 
    
    if(list->head == NULL) {
        printf("ERROR: list is empty!!\n");
        return;
    }
    
    NODE current = list->head;
    while(current != NULL) {
        printf("%d", *((int *)(current->data)));
        if(current->next != NULL)
            printf("->");
        current = current->next;
    }
}
int main()
{
    LINKED_LIST list = init_list();
    return 0;
}

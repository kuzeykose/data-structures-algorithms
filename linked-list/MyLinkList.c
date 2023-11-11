/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

/* 
 *Name: Jeongyeon Park
 * E-mail: jeongyeo@uoguelph.ca
 * Program name: memcheck.c
 * ID: 1006554
 * Created on February 21, 2018
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*declarations*/
int memcheck_main();

char *strdup2(char *str){
  char *new;
  new = malloc( strlen(str)+1 );
  if(new)
      strcpy( new, str );
  return new;
}

struct node{
    void *address;
    char *file;
    int line;
    struct node *next;
};

/*point to the first node in linked list*/
struct node *head = NULL;

void print_list(struct node *list){
    /*print list*/
    while(list){
        printf("memcheck error:  memory address %p which was allocated in file \"%s\", line %d, was never freed\n", list->address, list->file, list->line);
        list = list->next;
    }
}

void *memcheck_malloc(size_t size, char *file, int line){
    void *temp;
    struct node *new = (struct node*) malloc(sizeof(struct node));
    temp = malloc(size);
    /*fill data*/
    new->address = temp;
    new->file = strdup2(file);
    new->line = line;
    new->next = head;
    /*new head*/
    head = new;
    return temp;
}

void *memcheck_calloc(size_t nitems, size_t size, char *file, int line){
    void *temp;
    struct node *new = (struct node*) malloc(sizeof(struct node));
    temp = calloc(nitems, size);
    new->address = temp;
    new->file = strdup2(file);
    new->line = line;
    new->next = head;
    head = new;
    return temp;
}

void *memcheck_realloc(void *ptr, size_t newsize, char *file, int line){
    void *temp;
    struct node *list = head;
    
    temp = realloc(ptr, newsize);

    /*Check if realloc returns the same address*/
    while(list){
        if(list->address == ptr){
            list->address = temp;
            list->file = strdup2(file);
            list->line = line;
        }
        list = list->next;
    }
    return temp;
}

void memcheck_free(void *ptr, char *file, int line){
    struct node *list = head, *prev = head;
    /*update head if ptr = head->address*/
    if(head->address == ptr){
        head = head->next;
        free(ptr);
        free(head);
        return;
    }
    /*update head in the linked list*/
    while(list){
        if(list->address == ptr){
            prev->next = list->next;
            free(ptr);
            free(list);
            return;
        }
        prev = list;
        list = list->next;
    }
    /*error message if not in linked list*/
    printf("memcheck error:  attempting to free memory address %p in file \"%s\", line %d.\n", ptr, file, line);
}
    
int main(){
    memcheck_main();
    print_list(head);
    return 0;
}


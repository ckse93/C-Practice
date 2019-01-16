#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
Linked List practice
addNode
print_nodes
sort_nodes
*/

int stuff = 0;
pthread_mutex_t mutex;

struct Node {
    int data;
    struct Node *next;
};

void addNode (struct Node *target, int input){
    struct Node *newNode = malloc(sizeof (struct Node));
    newNode->next = target->next;
    newNode->data = input;
    target->next = newNode;
}

void sortedAdd(struct Node *target, int data){
    struct Node *newNode = malloc(sizeof(struct Node));
    if (target == NULL){
        printf ("empty list\n");
        return;
    }
    else {
        //write this later. i need some sleep
    }
}

void print_nodes (struct Node *target){
    printf("\n");
    struct Node *curr = target;
    while (curr !=NULL){
        printf (" [%d] ", curr->data);
        curr = curr->next;
    }
}

int main (){
struct Node *head;
head->data = NULL;
head->next = NULL;

while(1){
    int option;
    printf("enter 1 for add, 2 for print, 0 for exit\n");
    scanf("%d", &option);
    printf("%d", option);
    if(option == 0){
        break;
    }
    else if (option == 1){            //add function call
        int data;
        printf ("enter value to add onto the existing node(s) : ");
        scanf("%d", &data);
        addNode(head, data);
    }
    else if (option == 2){
        print_nodes(head->next);
    }
    else{
        printf("please select again\n\n");
    }
}
return 0;
}

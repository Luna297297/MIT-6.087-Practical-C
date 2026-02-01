#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data; //playload
    struct node * next;
}node;

node * nalloc(int data){    //create new element
    node *new = malloc(sizeof(*new)); //create a memory space for the new node
    if(new == NULL) return NULL; 

    new->data = data;
    new->next = NULL;

    return new;
}

node * addfront(node *head, int data){
    node *new = nalloc(data);
    if (new==NULL) return head;

    new->next = head;

    return new;
}


node * addback(node *head, int data){
    node *new = nalloc(data);
    if(new==NULL) return head;

    node *cur = head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    cur->next = new;
    return head;
}

node * find(node *head, int data){
    node *cur = head;
    while(cur != NULL){
        if(cur->data == data) {
            return cur;
        } else{
            cur = cur->next;
        }
    }
    return NULL;
}

node * delnode(node * head, node * pelement){
    node * cur = head;
    //Situation1: pelement == head
    if(head == pelement){
        if(head->next == NULL){
            free(head); //這邊需要free cur嗎？我認為不需要，因為他只是指向head，並沒有malloc一塊記憶體位址給他？
            head = NULL;
            return NULL; 
        }else{
            cur = head->next;
            free(head);
            head=NULL;
            return cur;
        }
    }
    //Situation2: pelement != head
    while(cur != NULL){
        if(cur->next == pelement){
            cur->next = pelement->next;
            free(pelement);
            pelement = NULL;
        }else{
            cur = cur->next;
        }
        return head;
    }
    return head;
}

void freelist(node *head){
    node *cur = head;
    node *temp;
    while(cur != NULL){ //counting how many nodes are there in the linked list
        temp=cur->next;
        free(cur);
        cur = temp;
    }
}

void display(node *head){
    if (head == NULL){
        printf("No element in this linked list.\n");
    }
    node *cur = head;
    while(cur != NULL){
        printf("The element of the node is: %d\n", cur->data);
        cur = cur->next;
    }
}

int main(){
     
    node *head = nalloc(10);

    head = addfront(head, 33);
    printf("---First Time---\n");
    display(head);
    printf("\n");

    head = addback(head, 100);
    printf("---Second Time---\n");
    display(head);
    printf("\n");

    node *p = find(head, 10);
    head = delnode(head, p);
    printf("---Third Time---\n");
    display(head);
    printf("\n");

    freelist(head);
    printf("---Fourth Time---\n");
    head = NULL;
    display(head);
    printf("\n");

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "QueueLinkedList.h"

struct n {
    int data;
    n* next;
};

typedef n node;
node* root = NULL;
node* son = NULL;

void enque(int x){
    if(root == NULL){
        root = (node*) malloc(sizeof(node));
        root -> data = x;
        root -> next = NULL;
        son = root;
    } else {
    son -> next = (node*) malloc(sizeof(node));
    son -> next -> data = x;
    son = son -> next;
    son -> next = NULL;
}}

int deque(){
    if(root == NULL){
        printf("Liste bos.");
        return -1;
    }
    int rvalue = root -> data;
    node* temp = root;
    root = root -> next;
    free(temp);
    return rvalue;
}

main(int argc, char const *argv[])
{
    
  
}
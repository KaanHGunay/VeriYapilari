#include <stdio.h>
#include <stdlib.h>
#include "StackLinkedList.h"

void bastir(node* root){
    while(root != NULL){
        printf("%d\n", root -> data);
        root = root -> next;
    }
}

int pop(node* root){
    if(root == NULL){
        printf("Stack bos");
        return -1;
    }

    if(root -> next == NULL){ //eleman sayısı ikiden az ise
        int rvalue = root -> data;
        free(root);
        return rvalue;
    }

    node* iter = root;
    while(iter -> next -> next != NULL){ //sondan bir önceki elemana git
        iter = iter -> next;
    }
    
    node* temp = iter -> next; //silicek data
    int rvalue = temp -> data; //silinecek datanın verisi
    iter -> next = NULL;
    free(temp); //sil
    return rvalue;
}

node* push(node* root, int a){
    if(root == NULL){
        root = (node*) malloc(sizeof(node));
        root -> data = a;
        root -> next = NULL;
        return root;
    }

    node* iter = root;
    while(iter -> next != NULL){
        iter = iter -> next;
    }
    node* temp = (node*) malloc(sizeof(node));
    temp -> data = a;
    temp -> next = NULL;
    iter -> next = temp;
    return root;
}

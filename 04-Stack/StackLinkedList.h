#ifndef StackLinkedList
#define StackLinkedList

struct n{
    n* next;
    int data;
};
typedef n node;
void bastir(node*);
int pop(node*);
node* push(node*, int);

#endif

#ifndef DoublyLinkedList
#define DoublyLinkedList

struct n{
    int x;
    n* next;
    n* prev;
};

typedef n node;
void bastir(node*);
node* siraliekle(node*, int);
node* sil(node*, int);

#endif
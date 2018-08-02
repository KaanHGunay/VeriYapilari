#include <stdio.h>
#include <stdlib.h>


struct n
{
    int x;
    n* next;
};

typedef n node;


int main(int argc, char const *argv[])
{
    node* root;
    root = (node*)malloc(sizeof(node));
    root->x = 10;
    root->next = (node*)malloc(sizeof(node));
    root->next->x = 20;
    node* iter = root;

    printf("%d",iter->x);
    iter = iter->next;
    printf("%d",iter->x);
}

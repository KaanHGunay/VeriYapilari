#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

int main(int argc, char const *argv[])
{
    node* root =  NULL;
    root = siraliekle(root, 400);
    root = siraliekle(root, 40);
    root = siraliekle(root, 4);
    root = siraliekle(root, 450);
    root = siraliekle(root, 50);

    bastir(root);
    printf("\n");

    root = sil(root, 9); //olmayan eleman
    root = sil(root, 4); //ilk eleman
    root = sil(root, 50); //ortada bulunan eleman
    root = sil(root, 450); //sondaki eleman

    bastir(root);
}

#include <stdio.h>
#include <stdlib.h>
#include "StackLinkedList.h"

main(int argc, char const *argv[])
{
    node* s = NULL;
    s = push(s, 10);
    s = push(s, 20);
    bastir(s);
    printf("%d -> ", pop(s));
    s = push(s, 30);
    printf("%d -> ", pop(s));
    printf("%d -> ", pop(s));
}

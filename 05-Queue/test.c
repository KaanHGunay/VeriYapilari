#include <stdio.h>
#include <stdlib.h>
#include "QueueArray.h"

main(int argc, char const *argv[]){
    queue* q = tanimla();
    for(int i = 0; i < 20; i++)
    {
        enque(q, i);
    }
    
    for(int i = 0; i < 12; i++)
    {
        printf("%d ", deque(q));
    }

    for(int i = 0; i < 20; i++)
    {
        enque(q, i);
    }
    
    for(int i = 0; i < 30; i++)
    {
           printf("%d ", deque(q)); 
    }
    
}

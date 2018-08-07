#include <stdio.h>
#include <stdlib.h>
#include "QueueArray.h"

queue* tanimla(){
    queue* q = (queue*) malloc(sizeof(queue));
    q -> dizi = NULL;
    q -> sira = 0;
    q -> sirabasi = 0;
    q -> boyut = 2;
    return q;
}

void toparla(queue* q){
    if(q -> sirabasi == 0){
        return;
    }
    
    for(int i = 0; i < q -> boyut; i++){
        q -> dizi[i] = q -> dizi[i + q -> sirabasi];
    }

    q -> sira -= q -> sirabasi;
    q -> sirabasi = 0;    
}

int deque(queue* q){
    if(q -> sira == q -> sirabasi){
        printf("Sira bos");
        return -1;
    }

    if(q -> sira - q -> sirabasi <= q -> boyut / 4){ //eleman sayısı boyutun çeyreğinden az ise diziyi küçült
        int* dizi2 = (int*) malloc(sizeof(int) * q -> boyut / 2);        
        for(int i = 0; i < q -> sira - q -> sirabasi; i++){
            dizi2[i] = q -> dizi[q -> sirabasi + i];
        }
        q -> sira -= q -> sirabasi;
        q -> sirabasi = 0;
        free(q -> dizi);
        q -> boyut /= 2;
        q -> dizi = dizi2;  
    }

    return q -> dizi[q -> sirabasi++];
}

void enque(queue* q, int a){
    if(q -> dizi == NULL){
        q -> dizi = (int*) malloc(sizeof(int) * 2);
    }

    if(q -> sira >= q -> boyut){
        q -> boyut *= 2;
        int* dizi2 = (int*) malloc(sizeof(int) * q -> boyut);

        for(int i = 0;i < q -> boyut / 2;i++){
            dizi2[i] = q -> dizi[i];
        }

        free(q -> dizi);
        q -> dizi = dizi2;
    }

    q -> dizi[q -> sira++] = a;
}

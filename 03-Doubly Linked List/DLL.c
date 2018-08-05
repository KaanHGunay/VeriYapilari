#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    n* next;
    n* prev;
};

typedef n node;

void bastir(node* r){
    while(r != NULL){
        printf("%d ", r -> x);
        r = r -> next;
    }    
}

node* siraliekle(node* r, int x){
    if(r == NULL){ //Doubly Linked list boş ise
        r = (node*)malloc(sizeof(node));
        r -> next = NULL;
        r -> prev = NULL;
        r -> x = x;
        return r;
    }
    if(r -> x > x){ //Doubly Linked listte ilk elemandan küçük elemanın eklenmesi durumu
            node* temp = (node*)malloc(sizeof(node));
            temp -> x = x;
            temp -> next = r;
            r -> prev = temp;
            return temp;
    }
    node* iter = r;
    while(iter -> next != NULL && iter -> next -> x < x){
        iter = iter -> next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> prev = iter;
    //Eğer listenin sonuna gelindiyse NULL değerinin prev parametresi bulunmayacağından kontrollü şekilde ekleme yapılmaktadır.
    if(temp -> next != NULL){
        temp -> next -> prev = temp;
    }
    temp -> x = x;
    return r;
}

node* sil(node* r, int x){
    node* temp;
    node* iter = r;

    if(r -> x == x){ //ilk eleman silinecekse
        temp = r;
        r = r -> next;
        free(temp);
        return r;
    }

    while(iter -> next != NULL && iter -> next -> x != x){
        iter = iter -> next;
    }

    if(iter -> next == NULL){
        printf("Sayı Bulunamadı.\n");
        return r;
    }
    temp = iter -> next;
    iter -> next = iter -> next -> next; //silinecek olan nodu atlayarak önceki noda bağlıyoruz.
    free(temp);
    if(iter -> next != NULL){
        iter -> next -> prev = iter;
    }
    return r;
}

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

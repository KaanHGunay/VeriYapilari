#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    n* next;
};

typedef n node;

void bastir(node* r){
    while(r != NULL){
        printf("%d ", r -> x);
        r = r -> next;
    }    
}

void ekle(node* r, int x){
    while(r -> next != NULL){
        r = r -> next;
    }
    r -> next = (node*)malloc(sizeof(node));
    r -> next -> x = x;
    r -> next -> next = NULL;
}

node* siraliekle(node* r, int x){
    if(r == NULL){ //Linked list boş ise
        r = (node*)malloc(sizeof(node));
        r -> next = NULL;
        r -> x = x;
        return r;
    }
    if(r -> x > x){ //Linked listte ilk elemandan küçük elemanın eklenmesi durumu
            node* temp = (node*)malloc(sizeof(node));
            temp -> x = x;
            temp -> next = r;
            r = temp;
            return temp;
    }
    node* iter = r;
    while(iter -> next != NULL && iter -> next -> x < x){
        iter = iter -> next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
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

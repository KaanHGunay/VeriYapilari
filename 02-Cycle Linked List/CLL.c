#include <stdio.h>
#include <stdlib.h>

struct n{
    int x;
    n* next;
};

typedef n node;

void bastir(node* r){
    //Bütün daireyi dolaşacak iter değeri
    node* iter = r;

    //İlk değerim root değerine eşit olması nedeniyle ilk bastırma işlemi manuel olarak yapıldı
    printf("%d ", iter -> x);
    iter = iter -> next;

    //Diğer tüm elemanları bastır
    while(iter != r){
        printf("%d ", iter -> x);
        iter = iter -> next;
    }    
}

void ekle(node* r, int x){
    node* iter = r;
    while(iter -> next != r){
        iter = iter -> next;
    }
    iter -> next = (node*)malloc(sizeof(node));
    iter -> next -> x = x;
    iter -> next -> next = r;
}

node* siraliekle(node* r, int x){
    if(r == NULL){ //liste boş ise
        r = (node*)malloc(sizeof(node));
        r -> next = r;
        r -> x = x;
        return r;
    }

    if(r -> x > x){ //ilk elemana değiştirilecekse
            node* temp = (node*)malloc(sizeof(node));
            temp -> x = x;
            temp -> next = r;
            r = temp;

            //son elemana git
            node* iter = r;
            while(iter -> next != r){
                iter = iter -> next;
            }

            //son elemanın gösteridiği root değerini yeni değer ile değiştir
            iter -> next = temp;
            return temp;
    }

    node* iter = r;
    while(iter -> next != r && iter -> next -> x < x){
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
        while(iter -> next != r){
            iter = iter -> next;
        }
        iter -> next = r -> next;
        free(r);
        temp = r;
        return iter -> next;
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

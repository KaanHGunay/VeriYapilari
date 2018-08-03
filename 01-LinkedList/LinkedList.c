#include <stdio.h>
#include <stdlib.h>

//linked liste oluşturmak için data kısmı ve diğer elemanı gösteren pointer ataması
struct n
{
    //Data bölümü
    int x;
    //Pointer bölümü
    n* next;
};

typedef n node;

//Listenin tamamını bastıracak fonksiyon
void bastir(node* r){    
    while(r != NULL){
        printf("%d ", r -> x);
        r = r -> next;
    }    
}

int main(int argc, char const *argv[])
{
    //İlk düğümü göstermek için oluşturulan root
    node* root;
    root = (node*)malloc(sizeof(node));
    root -> x = 10;
    root -> next = (node*)malloc(sizeof(node));
    root -> next -> x = 20;
    root -> next -> next = (node*)malloc(sizeof(node));
    root -> next -> next -> x = 30;
    //Sonda bulunan elemanın gösterdiği pointera NULL değeri atanarak sonuncu olduğunu anlıyoruz
    root -> next -> next -> next = NULL;
    //Listede bulunulan yeri gösterecek olan iterasyon
    node* iter = root;

    printf("%d",iter -> x);
    iter = iter -> next;
    printf("\n%d\n",iter->x);

    iter = root;
    int i = 0;
    while(iter -> next != NULL){
        i++;
        printf("%dinci eleman : %d \n",i,iter->x);
        iter = iter -> next;   
    }
    
    for(int i = 0; i < 5; i++)
    {
        iter -> next = (node*)malloc(sizeof(node));
        iter = iter -> next;
        iter -> x = i * 40;
        iter -> next = NULL;
    }

    bastir(root);
}

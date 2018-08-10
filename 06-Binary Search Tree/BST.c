#include <stdio.h>
#include <stdlib.h>

struct n{
    int data;
    n* sol;
    n* sag;
};
typedef n node;

node* ekle(node* agac, int x){
    if(agac == NULL){
        node* root = (node*) malloc(sizeof(node));
        root -> sol = NULL;
        root -> sag = NULL;
        root -> data = x;
        return root;
    }

    if(agac -> data < x){ //data x değerinden küçük ise recursive şekilde sağa ekle
        agac -> sag = ekle(agac -> sag, x);
        return agac;
    }

    agac -> sol = ekle(agac -> sol, x);
    return agac;
}

void dolas_kucuktenBuyuge(node* agac){
    if(agac == NULL){
        return;
    }

    dolas_kucuktenBuyuge(agac -> sol);
    printf("%d ", agac -> data);
    dolas_kucuktenBuyuge(agac -> sag);
}

void dolas_buyuktenKucuge(node* agac){
    if(agac == NULL){
        return;
    }

    dolas_buyuktenKucuge(agac -> sag);
    printf("%d ", agac -> data);
    dolas_buyuktenKucuge(agac -> sol);
}

int bul(node* agac, int aranan){
    if(agac == NULL){
        return -1; //hata kodu olarak -1
    }

    if(agac -> data == aranan){
        return 1; //aranan değer bulundu
    }

    if(bul(agac -> sag, aranan) == 1){
        return 1; //her sağı kontrol et varsa 1 döndür
    }

    if(bul(agac -> sol, aranan) == 1){
        return 1; //her solu kontrol et varsa 1 döndür
    }

    return -1;
}

int max(node* agac){
    while(agac -> sag != NULL){
        agac = agac -> sag;
    }

    return agac -> data;
}

int min(node* agac){
    while(agac -> sol != NULL){
        agac = agac -> sol;
    }

    return agac -> data;
}

node* sil(node* agac, int x){
    if(agac == NULL){
        return NULL;
    }

    if(agac -> data == x){
        if(agac -> sol == NULL && agac -> sag == NULL){ //agacın sağ ve solu boş ise
            return NULL;
        }

        if(agac -> sag != NULL){ //agacın sağ tarafı dolu ise
            agac -> data = min(agac -> sag);
            agac -> sag = sil(agac -> sag, min(agac -> sag));
            return agac;
        }
        
        //agacın sağı boş solu dolu ise
        agac -> data = max(agac -> sol);
        agac -> sol = sil(agac -> sol, max(agac -> sol));
        return agac;
    }

    if(agac -> data < x){
        agac -> sag = sil(agac -> sag, x);
        return agac;
    }

    agac -> sol = sil(agac -> sol, x);
    return agac;
}

main(int argc, char const *argv[]){
    node* agac = NULL;
    agac = ekle(agac, 56);
    agac = ekle(agac, 200);
    agac = ekle(agac, 26);
    agac = ekle(agac, 190);
    agac = ekle(agac, 213);
    agac = ekle(agac, 18);
    agac = ekle(agac, 28);
    agac = ekle(agac, 12);
    agac = ekle(agac, 24);
    agac = ekle(agac, 17);
    dolas_kucuktenBuyuge(agac);
    printf("\n");
    dolas_buyuktenKucuge(agac);
    printf("\n");
    printf("%d\n", bul(agac, 100));
    printf("%d\n", bul(agac, 200));
    printf("max = %d, min = %d\n", max(agac), min(agac));
    agac = sil(agac, 190);
    agac = sil(agac, 56);
    dolas_buyuktenKucuge(agac);
}

#ifndef QueueArray
#define QueueArray

struct n{
    int* dizi;
    int sira;
    int sirabasi;
    int boyut;
};
typedef n queue;
queue* tanimla();
void toparla(queue*);
int deque(queue*);
void enque(queue*, int);

#endif
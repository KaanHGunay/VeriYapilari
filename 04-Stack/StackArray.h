#ifndef StackArray
#define StackArray

struct s {
    int boyut;
    int tepe;
    int* dizi;
};
typedef s stack;
stack* tanim();
int pop(stack*);
int push(int, stack*);
void bastir(stack*);

#endif
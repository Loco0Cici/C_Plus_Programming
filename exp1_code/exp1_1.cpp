#include <stdio.h>
void swap(int *d1, int *d2);
void swap(int &d1, int &d2);
int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("a:%d, b:%d\n", a, b);
    swap (&a, &b);
    printf("a:%d, b:%d\n", a, b);
    swap (a, b);
    printf("a:%d, b:%d\n", a, b);
    return 0;   
}
void swap(int *d1, int *d2){
    int t = *d1;
    *d1 = *d2;
    *d2 = t;
}
void swap(int &d1, int &d2){
    int t = d1;
    d1 = d2;
    d2 = t;
}
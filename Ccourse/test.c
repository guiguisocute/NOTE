#include <stdio.h>
void swap_singelpoint(int *pa,int *pb){
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void swap_doublepoint(int **ppa,int **ppb){
    int* temp;
    temp = *ppa;
    *ppa = *ppb;
    *ppb = temp;
}



int main(){
    int a = 10, b = 20;
    int a1 = 10, b1 = 20;
    int* pa = &a1;
    int* pb = &b1; 

    swap_singelpoint(&a,&b);
    printf("%d %d\n",a,b);
    swap_doublepoint(&pa,&pb);
    printf("%d %d\n",*pa,*pb);
    printf("%d %d",a1,b1);

    return 0;

}


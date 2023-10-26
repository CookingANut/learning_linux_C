#include <stdio.h>
#include <stdlib.h>
#define N 20 

int a[N];

void gen_random(int upper_bound){
    int i;
    for(i=0;i < N;i++){
        a[i] = rand() % upper_bound;
    }
}

int main(void){
    int i,j, histogram[10] = {0};
    gen_random(10);
    for(i=0;i<N;i++)
        ++histogram[a[i]];

    for(i=0;i<10;i++)
        printf("%d ",i);

    printf("\n");

    for(j=0;j<N;j++){
        for(i=0;i<10;i++){
            if(histogram[i] > 0){
                printf("* ");
                histogram[i]--;
            }else{
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}
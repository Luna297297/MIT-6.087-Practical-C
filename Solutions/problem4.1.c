#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shift_element(int *, int *);
void insertion_sort(int *, int);

int main(){
    int v[] = {2, 4, 1, 3, 5, 9, 6, 10, 8, 7};
    int len = sizeof(v)/sizeof(v[0]);
    int *base = (int *)malloc(sizeof(v));
    if (!base) return 1;

    memcpy(base, v, sizeof(v));

    insertion_sort(base, len);

    printf("{");
    for(int i=0; i<len; i++){
        printf("%d", *(base+i));
        if(i < len-1) printf(", ");
        }
    printf("}\n");

    free(base);
    base = NULL;

    return 0;
}

void shift_element(int *p, int *base){
    int temp = *p;
    for(; p>base && temp < *(p-1); p--){ //檢查邊界條件
        *p = *(p-1);
    }
    *p = temp;
}

void insertion_sort(int *base, int len){
    for(int i=1; i<len; i++){
        int *p = base+i;
        if(*p < *(p-1)){
            shift_element(p, base);
        }
    }
}
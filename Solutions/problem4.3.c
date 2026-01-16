#include <stdio.h>

void shift_element_gap(int *, int *, int);
void shell_sort(int *, int);

int main(){
    int v[] = {1, 22, 45, 3, 7, 0, 11, 2, 55, 99, 193, 21, 444, 378, 39};
    int len = sizeof(v)/sizeof(v[0]);
    int * base = v;
    
    shell_sort(base, len);

    printf("---After Shell Sort---\n");
    printf("{");
    for(int i=0; i<len; i++){
        if(base+i != base+len-1){
            printf("%d, ", *(base+i));
        }else{
            printf("%d}", *(base+i));
        }
    }
    return 0;
}


void shift_element_gap(int *cur, int *base, int gap){
    //Shift the current element backward by 'gap' if the predecessor is larger.

    int temp = *cur;
    while(cur-gap >= base && *(cur-gap) > temp){
        *cur = *(cur-gap);
        cur -= gap;
    }
    *cur =temp;
}

void shell_sort(int *base, int len){
    
    unsigned int gap;


    for(gap = len/2; gap > 0; gap /= 2){

        for(int *cur = base+gap; cur < base+len; cur++){
            //Scan through the array from 'base+gap' to the end.
            if(*(cur-gap) > *cur){
                shift_element_gap(cur, base, gap);
            }
        }
    }
}
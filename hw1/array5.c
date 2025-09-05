#include <stdio.h>
#include <stdlib.h>

void temp(int i) {
    int a[2];
    int b[3];
    int *c;
    int *d;
    c = (int *)malloc(sizeof(int) * 4);
    d = (int *)malloc(sizeof(int) * 5);

    printf("Address of array a: %p\n", (void*)a);
    printf("Address of array b: %p\n", (void*)b);
    printf("Address of array c: %p\n", (void*)c);
    printf("Address of array d: %p\n", (void*)d);
    
    free(c);
    free(d);
    printf("\n");
}

int main() {
    printf("=== ARRAY ADDRESSES ===\n\n");
    
    
    temp(0);
    
    return 0;
}
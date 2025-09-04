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
    
    // Call temp function multiple times to show stack behavior
    printf("Calling temp() function 3 times to observe address patterns:\n\n");
    
    temp(0);
    
    // printf("=== OBSERVATIONS ===\n");
    // printf("• Arrays 'a' and 'b' are on the STACK - addresses change between function calls\n");
    // printf("• Arrays 'c' and 'd' are on the HEAP - addresses are typically increasing\n");
    // printf("• Stack addresses are usually much higher than heap addresses\n");
    // printf("• Stack variables (a, b, &c, &d) get reused in each function call\n");
    // printf("• Heap allocations (c, d) get new addresses each time\n");
    
    return 0;
}
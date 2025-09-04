#include <stdio.h>
#include <stdlib.h>

struct s2 {
    float a;
    int b;
};

struct s1 {
    int c;
    struct s2 **d;
};

struct s1 x[5];

int main() {
    struct s2 inst = {1.5f, 42};
    
    struct s2 *ptr_array[1];
    ptr_array[0] = &inst;
    
    x[2].d = ptr_array;
    
    int *address_of_b = &(x[2].d[0]->b);
    
    printf("Address of b via third element: %p\n", (void*)address_of_b);
    printf("Value of b: %d\n", *address_of_b);
    
    return 0;
}
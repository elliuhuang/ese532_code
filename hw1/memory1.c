#include <stdio.h>
#include <stdlib.h>

int main() {
    // Stack variables 
    int x = 20;                    
    int *ptr_to_x = &x;    
    
    // Heap variables
    int *heap_single = malloc(sizeof(int));
    *heap_single = 50;            
    
    int *heap_array = malloc(3 * sizeof(int));
    heap_array[0] = 5;            
    heap_array[1] = 6;           
    heap_array[2] = 7;            
    
    // Stack pointers to heap allocations
    int *ptr_to_heap_array = heap_array;    
    int *ptr_to_heap_single = heap_single;  

    printf("=== MEMORY LAYOUT ANALYSIS ===\n\n");
    
    printf("STACK VARIABLES:\n");
    printf("x address:                  %p, value: %d\n", 
           (void*)&x, x);
    printf("ptr_to_x address:           %p, value: %p, points to: %d\n", 
           (void*)&ptr_to_x, (void*)ptr_to_x, *ptr_to_x);
    printf("ptr_to_heap_array address:  %p, value: %p, points to: %d\n", 
           (void*)&ptr_to_heap_array, (void*)ptr_to_heap_array, *ptr_to_heap_array);
    printf("ptr_to_heap_single address: %p, value: %p, points to: %d\n", 
           (void*)&ptr_to_heap_single, (void*)ptr_to_heap_single, *ptr_to_heap_single);
    
    
    
    printf("\nHEAP VARIABLES:\n");
    printf("heap_single address:        %p, value: %d\n", 
           (void*)heap_single, *heap_single);
    printf("heap_array[0] address:      %p, value: %d\n", 
           (void*)&heap_array[0], heap_array[0]);
    printf("heap_array[1] address:      %p, value: %d\n", 
           (void*)&heap_array[1], heap_array[1]);
    printf("heap_array[2] address:      %p, value: %d\n", 
           (void*)&heap_array[2], heap_array[2]);
    
    printf("\nPOINTER CHAIN:\n");
    printf("ptr_to_x -> x: %d \n", **(&ptr_to_x));
    printf("ptr_to_heap_single -> heap: %d \n", **(&ptr_to_heap_single));
    printf("ptr_to_heap_array -> heap[0]: %d\n", **(&ptr_to_heap_array));
    
    // Clean up heap memory
    free(heap_single);
    free(heap_array);
    
    return 0;
}
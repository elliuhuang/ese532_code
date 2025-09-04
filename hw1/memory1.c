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
    
    printf("\nADDRESS DIFFERENCES ANALYSIS:\n");
    printf("Difference between consecutive stack pointers: %ld bytes\n", 
           (char*)&ptr_to_x - (char*)&ptr_to_heap_array);
    printf("Difference between consecutive heap array elements: %ld bytes\n", 
           (char*)&heap_array[1] - (char*)&heap_array[0]);
    
//     printf("\nVERIFICATION:\n");
//     // Compare variables declared in order to see stack growth within this frame
//     printf("Stack variable order (by declaration): ptr_to_heap_single < ptr_to_heap_array < ptr_to_x < x\n");
//     printf("Stack addresses show: variables declared later get higher addresses in this frame\n");
//     printf("This is normal for stack frames - the stack grows downward between function calls,\n");
//     printf("but within a frame, later variables may get higher addresses.\n");
//     printf("Heap grows: %s\n", 
//            (heap_single < heap_array) ? "upward (normal)" : "downward (unusual)");
    
    printf("\nPOINTER CHAIN VERIFICATION:\n");
    printf("ptr_to_x -> x: %d (should be 20)\n", **(&ptr_to_x));
    printf("ptr_to_heap_single -> heap: %d (should be 50)\n", **(&ptr_to_heap_single));
    printf("ptr_to_heap_array -> heap[0]: %d (should be 5)\n", **(&ptr_to_heap_array));
    
    // Clean up heap memory
    free(heap_single);
    free(heap_array);
    
    return 0;
}
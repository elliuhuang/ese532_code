#include <stdio.h>

int main() {
    int a[2][4] = {{10, 20, 30, 40}, {50, 60, 70, 80}};
    
    printf("=== PART 1: Array of Pointers ===\n");
    
    int *ptr_array[2];
    ptr_array[0] = a[0];  // Points to first row 
    ptr_array[1] = a[1];  // Points to second row 
    
    printf("Original 2D array addresses and values:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 4; j++) {
            printf("a[%d][%d] at %p = %d\n", i, j, (void*)&a[i][j], a[i][j]);
        }
    }
    
    printf("\nArray of pointers addresses and values:\n");
    printf("ptr_array[0] at %p points to %p\n", (void*)&ptr_array[0], (void*)ptr_array[0]);
    printf("ptr_array[1] at %p points to %p\n", (void*)&ptr_array[1], (void*)ptr_array[1]);
    
    printf("\nPrinting 2D array contents using array of pointers:\n");
    for(int i = 0; i < 2; i++) {
        printf("Row %d: ", i);
        for(int j = 0; j < 4; j++) {
            printf("%d ", ptr_array[i][j]);
        }
        printf("\n");
    }
    
    printf("\n=== PART 2: Double Pointer ===\n");
    
    int **double_ptr = ptr_array;  // Points to address of ptr_array
    
    printf("double_ptr at %p points to %p\n", (void*)&double_ptr, (void*)double_ptr);
    printf("double_ptr[0] (same as ptr_array[0]) points to %p\n", (void*)double_ptr[0]);
    printf("double_ptr[1] (same as ptr_array[1]) points to %p\n", (void*)double_ptr[1]);
    
    printf("\nPrinting 2D array contents using double pointer:\n");
    for(int i = 0; i < 2; i++) {
        printf("Row %d: ", i);
        for(int j = 0; j < 4; j++) {
            printf("%d ", double_ptr[i][j]);  // Using double pointer to access elements
        }
        printf("\n");
    }
    
    printf("\n=== VERIFICATION ===\n");
    printf("Verifying all three methods give same results:\n");
    printf("Element a[1][2] (should be 70):\n");
    printf("  Using 2D array: a[1][2] = %d\n", a[1][2]);
    printf("  Using array of pointers: ptr_array[1][2] = %d\n", ptr_array[1][2]);
    printf("  Using double pointer: double_ptr[1][2] = %d\n", double_ptr[1][2]);
    
    return 0;
}
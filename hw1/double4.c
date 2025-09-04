#include <stdio.h>

int main() {
    double a[] = {3.14, 2.71};
    
    printf("=== DOUBLE ARRAY AS BYTES ===\n");
    printf("Total array size: %zu bytes\n", sizeof(a));
    
    unsigned char *bytes = (unsigned char*)a;
    
    printf("\nByte representation:\n");
    for(int i = 0; i < sizeof(a); i++) {
        printf("Byte %2d: 0x%02X \n", i, bytes[i]);
    }
    
    printf("\nGrouped by array elements:\n");
    printf("a[0] = %.2f (bytes 0-7):\n", a[0]);
    for(int i = 0; i < 8; i++) {
        printf("  Byte %d: 0x%02X\n", i, bytes[i]);
    }
    
    printf("\na[1] = %.2f (bytes 8-15):\n", a[1]);
    for(int i = 8; i < 16; i++) {
        printf("  Byte %d: 0x%02X\n", i, bytes[i]);
    }
    
    return 0;
}
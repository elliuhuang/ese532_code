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
    
    return 0;
}
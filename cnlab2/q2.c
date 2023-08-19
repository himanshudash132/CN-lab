

#include <stdio.h>

int main() {
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    // Extracting individual bytes
    unsigned char byte1 = (num & 0xFF);
    unsigned char byte2 = ((num >> 8) & 0xFF);
    unsigned char byte3 = ((num >> 16) & 0xFF);
    unsigned char byte4 = ((num >> 24) & 0xFF);

    // Printing the content of the variables
    printf("Byte 1: 0x%02X\n", byte1);
    printf("Byte 2: 0x%02X\n", byte2);
    printf("Byte 3: 0x%02X\n", byte3);
    printf("Byte 4: 0x%02X\n", byte4);

    return 0;
}
    
    

    

// Write a C program to extract each byte from a given number and store them in
// separate character variables and print the content of those variables.

#include <stdio.h>

int main()
{

    unsigned int num = 0x12899708;

    // Extract each byte
    unsigned char byte1 = (num >> 24) & 0xFF;
    unsigned char byte2 = (num >> 16) & 0xFF;
    unsigned char byte3 = (num >> 8) & 0xFF;
    unsigned char byte4 = num & 0xFF;

    printf("Number: 0x%X\n", num);

    printf("Byte 1: 0x%X\n", byte1);
    printf("Byte 2: 0x%X\n", byte2);
    printf("Byte 3: 0x%X\n", byte3);
    printf("Byte 4: 0x%X\n", byte4);

    return 0;
}

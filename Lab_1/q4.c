// Write a C Program to enter a number and store the number across the
// following structure and print the content of each member of the structure.
// Then aggregate each member of the structure to form the original number and
// print the same.

#include <stdio.h>
#include <string.h>

// Define the structure
struct pkt
{
    char ch1;
    char ch2[2];
    char ch3;
};

int main()
{

    unsigned int num;

    printf("Enter a 4-byte number:");
    scanf("%u", &num);

    struct pkt packet;

    packet.ch1 = (num >> 24) & 0xFF;
    packet.ch2[0] = (num >> 16) & 0xFF;
    packet.ch2[1] = (num >> 8) & 0xFF;
    packet.ch3 = num & 0xFF;

    printf("Content of the structure members:\n");
    printf("ch1: 0x%X\n", (unsigned char)packet.ch1);
    printf("ch2[0]: 0x%X\n", (unsigned char)packet.ch2[0]);
    printf("ch2[1]: 0x%X\n", (unsigned char)packet.ch2[1]);
    printf("ch3: 0x%X\n", (unsigned char)packet.ch3);

    unsigned int aggregated_num = ((unsigned char)packet.ch1 << 24) |
                                  ((unsigned char)packet.ch2[0] << 16) |
                                  ((unsigned char)packet.ch2[1] << 8) |
                                  (unsigned char)packet.ch3;

    printf("Aggregated number: %u\n", aggregated_num);

    return 0;
}

// Write a C program to check whether the Host machine is in Little Endian or
// Big Endian. Enter a number, print the content of each byte location and
// Convert the Endianness of the same i.e. Little to Big Endian and vice-versa.

#include <stdio.h>

int check_endianness()
{
    unsigned int x = 1;
    char *c = (char *)&x;
    return (*c) ? 0 : 1;
}

void print_bytes(unsigned int num)
{
    unsigned char *byte = (unsigned char *)&num;
    for (int i = 0; i < sizeof(num); i++)
    {
        printf("Byte %d: 0x%X\n", i, byte[i]);
    }
}

unsigned int convert_endianness(unsigned int num)
{
    unsigned char *byte = (unsigned char *)&num;
    return (byte[0] << 24) | (byte[1] << 16) | (byte[2] << 8) | byte[3];
}

int main()
{

    if (check_endianness() == 0)
    {
        printf("Host machine is Little Endian.\n");
    }
    else
    {
        printf("Host machine is Big Endian.\n");
    }

    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    printf("Original number bytes:\n");
    print_bytes(num);

    unsigned int converted_num = convert_endianness(num);

    printf("Converted number bytes:\n");
    print_bytes(converted_num);

    printf("Converted number: %u\n", converted_num);

    return 0;
}

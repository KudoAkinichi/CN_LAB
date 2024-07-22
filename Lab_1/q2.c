// Write a C program to assign values to each member of the following structure.
// Pass the populated structure to a function Using call-by-value and another
// function using call-by-address and print the value of each member of the
// structure.
// struct student_info{
// int roll_no;
// char name [50];
// float CGPA;
// struct dob age;
// };

#include <stdio.h>
#include <string.h>

struct dob
{
    int day;
    int month;
    int year;
};

struct student_info
{
    int roll_no;
    char name[50];
    float CGPA;
    struct dob age;
};

void printStudByValue(struct student_info student)
{
    printf("Call-by-value:\n");
    printf("Roll No: %d\n", student.roll_no);
    printf("Name: %s\n", student.name);
    printf("CGPA: %.2f\n", student.CGPA);
    printf("Date of Birth: %d/%d/%d\n", student.age.day, student.age.month, student.age.year);
}

void printStudByAddr(struct student_info *student)
{
    printf("Call-by-address:\n");
    printf("Roll No: %d\n", student->roll_no);
    printf("Name: %s\n", student->name);
    printf("CGPA: %.2f\n", student->CGPA);
    printf("Date of Birth: %d/%d/%d\n", student->age.day, student->age.month, student->age.year);
}

int main()
{

    struct student_info student;

    student.roll_no = 101;
    strcpy(student.name, "John Doe");
    student.CGPA = 3.75;
    student.age.day = 15;
    student.age.month = 8;
    student.age.year = 2000;

    printStudByValue(student);

    printStudByAddr(&student);

    return 0;
}

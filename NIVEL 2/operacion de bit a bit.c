#include<stdio.h>

int main()
{
    int A = 29; //* 29 = 0001 1101*/
    int B = 48; //* 48 = 0010 0000*/
    int C = 0;

    C = A & B;     //* 16 = 0001 0000*/
    printf("%d & %d =%d\n", A , B ,C);
}
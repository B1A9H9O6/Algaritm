

#include <stdio.h>

int primenumber(int i)
{
    if (i % 2 == 0 )
    {
        printf("\n it's a hard number");
        return 0;
    }
    else
    {
       
        printf("\n it's a prime number");
        return 0;
    }
}

int main(void)
{
    int a;
    printf("Enter the number:");
    scanf_s ("%d", &a);
    primenumber(a);
    return 0;
}

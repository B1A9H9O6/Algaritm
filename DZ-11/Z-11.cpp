#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
//DZ-1===============================
void clear(char* arr, const int size)
{
    for (int i = 0; i < size; ++i) {
        arr[i] = -1;
    }
}

void print(char* buff)
{
    for (int i = 0; i < 50; i++)
    {
        if (buff[i] == '\r')
            break;
        printf("%c", buff[i]);
    }
    printf("\n");
}
void enc(char* buff, int a)
{
    if (a == 0)
    {
        printf("Encryption: ");
        for (int i = 0; i <= 50; i++)
        {
            if (buff[i] == -1)
                break;
            buff[i] = buff[i] + 3;
        }
    }
    else
    {
        printf("Decryption  ");
        for (int i = 0; i <= 50; i++)
        {
            if (buff[i] == -1)
                break;
            buff[i] = buff[i] - 3;
        }
    }
}
//=====================================================

//DZ-2=================================================
char cop[20];
char cop2[20];
void clear2(int* arr, const int size)
{
    for (int i = 0; i < size; ++i) {
        arr[i] = -1;
    }
}

void per(char* buff2, int* buf,int size, int a)
{
    
    if (a == 0)
    {
        printf("Encryption: ");
        for (int i = 0; i < size; i++)
        {
                cop[i] = buff2[buf[i] - 1];
                printf("%c ", cop[i]);
        }
    }
    else
    {
        printf("\nDecryption  ");
        for (int i = 0; i < size; i++)
        {
            printf("%c ", cop[buf[i] - 1]);
        }
    }
}

int main()
{
    //DZ-1=============================================
    char buff[50] ;
    printf("Enter the message to be encoded: ");
    clear(buff, 50);
  
    char n = 0;

   for(int k=0;k<=50;k++)
    {
       if (buff[k - 1] == '\n')
           break;
        scanf_s("%c", &n);
        buff[k] = n;   
   } 
   
   enc(buff, 0);
    print(buff);
    enc(buff, 1);
    print(buff);
    //===================================================

    //DZ-2===============================================
    char buff2[50];
    int buf[10]={2,1,4,3,5,8,9,6,7,10};
    char t = 0;
    int q = 0;
    clear(buff2, 50);
  
    int size=0;
    int sizebuf=0;
    printf("Enter the message to be encoded: ");
    for (int k = 0; k <= 50; k++)
    {

        scanf_s("%c", &t);
        buff2[k] = t;

        if (buff2[k] == '\n')
        {
            buff2[k] = 0;
            break;
        }
        size++; 
    }
  
  

    per(buff2, buf, size, 0);
    per(buff2, buf, size, 1);
    return 0;
}

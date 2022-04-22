#include <string.h>
#include <stdio.h> 
#include <stdlib.h>

//DZ-1==================================================
typedef struct OneLinkNode
{
    int dat;
    struct OneLinkNode* next;
} OneLinkNode;

void fillIntRandom(int* array, int size, int border) 
{
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

int htSize;

int hash(int data)
{
	return data % htSize;
}

int insertNode(OneLinkNode** table, int data)
{
    OneLinkNode* p, * p0;

    int bucket = hash(data);
    p = (OneLinkNode*)malloc(sizeof(OneLinkNode));
    if (p == NULL)
    {
        printf("Out of memory \n");
        return false;
    }

    p0 = table[bucket];
    table[bucket] = p;
    p->next = p0;
    p->dat = data;
    return true;
}
void print(OneLinkNode** table, int size)
{
    int a=0;
    OneLinkNode* p;
    for (int i = 0; i < size; i++)
    { 
        p = table[i];
        while (p)
        {
            
               printf("%5d", p->dat);
               a = p->dat + a;
                p = p->next;
                
        }
        

    }
    printf(" \n Sum=%d\n", a);
}
//=============================================================

//DZ-2=========================================================
void clearIntArray(int* arr, const int size)
{
    for (int i = 0; i < size; ++i) {
        arr[i] =0;
    }
}

const int max = 98;

int cal(int* zen, const int Task)
{
    int used[max];
    int arr[max];

    clearIntArray(used, max);
    clearIntArray(arr, max);

    int sum = 0;
    for (int i = 0; i <max; i++)
    {
        used[i] = zen[i];
        for (int y = 0; y < Task; y++)
        {
            
            if ((used[i]+sum) <= max && sum>=0)
            {
                sum += used[i];
                arr[i]++;
                

            }
            if (sum == 98)
            {
                break;
            }
        }
 
        if (sum == 98) break;
    }
    printf("\n");

    for (int i = 0; i <= Task - 1; i++)
    {
        printf("%d ", zen[i]);
    }

    printf("\n");

    for(int i=0;i<=Task-1;i++)
    {
        printf("%d  ", arr[i]);
    }
    return sum;
}

int main()
{
    //DZ-1====================================================
    htSize = 8;
    char a=-1;
    int* arr;
    const int sz = 20;
    arr = (int*)malloc(sizeof(int) * sz);
    OneLinkNode** hashTable = (OneLinkNode**)calloc(htSize, sizeof(OneLinkNode*));
    do
    {

            int i = 0;
            scanf_s("%c", &a);
              
            if (a >= 0 && a != 10)
            { 
                *(arr) = (int)a;
                insertNode(hashTable, arr[i]);
                 i++;
            }
    } while (a != '\n');
    print(hashTable, htSize);
    //============================================================

    //DZ-2========================================================
    const int n = 5;
    int coin[] = { 50, 10, 5, 2, 1 };
    printf("Sum=%d", cal(coin, n));
    return 0;
}

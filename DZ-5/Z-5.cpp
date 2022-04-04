#include <string.h>
#include <stdio.h> 

//Z-1=============================
void swap(int* a, int* b)
{
    int r = *a;
    *a = *b;
    *b = r;
}
void sort(int* arr, int l, int r)
{
    int y = arr[r];
    if (r <= l) 
        return;

    int i = l;
    int j = r - 1;
    int p = l - 1;
    int q = r;

    while (i <= l)
    {
        while (arr[i] < y)
            i++;
        while (arr[j] > y)
            j--;
        if (i >= j)
            break;
        swap(&arr[i], &arr[j]);

        if (arr[i] == y)
        {
            p++;
            swap(&arr[p], &arr[i]);
            i++;
        }
        if (arr[j] == y)
            swap(&arr[q--], &arr[i--]);
    }
    swap(&arr[i], &arr[r]);
    j = i - 1;
    i++;

    for(int x=l;x<=p;x++,j--)
        swap(&arr[x], &arr[j]);
    for (int x = r-1; x >= q; x++, i++)
        swap(&arr[x], &arr[i]);
    sort(arr, l, j);
    sort(arr, i, r);
}

void print(int* array, int size, int offset) 
{
    char format[8];
    sprintf_s(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) 
    {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}
//==================================
// 
// 
//Z-2===============================
const int siz = 12;     
const int hor = 10, ver = siz;
void newBuckets(int buckets[][ver])
{
    for (int i = 0; i < hor; i++)
        for (int j = 0; j < ver; j++)
            buckets[i][j] = -1;
}
void blocksort(int* array)
{
    
    int buckets[hor][ver];
    int ostatok, temp;
    int count = 0;

    for (int x = 1; x <= 100; x *= 10)
    {

        newBuckets(buckets);
        count = 0;

        for (int i = 0; i < siz; i++)
        {
            if (array[i] % 2 == 0)
            {
                temp = array[i] / x;
                ostatok = temp % 10;
                buckets[ostatok][i] = array[i];
            }
        }

        for (int i = 0; i < hor; i++)
        {
            for (int j = 0; j < ver; j++)
            {
                if (buckets[i][j] != -1)
                {
                    
                    
                        array[count] = buckets[i][j];
                        count++;
                    
                   
                }
               
            }
        }
    }

}
int main()
{
    //Z-1================================
    int arr[7] = { 3,6,6,8,2,1,2 };
    print(arr, 7,2);
    sort(arr, 0, 6);
    print(arr, 7,2);
    //===================================
    //Z-2================================
    int array[siz] = {0,2,8,3,4,6,5,9,8,2,7,3};  
    printf("\n");
    print(array, 12, 2);
    blocksort(array);
    print(array, 12, 2);
    return 0;
}



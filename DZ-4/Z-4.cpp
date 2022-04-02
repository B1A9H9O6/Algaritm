#include <string.h>
#include<stdio.h>
#include <math.h>

//DZ-2======================
double tpr(double x)
{
    return (sqrt(fabs(x)) + 5.0 * pow(x, 3.0));
}
//==========================

int main()
{
    //DZ-1===================================
   int arr[3][3] = {1,3,2,
                 7,5,9,
                 4,8,6};
   int x=0;
    for (int i = 0; i < 2; i++)
       {
           for (int y = 0; y < 3; y++)
           {
               
               if (arr[i][y] > arr[i + 1][y])
               { 
                   x = arr[i][y];
                   arr[i][y] = arr[i + 1][y];
                   arr[i + 1][y] = x;
               }

               if (arr[i][y] > arr[i][y +1])
               {
                   x = arr[i][y];
                   arr[i][y] = arr[i][y + 1];
                   arr[i][y + 1] = x;
                   
               }
               

           }

       }
    for (int i = 0; i < 3; i++)
   {
       for (int y = 0; y < 3; y++)
           printf("%d ", arr[i][y]);
    printf("\n");
   }
    //=======================================

    //DZ-2===================================
        double y;
        double p[11]={ 12.9, 9.3, 5.9, 112.0, 5.0, 3.0, 9.9, 9.0, 32.7, 31.2, 4.1 };
        for (int i = 10; i >= 0; i--)
        {
            y = tpr(p[i]);
            if (y > 400.0)
            {
                printf("\n%d Too big number ", i);
            }
            else
            {
                printf("\n%d %f ", i, y,"\n");
            }
        }
    return 0;
}


// Z-3.cpp 
//
#include <stdio.h>

//dz-1===================================
int recbin(int a)
{
	
	
	if (a >0)
	{
		printf("%d",a % 2 ,recbin(a/2));
	}
	else
		return a;
}
//=======================================



//dz-2===================================
int recdeg(int a,int b, int c)
{
	if (b > 0)
	{
		c*=a;
	
		recdeg(a, b - 1, c);
	}
	else
	{
		printf("%d\n", c);
		return 0;
	}
}
//=======================================



//dz-2.2=================================
int recParityCal(int a, int b, int c)
{
	if (b > 0)
	{
		c *= a;

		recParityCal(a, b-1, c);
	}
	else
	{
		printf("%d\n", c);
		return 0;
	}
}
int recParity(int a, int b,int c)
{
	if (b % 2 == 0)
	{
		a*=a;
		b = b / 2;
		recParityCal(a, b, c);
	}
	else
	{
		return 0;
	}
}
//======================================


//dz-3==================================
int routes(int x, int y)
{
	if (x == 1 && y == 1)
		return 1;
	else
		return x + y; //
	
	
}
int routesII(int x, int y) 
{
	if (x == 1 && y == 1)
		return 1;
	else
		return 0; //


}




int main(void)
{
	//dz-1===========
	int dec = 183;
	recbin(dec);
	printf("\n");
	//===============
	 
	//dz-2===========
	int a = 2;
	int b = 8;
	int c = 1;
	recdeg(a, b, c);
	//===============
	
	//dz-2.2=========
	recParity(a, b, c); // Не понял задания с нечетным 
	//===============

	//dz-3===========
	const int sizeX = 3;
	const int sizeY = 3;
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			printf("%5d", routes( x,  y));
		}
		printf("\n");
	}

	printf("\n");

	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			printf("%5d", routesII(x, y));
		}
		printf("\n");
	}



	return 0;
}
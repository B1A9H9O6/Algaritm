#include <string.h>
#include <stdio.h> 
#include <stdlib.h>

const int n = 6;
int cursor = -1;
int stack[n];
int push(int data)
{
	if (cursor < n)
	{
		
		stack[++cursor] = data;

		return true;
	}
	else
	{
		printf("\nSteck overflow");
		return false;
	}
}
int pop()
{

	

		return printf("%c,", stack[cursor--] + 65);
	

}


int matrix[n][n] = {
	{0,1,0,0,0,0},
	{0,0,1,0,0,0},
	{0,0,0,1,0,0},
	{0,0,0,0,1,0},
	{0,0,0,0,0,1},
	{0,0,0,0,1,0},
};

int visited[n] = { 0 };

void dep(int st)
{
	int r;
	
	printf("%c ", st +65);
	visited[st] = 1;
	for (r = 0; r < n; r++)
	{
		if (matrix[st][r] == 1 && !visited[r])
		{
			push(r);
			dep(r);
			
		}
	}
	
}

void reset()
{
	for (int i = 0; i < n; i++)
	{
		visited[i] = 0;
	}
}
int main()
{
	dep(0); 
	reset();
	printf("\n");
	for (int i = 0; i < 6; i++)
	{
		pop();
	}
	
	return 0;
}

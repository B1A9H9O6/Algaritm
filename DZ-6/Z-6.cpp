#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#define T int

//Z-1===================================
#define SZ 10
typedef struct Node
{
	int pr;
	int dat;
};


Node* arr[SZ];
int head;
int tail;
int items;

void init()
{
	for (int i = 0; i < SZ; i++)
	{
		arr[i] = 0;
	}
	head = 0;
	tail = 0;
	items = 0;

}

void ins(int pr, int dat)
{
	Node* node = (Node*) malloc(sizeof(Node));
	node->dat = dat;
	node->pr = pr;
	int flag;

	if (items == 0)
	{
		arr[tail++] = node;
		items++;
	}
	else if (items == SZ)
	{
		printf("\nQueue ist full");
		return;
	}
	else
	{
		int i = 0;
		int idx = 0;
		Node* tmp;
		for (i = head; i < tail; i++)
		{
			idx = i % SZ;
			if (arr[idx]->pr > pr)
				break;
			else
				idx++;
		}
		flag = idx % SZ;
		i++;
		while (i <= tail)
		{
			idx = i % SZ;
			tmp = arr[idx];
			arr[idx] = arr[flag];
			arr[flag] = tmp;
			i++;
		}
		arr[flag] = node;
		items++;
		tail++;
	}
}

Node* rem()
{
	if (items == 0)
	{
		return 0;
	}
	else
	{
		int idx = head++ % SZ;
		Node* tmp = arr[idx];
		arr[idx] = NULL;
		items--;
		return tmp;
	}
}
 
void printQ()
{
	printf("[ ");
	for (int i = 0; i < SZ; i++)
	{
		if (arr[i] == NULL)
		{
			printf("[* , *]");
		}
		else
		{
			printf("[%d, %d]", arr[i]->pr, arr[i]->dat);
		}
	}
	printf(" ]\n");
}

void re(int x)
{
	for (int i = 0; i < x; i++)
	{
		Node* n = rem();
	}
	printQ();
}
//=======================================

//Z-2====================================
#define size 10

typedef T boolean;

T cursor = -1;
T stack[size];

boolean push(T data)
{
	if (cursor < size)
	{ 
		printf("%d ", data);
		stack[++cursor] = data;
		
		return true;
	}
	else
	{
		printf("\nSteck overflow");
		return false;
	}
}

T pop()
{
	if (cursor != -1)
	{
		
		return printf(","), stack[cursor--];
	}
	else
	{
		printf("\n\Stack is empty");
		return-1;
	}
}
T recbin(T a)
{
	if (a > 0)
	{
		printf("%d", a % 2, recbin(a / 2));
	}
	else
		return a;
}

int main()
{
//Z-1====================================
	init();
	ins(1, 11);
	ins(3, 22);
	ins(4, 33);
	ins(2, 44);
	ins(3, 55);
	ins(4, 66);
	ins(5, 77);
	ins(1, 88);
	ins(2, 99);
	ins(6, 100);
	printQ();

	re(7);
	ins(1, 110);
	ins(6, 130);
	ins(2, 120);
	re(5);
//=========================================
	printf("\n");
//Z-2======================================
	push(2);
	push(3);
	push(5);
	push(8);
	push(9);
	printf("\n");
	while (cursor != -1)
	{
		recbin(pop()) ;
	}
//=========================================
	return 0;
}

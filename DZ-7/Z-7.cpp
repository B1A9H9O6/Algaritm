#include <string.h>
#include <stdio.h> 
#include <stdlib.h>
#define T char
//Z-1=====================================

#define siz 11

typedef char boolean;

T cursor = -1;
T stack[siz];

boolean push(T data)
{
	if (cursor < siz)
	{
		printf("%c", data);
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
		printf("\n Stack is empty");
		return-1;
	}
}
void recbin()
{
	bool t = false;
	int c = 0;
	int l = 0;
	int s = 0;
	for (int i = 0; i <= 9; i++)
	{
		int u = i;
		for (int x = 0; x <= 9; x++)
		{
			if (stack[i] == '(' || stack[x] == ')')
			{
				if (stack[u++] == ']' || stack[u++] == '}')
					break;
				c++;
			}	
				if (stack[i] == '(' && stack[x] == ')'&&i<x)
				{
					t = true;
					c = 0;
				}
				else if (stack[i] == ')' && stack[x] == '(')
				{
					break;
				}
			

			if (stack[i] == '[' || stack[x] == ']')
			{
				if (stack[u++] == ')' || stack[u++] == '}')
						break;
				l++;
			}	
				if (stack[i] == '[' && stack[x] == ']' && i < x)
				{
						t = true;
						l = 0;
				}
				else if (stack[i] == ']' && stack[x] == '[')
				{
					break;
				}
			

			if (stack[i] == '{' || stack[x] == '}')
			{
				if (stack[u++] == ')' || stack[u++] == ']' )
				{
					break;
				}
				s++;
			}	
				if (stack[i] == '{' && stack[x] == '}'&& i < x)
				{
						t = true;
						s = 0;
				}
				else if (stack[i] == '}' && stack[x] == '{' && i < x)
				{
					break;
				}
			
		}
	}
	if (t == false || c%2!=0 || l % 2 != 0 || s % 2 != 0)
	{
		printf("ERROR");
	}
	else
	{
		printf("Best");
	}
	return;
}
//=======================================================

//Z-2-3====================================================
int sor = 0;
typedef struct Node
{
	int dat;
	struct Node* next;
};

typedef struct List
{
	Node* head;
	int size;
};

void init(List* lst)
{
	lst->head = NULL;
	lst->size = 0;
}
void sort(int a )
{

	int c = 0;
	if (sor>a)
	{
		
		printf("List not sorted");
	}else
		
	sor = a;
	
}
void ins(List* lst, int data)
{

	Node* nev = (Node*)malloc(sizeof(Node));
	nev->dat =data;
	nev->next = NULL;
	

	Node* cur = lst->head;
	if (cur == NULL)
	{
		lst->head = nev;
		lst->size++;
		return;
	}
	else 
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = nev;
		lst->size++;
	}	
	sort(data);
}

Node* rm(List* lst, int data)
{
	Node* cur = lst->head;
	Node* par = NULL;
	if (cur == NULL)
		return NULL;

	while (cur->next != NULL && cur->dat != data)
	{
		par = cur;
		cur = cur->next;
	}
	if (cur->dat != data)
	{
		return NULL;
	}
	if (cur == lst->head)
	{
		return cur;
	}
	return cur;
}

void printNode(Node* n)
{
	if (n == NULL)
	{
		printf("[]");
		return;
	}
	printf("[%d]", n->dat);
}

void printList(List* lst)
{
	Node* cur = lst->head;
	if(cur == NULL)
	{
		printNode(cur);
	}
	else
	{
		do
		{
			printNode(cur);
			cur = cur->next;
		} while (cur != NULL);
	}
	printf("Size: %d \n", lst->size);
}
//======================================================
int main()
{
	//Z-1===============================================
	char i=NULL;
	printf("Enter expressions: ");
	do
	{
		scanf_s("%c",&i);
		push(i);
	} while (i !='\n');
	recbin();
	printf("\n");
	//==================================================
	//Z-2-3===============================================
	List* lst = (List*)malloc(sizeof(List));
	init(lst);
	printList(lst);
	ins(lst, 1);
	ins(lst, 10);
	ins(lst, 8);
	ins(lst, 40);
	ins(lst, 100);
	printList(lst);
	printNode(rm(lst, 100));
	printf("<- \n");
	printNode(rm(lst, 10));
	printf("<- \n");
	printList(lst);
	//===================================================
	//Z-3
	return 0;
}



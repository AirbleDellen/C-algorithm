#include<stdio.h>
#include<stdlib.h>
//基于堆栈和队列的回文检测
typedef struct linknode
{	char data;
	struct linknode *next;
}node;

node *head;
int n=0;                                   

//以下为检测回文主程序
int main()
{
	node *top,*last,*a3;
	node *p,*s;
	int l;
	char x;
	n=0;
	head=(node*)malloc(sizeof(node));
	last=(node*)malloc(sizeof(node));  
	p=last;
	scanf("%c",&x);
	s=(node*)malloc(sizeof(node)); 
	n++;  
	s->data=x;                             
	s->next=NULL;
	top=s;
	scanf("%c",&x);
	while(x!='#')	
	{		
		s=(node*)malloc(sizeof(node));        
		n++;                                  
		s->data=x;                            
		s->next=top;		               
		top=s;                                  
		scanf("%c",&x);
	}
	a3=top;
	while(a3->next!=NULL)
	{
		a3=a3->next;
		printf("%c",a3->data);

	}
	
}
#include<stdio.h>
#include<stdlib.h>
//基于堆栈和队列的回文
typedef struct linknode
{	char data;
	struct linknode *next;
}node;

node *head;
int n=0,nn;                                   

//以下为检测回文主程序
int main()
{
		node *top,*last,*a3;
		node *p,*s;
		int l;
		char x;
		
		node *head,*s1,*s2;
		node *s0;
		
		printf("请输入待检测字符串，以#结尾\n");
	n=0;
	head=(node*)malloc(sizeof(node));
	last=(node*)malloc(sizeof(node));  
	p=last;
	scanf("%c",&x);
	{
		s=(node*)malloc(sizeof(node)); 
		n++;  
		s->data=x;                             
		s->next=NULL;
		top=s;                            //建立堆栈初始节点
	}
	{
		s0=(node*)malloc(sizeof(node));
		s0->data=x;
		s0->next=NULL;
		head->next=s0;
	}                                     //建立初始列表节点
	scanf("%c",&x);
	while(x!='#')	
	{		
		{
			s=(node*)malloc(sizeof(node));        
			n++;                          //记录字符节点数        
			s->data=x;                            
			s->next=top;		               
			top=s;  
		}                                 //此段用于写入堆栈
		{
			s1=s0;
			s0=(node*)malloc(sizeof(node));
			s0->data=x;
			s0->next=NULL;
			s1->next=s0;
		}
		scanf("%c",&x);                
	}
	a3=top;
	
	//do
	//{	
	//	printf("%c",a3->data);
	//	a3=a3->next;	
	//} 
	//while(a3->next!=NULL); 
	//printf("%c",a3->data);          //此段用于堆栈输出检测
	//printf("\n");


	//s2=head;
	//while(s2->next!=NULL)
	//{
	//	s2=s2->next;
	//	printf("%c",s2->data);
	//}                               //此段用于列表输出检测
	//printf("\n");
    

	a3=top;
	s2=head;                 //初始化节点

	
	for(nn=0;nn<=n/2;nn++)
	{
		
		
	
		//printf("%c\n",a3->data);  //检测比对对象（1）
		s2=s2->next;
		//printf("%c\n",s2->data);  //检测比对对象（2）
		if(a3->data!=s2->data)
		{
			printf("所输入字符串非回文");
			return 0;
		}	
		a3=a3->next;
	}
	printf("所输入字符串为回文");
	return 0;
	
}

#include<stdio.h>
#include<stdlib.h>

typedef struct linknode
{	char data;
	struct linknode *next;
}node;

node *head;
int n=0;                                   
 
void CreateList()              
{
	node *p,*s;
	char x;
	n=0;
	head=(node*)malloc(sizeof(node)); 
	p=head;
	printf("\n\t\t建立一个线性表");
	printf("\n\t\t说明：请逐个输入字符，结束标记为#\n");
	printf("\t\t输入：");
	scanf("%c",&x);
	while(x!='#')	
	{		
		s=(node*)malloc(sizeof(node));         /*申请一个新结点*/
		n++;                                  
		s->data=x;                             /*对新结点的data域赋值*/
		s->next=NULL;		               /*对新结点的next域赋空值*/
		p->next=s;                             /*将新结点连接到表的末尾*/
		p=s;                                   /*P指向最后结点*/
		scanf("%c",&x);
	}
}

void InsList(int i,char x)                /*在单链表第i个位置插入元素*/          
{
	node *s,*p;
	int j;

	if(i<1)                            /*若i<1, 则插入位置错误*/    
	{
		printf("\n\t\t\t插入位置不合法！\n");
		return;
	}
	else                               
	{
		p=head;j=0;
		while(p!=NULL&&j<i-1)      /*寻找插入位置*/  
		{
			j++;
			p=p->next;
		}
		if(p!=NULL)               /*插入*/
		{
			s=(node*)malloc(sizeof(node));
			s->data=x;
			s->next=p->next;
			p->next=s;
			n++;
		}
		else 
		{
			printf("\n\t\t\t未找到插入位置！\n");
			return;
		}
	}
}

void DelList(int i)         /*删除单链表中第i个元素*/                      
{
	node *p,*q;
	int j=0;
	if(head->next==NULL) 
	{	
		printf("\n\t\t\t线性表已经为空！\n");
		return;
	}
	if(i<1)                            
	{
		printf("\n\t\t\t位置不合法！\n");
		return;
	}
	p=head;
	while(p->next!=NULL && j<i-1)         /*循环直到p指向第i-1个结点*/ 
	{
		p=p->next;
		j++;
	}
	if(p->next==NULL || j>i-1)
	{   		
		printf("\n\t\t\t没找到要删除的位置！\n");
		return;
	}
	else
	{
		q=p->next; p->next=q->next;		   /*删除第i个结点*/
		n--;
		free(q);
	}	
}

void ShowList()                   /*显示单链表所有元素*/        
{   
	node *p=head;
	printf("\n\t\t显示线性表的所有元素：");
	if(head->next==NULL||p==NULL)
		printf("\n\t\t链表为空！\n");
	else
	{
		printf("\n");
		while(p->next!=NULL)
		{
			printf("%5c",p->next->data);
			p=p->next;
		}
	}
}

void SearchList(char x)         /*在单链表查找值为x的数据元素*/         
{
  	node *p;
  	int i=0;
	p=head;
	while(1)
	{
		if (p->data==x)
		{
			printf("所输入值为第%d个数据",i);
			return;
		}
		if (p->next==NULL)
		{
			printf("未找到值为%c的元素",x);
		    return;
		}
		p=p->next;
		i++;
	}
}
void ReverseList() 
{
    if (head == NULL || head->next == NULL) 
	{
        printf("\n\t\t链表为空或只有一个元素，无法逆置。\n");
        return;
    }    
    node *prev = NULL, *curr = head->next, *next = NULL;    
    while (curr != NULL) 
	{
        next = curr->next;   
        curr->next = prev;   
        prev = curr;         
        curr = next;       
    }
    head->next = prev;       
}

int main()
{   
	int choice,i,j=1;
	char x;
	head=NULL;
	while(j!=0)
	{   
		printf("\n\n\n\n");
		printf("\t\t\t   线 性 表 子 系 统\n");
		printf("\n\t\t***************************************");
		printf("\n\t\t*          1-------建     表          *");
		printf("\n\t\t*          2-------插     入          *");
		printf("\n\t\t*          3-------删     除          *");
		printf("\n\t\t*          4-------显     示          *");
		printf("\n\t\t*          5-------查     找          *");
		printf("\n\t\t*          6-------求 表  长          *");
		printf("\n\t\t*          7-------就 地 逆 置        *");
		printf("\n\t\t*          0-------返     回          *");
		printf("\n\t\t***************************************\n");
		printf("\t\t请选择菜单号(0--6)：");
		
		scanf("%d",&choice);getchar();
		if(choice==1)
			CreateList();
		else if (choice==2)
			{   
				printf("\n\t\t请输入的位置i和数值x(输入格式：i，x):");
				scanf("%d,%c",&i,&x);
				InsList(i,x);
			}
		else if (choice==3)
			{   
				printf("\n\t\t请输入要删除元素的位置：");
				scanf("%d",&i);
				DelList(i);
			}
		else if (choice==4)
			{   
				if(head==NULL)
					printf("\n\t\t请先建立线性表！");
				else
					ShowList();
			}
		else if (choice==5)
			{   
				printf("\n\t\t请输入要查找的元素：");
				scanf("%c",&x);
				SearchList(x);
			}
		else if (choice==6)
			{   
				printf("\n\t\t表长为%d",n);
			}
		else if (choice == 7) 
		    {
                ReverseList();
                printf("\n\t\t链表已经逆置完成！\n");
            }
		else if (choice==0)
			j=0;
		else 
			printf("\n\t\t输入错误！请重新输入！\n");
	}
	return 0;
}

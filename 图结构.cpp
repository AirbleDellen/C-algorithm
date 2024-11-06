#include <stdio.h>

#define MAXLEN 10                       /*图的最多顶点数*/
#define FALSE 0
#define TRUE 1
#define QueueSize 30                    /*队列的最大容量数，图的广度优先遍历用到队列*/

typedef struct                                /*图的邻接矩阵存储结构*/
{
	char vexs[MAXLEN];                    /*存储顶点信息的一维数组*/
	int edges[MAXLEN][MAXLEN];            /*存储边信息的二维数组*/
	int n,e;                              /*顶点数和边数*/
}MGraph;

int visited[MAXLEN];                       /*标识结点是否已被访问的一维数组*/

typedef struct                            /*顺序循环队列，图的广度优先遍历用到队列*/
{
	int front;
	int rear;
	int count;
	int data[QueueSize];
}CirQueue;

void InitQueue(CirQueue *Q)           /*初始化队列*/
{
	Q->front=Q->rear=0;
	Q->count=0;
}

void EnQueue(CirQueue *Q,int x)        /*数据x进队*/
{
	if (Q->count>0 && Q->rear==Q->front)
		printf("Queue overflow");
	else
	{       
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%QueueSize;
		Q->count++;
	}
}

int DeQueue(CirQueue *Q)            /*队头数据元素出队*/
{
	int temp;
	if(Q->count==0)
	{
		printf("Queue underflow");
		return NULL;
	}
	else
	{
		temp=Q->data[Q->front];
		Q->front=(Q->front+1)%QueueSize;
		Q->count--;
		return temp;
	}
}

void CreateMGraph(MGraph *G)
{     
	int i,j,k;
	
	printf("\t\t请输入顶点数和边数(输入格式为:顶点数,边数):\n\t\t");
	scanf("%d,%d",&(G->n),&(G->e));
	printf("\t\t请输入顶点信息,每个顶点以回车作为结束:\n");
	for(i=1;i<=G->n;i++)
	{ 
		getchar(); printf("\t\t");
		scanf("%c",&(G->vexs[i]));
	}
	for(i=1;i<=G->n;i++)
		for(j=1;j<=G->n;j++)
			G->edges[i][j]=0;
	printf("\t\t请输入每条边对应的两个顶点的序号(从1开始编号,输入格式为:i,j):\n");
	for(k=1;k<=G->e;k++)
	{
		getchar();
		printf("\t\t请输入第%d条边的顶点序号：",k);
		scanf("%d,%d",&i,&j);
		G->edges[i][j]=1;
	}
}

void DFSM(MGraph *G,int i) 
/*从第i个顶点开始进行深度优先遍历，若为连通图，则可遍历所有结点*/
{
	int j;
	printf("\t\t深度优先遍历结点: 结点%c\n",G->vexs[i]);
	visited[i]=TRUE;        /*标记初始顶点i为已访问结点*/
	for(j=1;j<=G->n;j++)       
		/*对于从i顶点展开的所有尚未被访问的邻接点，都按深度优先遍历的原则进行访问*/
		if(G->edges[i][j]==1 && !visited[j])  DFSM(G,j);            
}

void  DFSTraverseM (MGraph *G)  
/*若为非连通图，则把每一个顶点都作为初始结点进行深度优先遍历，则可遍历所有结点*/
{
	int i;
	for(i=1;i<=G->n;i++)
		visited[i]=FALSE;
	for(i=1;i<=G->n;i++)
		if(!visited[i])  DFSM(G,i);
}

void BFSM(MGraph *G,int k)
/*借助队列从第k个顶点开始进行广度优先遍历，若为连通图，则可遍历所有结点*/
{ 
	int i,j;
	CirQueue Q;
	InitQueue(&Q);
	printf("\t\t广度优先遍历结点: 结点%c\n",G->vexs[k]);
	visited[k]=TRUE;                   /*标记初始顶点k为已访问结点*/
	EnQueue(&Q,k);                     /*初始顶点k入队*/
	while (Q.count!=0)
	{
		i=DeQueue(&Q);               /*队头结点出队*/
		for (j=1;j<=G->n;j++)
			if(G->edges[i][j]==1 && !visited[j])
			/*对于从i顶点展开的所有尚未被访问的邻接点，访问、置已访问标志，并入队*/
			{
				printf("\t\t广度优先遍历结点: 结点%c\n",G->vexs[j]);
				visited[j]=TRUE;
				EnQueue(&Q,j);
			}
	}
}

void BFSTraverseM(MGraph *G)
/*若为非连通图，则把每一个顶点都作为初始结点进行广度优先遍历，则可遍历所有结点*/
{
	int i;
	for (i=1;i<=G->n;i++)
		visited[i]=FALSE;
	for (i=1;i<=G->n;i++)
		if (!visited[i]) BFSM(G,i);
}

void DELET(MGraph *G)
{
	int k=0,h=0,i,j,p; 
          
	printf("请输入意欲删除的节点序号：");
	scanf("%d", &p);
	for(i=1;i<=G->n;i++)
	{
		if (G->edges[i][p]==1)
		{
			(G->e)--;
		}
		if (G->edges[p][i]==1)
		{
			(G->e)--;
		}
	}  //次循环用于删除与选定节点P有关的边数
	for(i=p+1;i<=G->n;i++)
	{
		for(j=1;j<=G->n;j++)
		{
			(G->edges[i-1][j])=(G->edges[i][j]); //将第i行节点前移
		}
	}
	for(i=p+1;i<=G->n;i++)
	{
		for(j=1;j<=G->n;j++)
		{
			(G->edges[j][i-1])=(G->edges[j][i]);  //将第i列节点前移
		}
		(G->vexs[i-1])=(G->vexs[i]);
	}

	(G->n)=(G->n)-1;
	printf("删除成功");
	printf("\n新矩阵为");
	printf("\n\t\t");
	for(i=1;i<=G->n;i++)
	{
		for(j=1;j<=G->n;j++)
			printf("%5d",G->edges[i][j]);
		printf("\n\t\t");                
	}
	getchar();
}

int main()
{
	MGraph *G,a;
	char ch1;
	int i,j,ch2;
	G=&a;
	printf("\n\t\t建立一个有向图的邻接矩阵表示\n");
	CreateMGraph(G);
	printf("\n\t\t已建立一个图的邻矩阵存储\n\t\t");
	for(i=1;i<=G->n;i++)
	{
		for(j=1;j<=G->n;j++)
			printf("%5d",G->edges[i][j]);
		printf("\n\t\t");                
	}
	getchar();
	ch1='y';
	while(ch1=='y'||ch1=='Y')
	{
		printf("\n\n\n\n\n\t\t图 子 系 统\n");
		printf("\t\t******************************************\n");
		printf("\t\t*          1-------更新邻接矩阵          *\n");
		printf("\t\t*          2-------深度优先遍历          *\n");
		printf("\t\t*          3-------广度优先遍历          *\n");
		printf("\t\t*          4-------选定节点删除          *\n");
		printf("\t\t*          0-------退        出          *\n");
		printf("\t\t******************************************\n");
		printf("\t\t请选择菜单号(0--4):");
		scanf("%d",&ch2); 
		getchar();
		switch(ch2)
		{
		 case 1:
			CreateMGraph(G);
			printf("\t\t\t图的邻接矩阵存储建立完毕.\n");
			break;
		 case 2:
			DFSTraverseM(G);
			break;
		 case 3:
			BFSTraverseM(G);
			break;
		case 4:
			DELET(G);
			break;
		 case 0:
			ch1='n';
			break;
		 default:
			printf("\t\t输入错误！请重新输入！\n");
		}
	}
}
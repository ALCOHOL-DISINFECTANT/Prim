#include<stdio.h>

#define MAX 100//定义最大顶点数 

int visited(int ar[][MAX]);//输入邻接矩阵 
void output(int ver, int ar[][MAX]);//输出信息

typedef struct SHORT//用于生成结构体矩阵用以判断各个邻接边的最短边 
{
	int adjvek;
	int lowvek;
}short_ver;

int main()
{
	int i, j, ori, ver, som;
	int visit[MAX][MAX];
	short_ver shord[MAX], compare;
	
	for(i = 0;i < MAX;i++)//初始化邻接矩阵 
	{
		for(j = 0;j < MAX;j++)
			visit[i][j] = 2147483646;
		visit[i][i] = 0;
	}
	
	for(i = 0;i < MAX;i++)
	{
		shord[i].adjvek = 0;
		shord[i].lowvek = 0;		 
	}
	
	ver = visited(visit);//输入邻接矩阵 
	printf("请输入Prim算法的起点：");
	scanf("%d",&ori);
	output(ver, visit);//输出信息 
	printf("输出起点从V%d开始的最小生成树：\n",ori);
	
	for(i = 0;i < ver;i++)//将visit中的第ori行的信息导入shord数组中 
	{
		shord[i].adjvek = ori;
		shord[i].lowvek = visit[ori][i];
	}
	
	for(j = 1;j < ver;j++)
	{
		compare.adjvek = 2147483647;
		compare.lowvek = 2147483647;
		som = 0;
		for(i = 0;i < ver;i++)
		{
			if(compare.lowvek >= shord[i].lowvek && shord[i].lowvek != 0)//找出最短边 
			{
				som = i;
				compare.adjvek = shord[i].adjvek;
				compare.lowvek = shord[i].lowvek;
			}
		}
		shord[som].lowvek = 0;//记录最短边 
		for(i = 0;i < ver;i++)
		{
			if(shord[i].lowvek > visit[som][i])
			{
				shord[i].adjvek = som;
				shord[i].lowvek = visit[som][i];
			}
		}
		
		printf("(%d,%d)%d\n",compare.adjvek,som,compare.lowvek);//输出最优边的信息 
	}
}

int visited(int visit[MAX][MAX])
{
	int ver, ver1, ver2, edge, edge1, i;
	printf("请输入顶点个数和边的个数：");
	scanf("%d %d",&ver, &edge);	

	for(i = 0;i < edge;i++)
	{
		printf("请输入边依附的两个顶点编号(范围0-%d)和权值：",ver-1);
		scanf("%d %d %d",&ver1, &ver2, &edge1);
		if(ver1<0||ver1>5||ver2<0||ver2>5)
		{
			printf("请输入两个范围在 0-%d 的顶点编号\n",ver-1);
			continue;
		}
		else
		{
			visit[ver1][ver2] = edge1;
			visit[ver2][ver1] = edge1;
		}		 
	}
	return ver;
		
}
void output(int ver, int visit[MAX][MAX])
{
	int i, j;
	printf("输出边数组信息：\n");
	for(i = 0;i < ver;i++)
		printf("%d ",i);
	printf("\n输出邻接矩阵信息：\n");
	for(i = 0;i < ver;i++)
	{
		for(j = 0;j < ver;j++)
		{
			if(visit[i][j] != 2147483646)
				printf("%2d  ",visit[i][j]);
			else
				printf("∞  ");
		}
		printf("\n");
	}
}

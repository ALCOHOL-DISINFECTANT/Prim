#include<stdio.h>

#define MAX 100//������󶥵��� 

int visited(int ar[][MAX]);//�����ڽӾ��� 
void output(int ver, int ar[][MAX]);//�����Ϣ

typedef struct SHORT//�������ɽṹ����������жϸ����ڽӱߵ���̱� 
{
	int adjvek;
	int lowvek;
}short_ver;

int main()
{
	int i, j, ori, ver, som;
	int visit[MAX][MAX];
	short_ver shord[MAX], compare;
	
	for(i = 0;i < MAX;i++)//��ʼ���ڽӾ��� 
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
	
	ver = visited(visit);//�����ڽӾ��� 
	printf("������Prim�㷨����㣺");
	scanf("%d",&ori);
	output(ver, visit);//�����Ϣ 
	printf("�������V%d��ʼ����С��������\n",ori);
	
	for(i = 0;i < ver;i++)//��visit�еĵ�ori�е���Ϣ����shord������ 
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
			if(compare.lowvek >= shord[i].lowvek && shord[i].lowvek != 0)//�ҳ���̱� 
			{
				som = i;
				compare.adjvek = shord[i].adjvek;
				compare.lowvek = shord[i].lowvek;
			}
		}
		shord[som].lowvek = 0;//��¼��̱� 
		for(i = 0;i < ver;i++)
		{
			if(shord[i].lowvek > visit[som][i])
			{
				shord[i].adjvek = som;
				shord[i].lowvek = visit[som][i];
			}
		}
		
		printf("(%d,%d)%d\n",compare.adjvek,som,compare.lowvek);//������űߵ���Ϣ 
	}
}

int visited(int visit[MAX][MAX])
{
	int ver, ver1, ver2, edge, edge1, i;
	printf("�����붥������ͱߵĸ�����");
	scanf("%d %d",&ver, &edge);	

	for(i = 0;i < edge;i++)
	{
		printf("�����������������������(��Χ0-%d)��Ȩֵ��",ver-1);
		scanf("%d %d %d",&ver1, &ver2, &edge1);
		if(ver1<0||ver1>5||ver2<0||ver2>5)
		{
			printf("������������Χ�� 0-%d �Ķ�����\n",ver-1);
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
	printf("�����������Ϣ��\n");
	for(i = 0;i < ver;i++)
		printf("%d ",i);
	printf("\n����ڽӾ�����Ϣ��\n");
	for(i = 0;i < ver;i++)
	{
		for(j = 0;j < ver;j++)
		{
			if(visit[i][j] != 2147483646)
				printf("%2d  ",visit[i][j]);
			else
				printf("��  ");
		}
		printf("\n");
	}
}

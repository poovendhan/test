#include<stdio.h>
#include<stdlib.h>
typedef struct edge
{
	int v1,v2,w;
}edge;
typedef struct node
{
	edge data[20];
	int n;
}node;
node list;
int temp[10];
void sort()
{
	int i,j;
	node t;
	for(i=0;i < list.n; i++)
	{
		for(j = 0; j < list.n-1; j++)
		{
			if(list.data[j].w > list.data[j+1].w)
			{
				t.data[j] = list.data[j];
				list.data[j] = list.data[j+1];
				list.data[j+1] = t.data[j];
			}
		}
	}
}
int findvertex(int c)
{
	return temp[c];
}

void union1(int c1, int c2, int nn)
{
	int i;
	for(i = 1; i <= nn; i++)
	{
		if(temp[i] == c2)
			temp[i] = c1;
	}
}
void kruskalAlgorthim(int v, int nn, int a[][3])
{
	list.n = 0;
	int i, j, c1, c2;

	//store the vertiex edge and weights into the structure
	for(i = 0; i < v; i++)
	{
		list.data[list.n].v1 = a[i][0];
		list.data[list.n].v2 = a[i][1];
		list.data[list.n].w = a[i][2];
		list.n++;
	}
	
	//sort the structure to non decreasing order based on weight
	sort();

	//i starts from 1 bcz vertiex edges starting from 1
	for(i = 1; i <= nn ; i++) 
	{
		temp[i] = i;
	}
	for(i = 0; i < list.n; i++)
	{
		//To avoid the loop
		c1 = findvertex(list.data[i].v1);
		c2 = findvertex(list.data[i].v2);
		if(c1 != c2)
		{
			temp[c2] = c1;
			printf("%d %d->%d\n", list.data[i].v1, list.data[i].v2, list.data[i].w);
			union1(c1,c2, nn);
		}
	}

}

int main()
{
	int i,j,v,nn;
	
	printf("Enter the no of connection b/w two vertiexs:");
	scanf("%d", &v);
	printf("\nEnter the no of nodes:");
	scanf("%d", &nn);
	int a[v][3];
	for(i = 0; i < v; i++)
	{
		for(j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	kruskalAlgorthim(v, nn, a);
}


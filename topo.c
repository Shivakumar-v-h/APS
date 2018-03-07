#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int top=-1;
int stack1[6];
void push(int num)
{
    stack1[++top]=num;
}
int pop()
{
    return (stack1[top--]);
}
void topological(int arr[][10],int n)
{
    int i,j,k,temp;
    int t[n+1];
    int x=0;
    int *visited=(int *)malloc(sizeof(int)*n);
    int *in_degree=(int *)malloc(sizeof(int)*n);
    memset(visited,0,sizeof(int)*n);
    memset(in_degree,0,sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[j][i]==1)
                in_degree[i]=in_degree[i]+1;
        }
    }

    printf(("\n\n"));
    for(k=0;k<6;k++)
    {
      /*  for(i=0;i<n;i++)
        {
        printf("%d ",in_degree[i]);
        }*/
    for(i=0;i<n;i++)
    {
        if(in_degree[i]==0)
        {
          //  flag==1;
            push(i);
            visited[i]=1;
        }
    }
    if(top!=-1)
    {
        temp=pop();
     //   printf("temp=%d\n",temp);
        t[x++]=temp;
        in_degree[temp]=-1;
        for(j=0;j<n;j++)
        {
            if(arr[temp][j]==1 && visited[j]==0)
            {
                in_degree[j]=in_degree[j]-1;
            /*    if(in_degree[j]==0)
                {
                    push(j);
                    visited[j]=1;
                }*/
            }
        }
    }
    }
    for(i=0;i<n;i++)
    {
        printf("%d  ",t[i]);
    }
}
int main()
{
    int m[10][10] ={{0, 1, 0, 1, 0,0},
                    {0, 0, 1, 1, 0,0},
                    {0, 0, 0, 1, 1,1},
                    {0, 0, 0, 0, 1,1},
                    {0, 0, 0, 0, 0,1},
                    {0, 0, 0, 0, 0,0}};
    int n=6;
    topological(m,n);
}

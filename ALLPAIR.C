#include<stdio.h>
#include<conio.h>
int min(int,int);
void main()
{
int n,k,cost[10][10],a[10][10],i,j,p[10];
clrscr();
printf("enter the no of vertices\n");
scanf("%d",&n);
printf("enter cost");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
scanf("%d",&cost[i][j]);
}
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i!=j)
{
a[i][j]=cost[i][j];
}
else
a[i][j]=0;
}
}
for(k=0;k<n;k++)
{
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}
}
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
printf("%d\t",a[i][j]);
}
printf("\n");
}
getch();
}
int min(int a,int b)
{
int min;
if(a<b)
min=a;
else
min=b;
return min;
}

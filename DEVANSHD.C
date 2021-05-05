#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
int n,i,x[10],y[10],w,j;
clrscr();
printf("enter number of elements");
scanf("%d",&n);
for(i=0;i<n;i++)
{
scanf("%d",&x[i]);
}
switch(n)
{
case 1: w=1;break;
case 2: w=-1;break;
}
for(i=0;i<n;i++)
{
y[i]=0;
j=0;
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
y[i]=y[i]+x[j]*pow(w,i*j);
}
}
for(i=0;i<n;i++)
{
printf("%d\n",y[i]);
}
getch();
}
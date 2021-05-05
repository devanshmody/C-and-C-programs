#include<stdio.h>
#include<conio.h>
struct fft
{
int real,img;
};
struct fft z[5];
void main()
{
	int x[10],i,n,y[10];
	clrscr();
	printf("Enter number of elements:\n" );
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter element:\n");
		scanf("%d",&x[i]);
	}
		y[0]=x[0]+x[2];
		y[1]=x[0]-x[2];
		y[2]=x[1]+x[3];
		y[3]=x[1]-x[3];
	for(i=0;i<4;i++)
	{
		printf("y[%d]= %d\n",i,y[i]);
	}
	for(i=0;i<4;i++)
	{
		z[i].real=z[i].img=0;
	}
	z[0].real=y[0]+y[2];
	z[1].real=y[1];
	z[1].img=-1*y[3];
	z[2].real=y[0]-y[2];
	z[3].real=y[1];
	z[3].img=y[3];
	for(i=0;i<4;i++)
	{
		printf("%d + %dj\n",z[i].real,z[i].img);
	}

	getch();
}
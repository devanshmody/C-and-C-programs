#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
float x,y,x1,y1,x2,y2,e,dx,dy,length;
int i,gd,gm;
clrscr();
printf("enter for x1:");
scanf("%f",&x1);
printf("enter for y1:");
scanf("%f",&y1);
printf("enter for x2:");
scanf("%f",&x2);
printf("enter for y2:");
scanf("%f",&y2);
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"");
dx=abs(x2-x1);
dy=abs(y2-y1);
x=x1;
y=y1;
e=(2*dy)-dx;
i=1;
if(dx==0)
{
while(y<=y2)
{
putpixel(x,y,15);
y++;
}
}
else
{
do
{
putpixel(x,y,15);
while(e>=0)
{
y=y+1;
e=e-(2*dx);
}
x=x+1;
e=e+(2*dy);
i=i+1;
}
while(i<=dx);
}
getch();
closegraph();
}



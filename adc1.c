#include<regx51.h>
#define input P1
#define output P0
sbit wr=P3^5;
sbit rd=P3^6;
sbit intr=P3^4;
sbit cs=P3^7;
void delay(unsigned int msec)
{
int i,j;
for(i=0;i<msec;i++)
for(j=0;j<1275;j++);
}
void main()
{
input=0xff;
intr=1;
rd=1;
wr=1;
cs=0;
while(1)
{
wr=0;
delay(1);
wr=1;
while(intr==1);
rd=0;
output=input;
delay(1);
intr=1;
rd=1;
}
}
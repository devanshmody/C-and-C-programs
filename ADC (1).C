#include <REGX51.H>
#define input P1 //ADC Port
#define output P2
sbit rd=P0^1; //Read signal P1.0
sbit wr=P0^2; //Write signal P1.1
sbit cs=P0^0; //Chip Select P1.2
sbit intr=P0^3; //INTR signal P1.3
void delay(int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<1275;j++)
		{
		}
	}
}
void main() 
{
	char a;
	P1=0Xff;
	intr=1;
	rd=1;
	wr=1;
	cs=0;
	while(1)
	{	
		P2=0Xff;
		wr=0;
		delay(1);
		wr=1;
		while(intr==1)
		{
			rd=0;
			a=input;
			output=a;
			delay(1);
					intr=0;
		rd=1;
			//P1=0xff;
			delay(10);
		}
	}
}

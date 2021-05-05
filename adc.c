#include<reg51.h>
#define input P1  		//Input port to read the values of  ADc
#define output P0 	// Output port, connected to LED's.
sbit wr= P3^5; 		// Write pin. It is used to start the conversion.
sbit rd= P3^6; 		// Read pin. It is used to extract the data from internal register to the output pins of ADC.
sbit intr= P3^4; 		// Interrupt pin. This is used to indicate the end of conversion. It goes low when conversion is complete.
void delay(unsigned int msec ) // The delay function provides delay in msec.
{ 
int i,j ;
for(i=0;i<msec;i++)
 		for(j=0; j<1275; j++);
}
void main()
{ 
input=0xff; 	// Declare port 1 as input port.
intr=1;
rd=1;
wr=1;
while(1)
{
wr=0;
delay(100);
wr=1;
while(intr==1);
rd=0;
output=input;
delay(1);
intr=1;
rd=1;
}
}


//file name:circonv.cpp
/*------------- Circular Convolution of two sequences ---------------*/
//
//      This program computes the circular convolution of two causal
//     	sequences x(n) and h(n).
//
//	Inputs :  1. Length of the sequences i.e. N
//		  2. Samples of the two sequences to be convolved
//
//	Outputs :    Circular convolution sequence of x(n) and h(n)
//
//	Assumptions: The given sequences are causal and real.
//---------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
   float h[20],x[20],y[20],sum;
   int N,M,n,k,m;
   clrscr();
   printf("\t\t\tCircular Convolution\n\n");

   printf("Enter the value of N = ");
   scanf("%d",&N);                       // length of the two sequences
   printf("Enter the sequence h(n)\n");
   for(n = 0; n < N; n++)
   {
      printf("h[%d] = ",n);               // Entering the sequence h(n)
      scanf("%f",&h[n]);
   }
   printf("Enter the sequence x(n)\n");
   for(n = 0; n < N; n++)
   {
      printf("x[%d] = ",n);               // Entering the sequence x(n)
      scanf("%f",&x[n]);
   }

// Next nested for loop calculates circular convolution

   printf("\nThe circular of convolution is...");
   for(m = 0; m < N; m++)
   {
      sum = 0.0;
      for(k = 0; k < N; k++) //computation of one value in circular
      {//					            convolution
	if((m-k) >= 0) n = m-k;                          //modulo index
	  else n = m-k+N;
	sum += x[k] * h[n];
      }
      y[m] = sum;
      printf("\ny[%d] = %f",m,y[m]);
   }                                  // displaying the value on screen
}
//----------------------------End of program---------------------------

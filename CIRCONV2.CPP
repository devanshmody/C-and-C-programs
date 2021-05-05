//file name:cirvonv2.cpp
/*------------- Circular Convolution using DFT and IDFT -------------*/
//
//      This program computes the circular convolution of two causal
//     	sequences x(n) and h(n) using DFT and IDFT.
//
//	Inputs :  1. Length of the sequences i.e. N
//		  2. Samples of the two sequences to be convolved
//
//	Outputs :    Circular convolution sequence of x(n) and h(n)
//
//	Assumptions: The given sequences are real and causal.
//---------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
   float h[20],x[20],y[20],pi;
   float HReal[20],HImag[20],XReal[20],XImag[20],YReal[20],YImag[20];
   float N,M,n,k,m;
   clrscr();
   printf("\t\tCircular Convolution using DFT and IDFT\n\n");

   printf("Enter the value of N = ");
   scanf("%f",&N);                       // length of the two sequences
   printf("Enter the sequence h(n)\n");
   for(n = 0; n < N; n++)
   {
      printf("h[%1.0f] = ",n);            // Entering the sequence h(n)
      scanf("%f",&h[n]);
   }
   printf("Enter the sequence x(n)\n");
   for(n = 0; n < N; n++)
   {
      printf("x[%1.0f] = ",n);            // Entering the sequence x(n)
      scanf("%f",&x[n]);
   }

// Next nested for loop calculates DFT of h(n) i.e. H(k)

   pi = 22.0/7.0;                                        // value of pi
   for(k = 0; k < N; k++)
   {             // this loop computes real and imaginary parts of H(k)
      HReal[k] = HImag[k] = 0.0;
      for(n = 0; n < N; n++)   // this loop computes real and imaginary
      {//                               parts of H(k) at one value of k
	 HReal[k] = HReal[k] + h[n]*cos((2*pi*k*n)/N);    //  real H(k)
	 HImag[k]= HImag[k]+ h[n]*sin((2*pi*k*n)/N);   //imaginary H(k)
      }
      HImag[k]= HImag[k]*(-1.0);
   }                             //inversion of imaginary value of H(k)

// Next nested for loop calculates DFT of x(n) i.e. X(k)

   for(k = 0; k < N; k++)
   {             // this loop computes real and imaginary parts of X(k)
      XReal[k] = XImag[k] = 0.0;
      for(n = 0; n < N; n++)   // this loop computes real and imaginary
      {//                               parts of X(k) at one value of k
	 XReal[k] = XReal[k] + x[n]*cos((2*pi*k*n)/N);    //  real X(k)
	 XImag[k]= XImag[k]+ x[n]*sin((2*pi*k*n)/N);   //imaginary X(k)
      }
      XImag[k]= XImag[k]*(-1.0);
   }                             //inversion of imaginary value of X(k)

// next loop multiplies the two DFTs H(k) and X(k)

   for(k = 0; k < N; k++)
   {
      YReal[k] = HReal[k]*XReal[k] - HImag[k]*XImag[k];
      YImag[k] = HReal[k]*XImag[k] + HImag[k]*XReal[k];
   }

// next part of the program computes inverse DFT

   for(n = 0; n < N; n++)
   {
      y[n] = 0;
      for(k = 0; k < N; k++)    // this loop computes one value of x(n)
      {
	 y[n] = y[n] + YReal[k]*cos((2*pi*k*n)/N)
		      - YImag[k]*sin((2*pi*k*n)/N);
      }
      y[n] = y[n]/N;
   }
// next loop prints sequence y(n) on the screen
   printf("\nThe circular of convolution is...");
   for(n = 0; n < N; n++)
      printf("\ny[%1.0f] = %f",n,y[n]);
				      // displaying the value on screen
}
//----------------------------End of program---------------------------
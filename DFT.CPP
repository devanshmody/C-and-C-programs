//file name : dft.cpp
/*----------------- Discrete Fourier Transform(DFT) -----------------*/
//
//	This program computes the N point DFT of the sequence x(n)
//      of length N.
//
//                 Inputs :  1. Number of samples of x(n), i.e. N
//			     2.	Values of samples of x(n)
//
//		  Outputs :     N point DFT X(k) with its real
//                              real and imaginary parts.
//
//	      Assumptions :     The sequence x(n) is considered real.
//---------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
void main()
{
     float static x[100],XReal[100],XImag[100],pi;
     float k,n,N;

     clrscr();
     printf("\t\t\tDiscrete Fourier Transform(DFT)\n");
     printf("\nEnter the number samples in the sequence x(n), N = ");
     scanf("%f",&N);                       // number of samples in x(n)
     printf("\nEnter the samples of sequence x(n)\n");
     for(n = 0; n < N; n++)
     {
       printf("x(%1.0f) = ",n);      // enter values of samples of x(n)
       scanf("%f",&x[n]);
     }

//   next part of the program computes real and imaginary parts of X(k)

     pi = 22.0/7.0;                                     // value of pi
     for(k = 0; k < N; k++)
     {           // this loop computes real and imaginary parts of X(k)
	XReal[k] = XImag[k] = 0.0;
	for(n = 0; n < N; n++) // this loop computes real and imaginary
	{//                             parts of X(k) at one value of k
	   XReal[k] = XReal[k] + x[n]*cos((2*pi*k*n)/N);  //  real X(k)
	   XImag[k]= XImag[k]+ x[n]*sin((2*pi*k*n)/N); //imaginary X(k)
	}
	XImag[k]= XImag[k]*(-1.0);
     }                           //inversion of imaginary value of X(k)

//   Next part of program displays X(k) on the screen

     printf("\nThe %1.0f point DFT of given sequence is...",N);
     printf("\n\tReal X(k)\t\tImaginary X(k)");
     for(k = 0; k < N; k++)
	printf("\nX(%1.0f) =  %3.6f\t\t  %3.4f",k,XReal[k],XImag[k]);
}
//---------------------------End of program---------------------------------

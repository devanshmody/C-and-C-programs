//file name : convztr.cpp
/*------------- Linear Convolution using z-transform ----------------*/
//
//      This program computes the Linear Convolution of two causal
//     	sequences x(n) and h(n) using z-transform.
//
//	Inputs :  1. Number of samples in h(n)
//		  2. Samples of h(n) in the form
//				h[0],h[1],h[2],.....h[N-1]
//		  3. Number of samples in x(n)
//		  4. Samples of x(n) in the form
//				x[0],x[1],x[2],.....x[M-1]
//
//	Outputs :    Convolution sequence of x(n) and h(n)
//
//	Assumptions: The given sequences are causal and real.
//---------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
   float h[20],x[20],y[20],sum;
   int N,M,n,k;

   clrscr();
   printf("\t\tLinear Convolution using z-transform\n\n");
   for(n = 0; n < 20; n++) h[n] = x[n] = 0;
//                                  initializing the sequences to zeros
   printf("Enter the number of samples in h(n) = ");
   scanf("%d",&N);                         // number of samples in h(n)
   printf("Enter the sequence h(n)\n");
   for(n = 0; n < N; n++)
   {                             // This loop accepts the sequence h(n)
      printf("h[%d] = ",n);
      scanf("%f",&h[n]);
   }

   printf("Enter the number of samples in x(n) = ");
   scanf("%d",&M);                         // number of samples in x(n)
   printf("Enter the sequence x(n)\n");
   for(n = 0; n < M; n++)
   {                             // This loop accepts the sequence x(n)
      printf("x[%d] = ",n);
      scanf("%f",&x[n]);
   }
   if(M > N)
   {         // Adjustment of the indices M an N according to the logic
      n = N; N = M; M = n;
   }

// The next two for loops calculate convolution of h(n) and x(n)

   for(n = 0; n < N; n++)
   {                     // This loop calculates first N values of y(n)
      sum = 0.0;
      for(k = 0; k <= n; k++)
      {
	 sum += h[k] * x[n-k]; // see logic of this program for details
      }
      y[n] = sum;
   }
   for(n = 1; n < N; n++)
   {                   // This loop calculates remaining values of y(n)
      sum = 0.0;
      for(k = n; k < N; k++)
      {
	 sum += h[k] * x[N-1-k+n];
      }                        // see logic of this program for details
      y[N-1+n] = sum;
   }
//Calculation of convolution completes here. Next loop displays results
//                                                        on the screen
   printf("\nThe result of convolution is...");
   for(n = 0; n < (N+M-1); n++) //This loop displays y(n) on the screen
      printf("\ny[%d] = %f",n,y[n]);
}
//----------------------------End of program---------------------------
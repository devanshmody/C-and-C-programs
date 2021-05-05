// Implementation of general difference equation based array mapping
//
//      This program implements the difference equation of the LSI
//     	system which is given as,
//
//      y(n) = -[a1*y(n-1)+a2*y(n-2)+a3*y(n-3)+........]
//                +b0*x(n)+b1*x(n-1)+b2*x(n-2)+.......
//
//                 Inputs :  1. Number of coefficients ak, denoted as N.
//			     2.	Values of a1,a2,a3,.....etc.
//                           3. Number of coefficients bk, denoted as M.
//			     4.	Values of b0,b1,b2,.....etc.
//                           5. Number of samples of x(n), denoted as L.
//			     6.	Values of x(0),x(1),x(2),.....etc.
//
//		  Outputs :     The computed output sequence y(n)
//				according to the specified format of
//				difference equation as above.
//
//	      Assumptions :  1. The number of samples computed for y(n)
//				are same as number of input samples.
//                           2. All initial conditions are assumed zero.
//
//                   Note :     Actually there is no specific formula
//				for number of samples in y(n). Because
//				samples in y(n) depend upon type of input
//                              x(n), coefficients ak and bk and initial
//                              conditions.
//
//------------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
   float a[10],b[10],x[100],y[100],sumXn_k,sumYn_k;
   int N,M,k,L,n;
   clrscr();

   printf("   Implementation of general difference"
	  " equation based array mapping\n");
   printf("\nEnter the number of coefficients a[k] i.e. N = ");
   scanf("%d",&N);              // number of ak i.e N
   printf("Enter the values coefficients a[k] \n");
   for(k = 1; k <= N; k++)      // values of a1,a2,a3,...etc.
   {
     printf("a%d = ",k);
     scanf("%f",&a[k]);
   }

   printf("\nEnter the number of coefficients b[k] i.e. M = ");
   scanf("%d",&M);               // number of bk i.e M
   printf("Enter the values coefficients b[k] \n");
   for(k = 0; k < M; k++)        // values of b0,b1,b2,...etc.
   {
     printf("b%d = ",k);
     scanf("%f",&b[k]);
   }
   printf("\nEnter the number of samples of x(n) ");
   scanf("%d",&L);                // number of samples of x(n)
   for(k = 0; k < L; k++)
   {                              // values of x(0),x(1),x(2),...etc.
     printf("x(%d) = ",k);
     scanf("%f",&x[k]);
   }

   printf("\nThe computed values of y(n) are as follows...\n");
   for(n = 0; n < L; n++)         // computation of y(n)
   {
     sumYn_k = 0;
     sumXn_k = 0;
     for(k = 1; (k <= n)&&(k <= N); k++)
     {        // computation of a1*y(n-1)+a2*y(n-2)+a3*y(n-3)+......
       sumYn_k += a[k] * y[n-k];
     }
     for(k = 0; (k <= n)&&(k < M); k++)
     {        // computation of b0*x(n)+b1*x(n-1)+b2*x(n-2)+......
       sumXn_k += b[k] * x[n-k];
     }
     y[n] = - sumYn_k + sumXn_k;  // final value of y(n)
     printf("\ny(%d) = %f",n,y[n]);
   }
}
//----------------------------End of program------------------------------

//file name : biliner.cpp
/*----- Butterworth filter design using Bilinear transformation -------*/
//
//      This program computes the system function of Butterworth filter
//      by using bilinear transformation. It computes the coefficients
//      of the cascaded second order sections.
//
//                 Inputs :  1. Order of the butterworth filter, i.e. N
//			     2.	Cutoff frequency of digital filter, wc
//
//		  Outputs :     Coefficients of cascaded second
//                              order sections of digital filter.
//
//	      Assumptions :     The cascaded second order sections
//                              can be described as follows..
//
// H(z) = H1(z) * H2(z) * H3(z). . .
//
//           b00 + b01z^-1 + b02z^-2      b10 + b11z^-1 + b12z^-2
// H(z) = B0 ----------------------- * B1 ----------------------- * ...
//           a00 + a01z^-1 + a02z^-2      a10 + a11z^-1 + a12z^-2
//
//---------------------------------------------------------------------
#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
     float B[20],b[20][3],a[20][3],pReal,pImag;
     float wc,N,pi,Theta,omegaC,den;
     int k;

     clrscr();
     printf("\t\tButterworth filter design using Bilinear "
						 "transformation\n\n");
     printf("Enter the order of the filter  N = ");
     scanf("%f",&N);                             // order of the filter
     printf("\nEnter the cutoff frequency of digital filter wc = ");
     scanf("%f",&wc);     // cutoff frequency of digital filter i.e. wc

     omegaC = tan(wc/2);  // cutoff frequency of equivalent analog
//                            filter by bilinear frequency relationship
     pi = 22.0/7.0;                                      // value of pi

//   The following loop computes the values of first  N/2  poles, since
//   next N/2 poles are complex conjugates first ones.    It calculates
//   real and imaginary parts of poles. Real value is made positive and
//   imaginary value is always positive for first N/2 poles.
     for(k = 0; k < N/2; k++)// loop for computation of first N/2 poles
     {
       Theta = ((N+2*k+1)*pi)/(2*N);              // angle of k'th pole
       pReal = -1*omegaC*cos(Theta); // real part of pole made positive
       pImag = omegaC*sin(Theta);             // imaginary part of pole

	 den = 1+2*pReal+pReal*pReal+pImag*pImag;
	B[k] = (omegaC*omegaC)/den;                // calculation of Bk

       b[k][0] = 1;   //|    for all the sections the value of bk0 = 1,
       b[k][1] = 2;   //|           bk1 = 2 & bk2 = 1. These values are
       b[k][2] = 1;   //|                fixed(see theory for details).

       a[k][0] = 1;                         // value of ak0 is always 1
       a[k][1] = (2*(pReal*pReal+pImag*pImag)-2)/den;            // ak1
       a[k][2] = (1-2*pReal+pReal*pReal+pImag*pImag)/den;        // ak2
		      // the above two statements calculate ak1 and ak2
     }

//   If N has odd  value then one pole lies on real axis. This pole has
//   no complex conjugate.  This pole  generates first order section in
//   H(z). Next loop computes coefficients of this section.
     if((N/2) != k)
     {
       k--;             // recompute the pole without complex conjugate

       den = omegaC+1;
       B[k] = omegaC/den;                          // calculation of Bk

       b[k][0] = 1;  //|   for first order section bk0 = 1, bk1 = 1 and
       b[k][1] = 1;  //|         bk2 = 0 always. These values are fixed
       b[k][2] = 0;  //|                     and need not be calculated

       a[k][0] = 1;                         // value of ak0 is always 1
       a[k][1] = (omegaC-1)/den;                  // calculation of ak1
       a[k][2] = 0;          // ak2 is always 0 for first order section

     }

//   Next loop prints the coefficients on the screen sectionwise
     printf("\nThe coefficients of cascaded second order sections "
			     "of digital\nfilter are as follows...\n");
     for(k = 0; k < N/2; k++)
     {
       printf("\nB%d = %f\tb%d0 = %f\ta%d0 = %f"
					  ,k,B[k],k,b[k][0],k,a[k][0]);
       printf("\n\t\tb%d1 = %f\ta%d1 = %f",k,b[k][1],k,a[k][1]);
       printf("\n\t\tb%d2 = %f\ta%d2 = %f\n",k,b[k][2],k,a[k][2]);
     }
}
//---------------------------End of program---------------------------------

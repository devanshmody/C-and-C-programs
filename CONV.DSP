/*-------------Convolution program using ADSP 2101 programming language--------------------*/
/*  The program computes the convolution between two sequences x(n) and h(n) to produce
    output sequence y(n).
      Inputs : 1.Input sequence x(n) from file X(n).dat
	       2.Input sequence h(n) from file H(n).dat

      Outputs : Output sequence y(n).
-------------------------------------------------------------------------------------------*/
.MODULE      conv;       /*Name of the module or program*/
.CONST  M=3;             /*constant defining the size of the h(n) array*/
.CONST  N=3;             /*constant defining the size of the x(n) array*/
.VAR/DM/CIRC/ABS = 0x10  h[M];/*variable defining the circular array h(n) of size M and whose
				starting address is 0x10*/
.VAR/DM/CIRC/ABS = 0x20  x[M+N-1];/*variable defining the circular array x(n) of size M+N-1
				    and whose starting address is 0x20*/
.VAR/DM/ABS      = 0x30  y[M+N-1];/*variable defining the linear array y(n) of size M+N-1
				    and whose starting address is 0x30*/
.INIT h:<H(n).dat>;    /*Initialise the array h(n) with the contents of the file H(n).dat*/
.INIT x:<X(n).dat>;    /*Initialise the array x(n) with the contents of the file X(n).dat*/

JUMP start; NOP; NOP; NOP; /*These instructions are stored at the interrupt vector locations
RTI; NOP; NOP; NOP;         and contain instructions which are executed when an interrupt
RTI; NOP; NOP; NOP;         occurs.The various interrupts are the hardware reset,SPORT1
RTI; NOP; NOP; NOP;         receive and transfer interrupts,SPORT0 receive and transfer
RTI; NOP; NOP; NOP;         interrupts and the timer interrupt.Since in this program we are
RTI; NOP; NOP; NOP;         only using the Hardware reset interrupt we write a 'JUMP start'
RTI; NOP; NOP; NOP;         at the vector location so that the program begins execution at
			    the instructon with label start after hardware reset occurs*/

start: I0 = ^h + M-1; /*Initialises the DAG1 index register I0 with the end address of array h(n)*/
       L0 = %h;    /*Initialises the DAG1 length register L0 with the length of array h(n)*/
       I1 = ^x;   /*Initialises the DAG1 index register I1 with the starting address of array x(n)*/
       L1 = %x;    /*Initialises the DAG1 length register L1 with the length of array x(n)*/
       I2 = ^y;   /*Initialises the DAG1 index register I2 with the starting address of array y(n)*/
       L2 = 0;    /*Initialises the DAG1 length register L2 with zero to indicate that it is
		    not a circular buffer*/
       M0 = -1;    /*Initialises the DAG1 modify register M0 with -1 to autodecrement by 1*/
       M1 = N;     /*Initialises the DAG1 modify register M1 with N to autoincrement by N*/
       M2 = 1;     /*Initialises the DAG1 modify register M2 with 1 to autoincrement by 1*/

       ENA M_MODE;  /*Sets the MAC result placement mode bit in the MSTAT register to enable
		      1.15 format arithmetic*/
       CNTR = M+N-1;    /*Initialise counter with M+N-1 for outer loop of y(n) calculation*/
       DO loop1 UNTIL CE;    /*Execute counter till counter expires*/
       CNTR = M;         /*Initialise counter with M for inner loop of convolution addition*/
       MR = 0;              /*Initialse MAC result register with zero*/
       DO loop2 UNTIL CE;    /*Execute instructions upto label loop2 till counter expires*/
       MX0 = DM(I0,M0);     /*Initialise MAC MX0 register with the contents of Data memory
			       whose address is pointed to by I0 register*/
       MY0 = DM(I1,M2);       /*Initialise MAC MY0 register with the contents of Data memory
				whose address is pointed to by I1 register*/
loop2: MR = MR + MX0 * MY0 (SS);     /*Main convolution loop*/
       DM(I2,M2) = MR0; /*The calculated value of the element of array y(n) is transferred to
			 data memory location pointed to by I2 register*/
loop1: MODIFY(I1,M1);  /*Change the base address of the x(n) loop after one convolution loop
			to point one location ahead of the location pointed to in the
			previous convolution loop to indicate one bit shift*/

.ENDMOD;   /*End of module or program*/









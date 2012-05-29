#include "Vect.h"
#include <stdio.h>

int main(int argc, char** argv)
{
	printf("_____Vector module test____\n");
	Vect V1(3);
	if( V1.size() != 3 )
	{
		printf("\t!!!Size function test not passed!!! Shutting down...\n");
		return 1;
	}
	else
		printf("\tSize function test passed...\n");
	Vect resVect;
	V1.SetElement( 0, 1 );
	V1.SetElement( 1, 2 );
	V1.SetElement( 2, 5 );
	Vect V2(V1);
	if( 	( V2[0] != 1 ) ||
	 	( V2[1] != 2 ) ||
		( V2[2] != 5 ))
	{
		printf("\t!!!Copy constructor or operator '[]' function not passed!!! Shutting down...\n");
		return 1;
	}
	else
		printf("\tCopy constructor and operator '[]' function passed...\n");
	long double *n = new long double[3];
	n[ 0 ] = 1;
	n[ 1 ] = 2;
	n[ 2 ] = 5; 
	V2 = Vect( n, 3);
	delete [] n;
	if( 	( V2[0] != 1 ) ||
	 	( V2[1] != 2 ) ||
		( V2[2] != 5 ))
	{
		printf("\t!!!'Array' constructor or operator '=' function not passed!!! Shutting down...\n");
		return 1;
	}
	else
		printf("\t'Array' constructor and operator '=' function passed...\n");
	resVect = V1 + V2;
	if( 	( resVect[0] != 2 ) ||
	 	( resVect[1] != 4 ) ||
		( resVect[2] != 10 ))
	{
		printf("\t!!!Operator '+' function not passed!!! Shutting down...\n");
		return 1;
	}
	else
		printf("\tOperator '+' function passed...\n");
	resVect	+= V1;
	if( 	( resVect[0] != 3 ) ||
	 	( resVect[1] != 6 ) ||
		( resVect[2] != 15 ))
	{
		printf("\t!!!Operator '+=' function not passed!!! Shutting down...\n");
		return 1;
	}
	else
		printf("\tOperator '+=' function passed...\n");
	resVect = V1 * 2;
	if( 	( resVect[0] != 2 ) ||
	 	( resVect[1] != 4 ) ||
		( resVect[2] != 10 ))
	{
		printf("\t!!!Operator '*' function not passed!!! Shutting down...\n");
		return 1;
	}
	else
		printf("\tOperator '*' function passed...\n");
	if( (V1 != V2) || ( resVect == V1 ) || ( resVect == V2 ))
	{
		printf("\t!!!Operator '!=' or '==' function not passed!!! Shutting down...\n ");
		return 1;	
	} 
	else
		printf("\tOperator '!=' and '==' function passed...\n ");
	printf("\tEverything is fine. Shutting down...\n");
	return 0;
}

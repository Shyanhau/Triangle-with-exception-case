#include "Triangle.h"
#include "CException.h"
#include <stdio.h>

char *getTriangleName(int side1, int side2, int side3)

{	
	if (side1 ==0 || side2 ==0 || side3 ==0)
		return "invalid";
	else if (side1 < 0 || side2 < 0 || side3 < 0 )  
		return "invalid";
	else if ( ((side1 + side2) < side3 ) || ((side1 + side3) < side2 ) || ((side2 + side3) < side1))
		return "invalid";
else	
	{
	
	if (side1==side2 && side2==side3)
		return "equilateral";
	else if(side1 == side2 || side2 == side3 || side1 == side3)
		return "isosceles";
	else if ((side1 != side2) && (side1 != side3))
		return "scalene";
		
	}
	
}

int areLengthsAllStrictlyPositive(int side1 , int side2, int side3)
{
	if( side1 <= 0 || side2 <= 0 ||side3 <= 0)
	  Throw(ERR_LENGTH_IS_NOT_STRICTLY_POSITIVE);
	  
}

int isTriangle(int side1, int side2, int side3) 
{
	if( ((side1 + side2) < side3 ) || ((side1 + side3) < side2 ) || ((side2 + side3) < side1))
		Throw(ERR_NOT_TRIANGLE);
}
	

	
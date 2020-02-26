#include <limits.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/*
 * TODO: explain this function
 */
unsigned long convertDouble(double v) {

  double * d = &v;
  unsigned long * ulongp = (unsigned long *) d;
  unsigned long val = *ulongp;
  return val;
}

/*
 * TODO: explain this function
 */
unsigned int convertFloat(float v) {
  float * f = &v;
  unsigned int * uintp = (unsigned int *) f;
  unsigned int val = *uintp;
  return val;
}

/*
 * TODO: complete this function, given this description:
 *
 * Returns whether or not x is less than or equal to y
 * by examining its underlying bit level representation.
 * A return value of 1 indicates x is <= y.
 *
 */
 int float_le(float x, float y) {
	unsigned ux = convertFloat(x);
	unsigned uy = convertFloat(y);
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;
	
	return 0;  //////!!!! replace this with correct code
    	
}

/*
 * TODO: complete this function, given this description:
 *
 * Returns whether or not x is greater than or equal to y
 * by examining its underlying bit level representation.
 * A return value of 1 indicates x is >= y.
 *
 */
int float_ge(float x, float y) {
  unsigned ux = convertFloat(x);
	unsigned uy = convertFloat(y);
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;

  return  0;  //////!!!! replace this with correct code
    
}


/*
 *
 *  This function creates a string representing the binary
 *  number that is stored for a given input unsigned integer.
 */
void uint_binary(unsigned int input, char* result) {
	int most_significant_bit = (sizeof( unsigned int)*8) - 1;

	strcpy(result, "");

    int i;
    for(i = most_significant_bit; i >= 0; --i) {
        if(input & (1 << i)) {
            strcat(result, "1");
        } else {
			strcat(result, "0");
		}
		if ((i % 4) == 0) {
      	 strcat(result, " ");
      	}
	}
}

/*
 * TODO: complete this comment
 */

#include <stdio.h>    // for printf
#include <string.h>   // for string operations (strcpy)
// Add more #includes if you need them


/*
 * TODO: explain this function
 */
unsigned int convertFloat2Bits(float v) {
  float * f = &v;
  unsigned int * uintp = (unsigned int *) f;
  unsigned int val = *uintp;
  return val;
}


/*
 * TODO: explain this function
 */
float convertBits2Float(unsigned int bitv) {
  unsigned int *f = &bitv;
  float *fp = (float *) f;
  float val = *fp;
  return val;
}


/*
 * TODO: explain this function
 */
unsigned long convertDouble2Bits(double v) {

  double * d = &v;
  unsigned long * ulongp = (unsigned long *) d;
  unsigned long val = *ulongp;
  return val;
}

/*
 * TODO: explain this function
 */
double convertBits2Double(unsigned long bitv) {
  unsigned long *f = &bitv;
  double *fp = (double *) f;
  double val = *fp;
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
	unsigned ux = convertFloat2Bits(x);
	unsigned uy = convertFloat2Bits(y);
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;
	
    // TODO: replace the line below with your solution to this problem
	return 0;
    	
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
  unsigned ux = convertFloat2Bits(x);
	unsigned uy = convertFloat2Bits(y);
	unsigned sx = ux >> 31;
	unsigned sy = uy >> 31;

   // TODO: replace the line below with your solution to this problem
   return  0;
    
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
		if ((i % 4) == 0 && i != 0) {   //pretty print a space between 4 bits
      	 strcat(result, " ");
      	}
	}
}

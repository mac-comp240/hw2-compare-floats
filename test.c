/*
 * TODO: add file description/authorship
 */

#include <stdio.h>   // for printf
#include <assert.h>  // for assert
// Add more #includes if you need them


// declarations
unsigned int convertDouble2Bits(double v);
unsigned int convertFloat2Bits(float v);
int float_le(float x, float y);
int float_ge(float x, float y);
void uint_binary(unsigned int input, char* result);


int main() {
	float x;
	float y;
    
	//holds binary representation of each value for debugging
	char bin[sizeof(unsigned int)*9 +1];

	x = -4.5;
	y = 5.0;
	// --------------------------------------------------------
    // check if results have the correct representation (for debugging)
    // remove this once you are confident in how these work
	unsigned int ux = convertFloat2Bits(x);
	unsigned int uy = convertFloat2Bits(y);
	uint_binary(ux, bin);
	printf("%f has representation %x (%s)\n", x, ux, bin);
	uint_binary(uy, bin);
	printf("%f has representation %x (%s)\n", y, uy, bin);
	// --------------------------------------------------------
	assert(float_le(x,y) == 1);
	assert(float_ge(x,y) == 0);

	x = 5.0;
	y = 5.0;
	// --------------------------------------------------------
    // check if results have the correct representation (for debugging)
    // remove this once you are confident in how these work
	ux = convertFloat2Bits(x);
	uy = convertFloat2Bits(y);
	uint_binary(ux, bin);
	printf("%f has representation %x (%s)\n", x, ux, bin);
	uint_binary(uy, bin);
	printf("%f has representation %x (%s)\n", y, uy, bin);
	// --------------------------------------------------------
	assert(float_le(x,y) == 1);
	assert(float_ge(x,y) == 1);

    // TODO: Add your test calls here

    return 0;
}

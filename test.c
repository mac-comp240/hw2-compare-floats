#include <stdio.h>
#include <assert.h>

//declarations
unsigned int convertDouble(double v);
unsigned int convertFloat(float v);
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

	unsigned int ux = convertFloat(x);
	unsigned int uy = convertFloat(y);

	// debug to see if have correct representation
	uint_binary(ux, bin);
	printf("%f has respresentation %x (%s)\n", x, ux, bin);

	uint_binary(uy, bin);
	printf("%f has respresentation %x (%s)\n", y, uy, bin);
	////// end debug

	assert(float_le(x,y) == 1);
	assert(float_ge(x,y) == 0);

	x = 5.0;
	y = 5.0;
	ux = convertFloat(x);
	uy = convertFloat(y);
	uint_binary(ux, bin);
	printf("%f has respresentation %x (%s)\n", x, ux, bin);

	uint_binary(uy, bin);
	printf("%f has respresentation %x (%s)\n", y, uy, bin);
	assert(float_le(x,y) == 1);
	assert(float_ge(x,y) == 1);

// TODO: work on this loop below and others of your choice
//////// A test that shows how the operator <= would get converted
//////// into a macro function by the machine when used in a
/////// relational expression (in a loop in this case).
/////// The code you would normally write would be:
//////    while (x <= y) { ... }
	x = 5.0;
	y = 10.0;
	while (float_le(x,y)) {
		printf("x: %f, ", x);  // should change to assert here
		x = x + 1.0;
	}
	printf("\n");  // then also don't need this
///////
}

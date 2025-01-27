# Relational Operations on Floating Point numbers

## Overview

In the IEEE 754 floating point representation there are three parts, the sign, the 
exponent, and the mantissa/significand (called n, e, and s, respectively in the book). One of the
benefits of this representation is that the bit-level representations of n, e, and s
can be used to compare two values and determine whether one is less than or equal to the 
other.

When we code with floats or doubles, we shouldn't use them counters in loops or 
compare two floats for equality (because the inherent limits on precision could cause
bad results). But we often have code that might look like use inequalities to
compare doubles or floats, as in this example:
```
double value, threshold;

...

if (value >= threshold) {
    // take action
}
```

To compare two floating point numbers, we will treat the binary representation of each of 
float or double as unsigned integers. We can use bitwise and shift operations to 
extract the sign bit from each number, as well as the exponent and significant/mantissa,
and then we will test a *relatively short* set of cases
using a combination of bitwise operations, shifting operations, and logical operators to test
them. You can either combine the cases into one big boolean expression, or use
if statements to check each case in turn (the first approach is elegant, but harder
to debug, the second is easier to read and debug, but less elegant).

The hardware of the machine implements something like this process: this is how
the comparisons can be done quickly

**Key insight here:** There are actually not very many different cases, so you
may be overthinking things if your code starts to get exceptionally long or exceptionally
complicated!

Your overall tasks are:
- to implement a function, `float_le`, that checks if one `float` is less than or equal
  to another by analyzing their bit representations
- to implement a function, `float_ge`, that checks if one `float` is greater than 
  or equal to another by analyzing their bit representations
- to implement a main function that performs at least 30 separate tests of these two
  functions, testing all combinations of different kinds of floats

### Assignment Rubric

- Overall (4 pts):
    - Correct Makefile, compiles and runs without errors
    - All debugging outputs removed or commented out
    - Clean code style
    - File description and names in file

- In `float_parts.c` (26 pts):
    - Complete, correct descriptive comments for: `convertFloat2Bits`, `convertBits2Float`,
    `convertDouble2Bits`, `convertBits2Double`
    - Correct implementation of `float_le`, based on the binary representation
    and its components, and using bitwise, shifting, and logical operations
    - Correct implementation of `float_ge`, based on the binary representation
    and its components, and using bitwise, shifting, and logical operations
  
- In `test.c` (20 pts):
    - At least 30 properly written test calls that cover the categories of 
    floating-point numbers as described below
    - Extra credit available for finding 21 or more distinct pairings to test

### Starter Code

- `floatParts.c` 
    - This file contains functions to convert floating-point numbers to 
    unsigned integers **with the same binary representation*. You will add
    functions to check floating-point less-than and greater-than when given those
    unsigned integers (so that we can work with the bits of the float representation).
- `test.c`
    - The main program, which will contain your detailed tests of the relative
    comparison functions in `floatParts.c`.


### Execution

The graders should be able to do the following to build and run your code *without errors*:
```
make clean
make
./fp_relational_ops
```

## Tasks to Complete

### Task 1: Create the Makefile for this project

This time, we want you to create the Makefile for this project. You can model it
on previous activities or homeworks. Here are the key points:
- The executable created should be called `fp_relational_ops`
- You must compile together both C files in this project
- You must include a `clean` target that removes the executable and any other files
  created by the compilation process


### Task 2: Build your intuitions

Before you start coding, take some time to build up intuitions about floating-point
values of different sorts, and their binary representations.

Go back through readings, videos, notes, and class activities to understand the different
kinds of numbers (normalized, denormalized, zero, infinity, NaN). Look at the `math.h`
and `float.h` libraries for some helpful constants, but you will need also to do
some calculations or in-depth research for the bounds for denormalized. Notice that -1.0 and 1.0
are interesting cut points where the exponent values shift from negative to positive.

**You will not have to deal with NaN for this assignment, but you will have to handle correctly
all other kinds.**

Determine the boundaries: 
- What does zero look like?
- What does infinity (positive and negative) look like?
- What is the smallest positive denormalized number, and what is the largest positive denormalized number
- What is the smallest positive normalized number?
- Similarly what are they for negative denormalized and normalized numbers

Look at the binary representation for these numbers, and separate them into sign, exponent, and significand/mantissa.
What patterns do you see in those three values when one float is smaller than the other?

Examine the starting `main` function in `test.c`. This function demonstrates how
to call the `convertFloat2Bits` function, and how to print the value as a float,
in hexadecimal, and in binary. Use this to help with your intuitions. (You may
temporarily comment out the assertions that test `float_le` and `float_ge`.)

### Task 3: implement `float_le`

You must complete the implementation of the `float_le` function. This function should take in two
`float` integers, `x` and `y`. It should return 1 if `x` is less than or equal to `y`,
and it should return 1 if `x` is greater than `y`.

You may not use the built-in `<=` operator on `x` and `y`. Instead, the starter
code for the function converts the float values to be unsigned integers, keeping the
same bit-level representation. Use bitwise, shift, and logical operations to extract
the sign bit, and perhaps exponent and significand parts. Then check boolean 
expressions to test the different cases (either combined in one big boolean expression
or written as a set of `if` statements). Return the correct result.

**Note:** While you may not use `<=` on the original `float` numbers, you **may**
use it to compare components of the floating-point representation, like sign, exponent,
significand, etc.

Your function must work correctly when given any combination of valid kinds of 
floats **except `NaN`**. It must also work with values that are strictly less than
and values that are equal.


#### Test as you go!

Examine the `main` function in `test.c`. It includes two pairs of float values and shows
how to check their representations in binary and how to test `float_le` and `float_ge`. 

A major part of your task is to develop and implement thorough testing for these
functions. As you implement each step in the `float_le` function, write tests that
check it!

Read the "Plan out testing" section below for more details.

### Task 4: implement `float_ge`

The `float_ge` function will naturally be similar to the `float_le` one. Implement 
it in much the same way as the `float_le` function.

### Planning out testing

When planning cases to test your functions, think first about the structure of the
data coming into the functions (what kind of floating-point numbers they are), and
second about the structure of your code (making sure that every part of the code
gets tested). 

There are many different kinds of floating-point numbers you should test:
* positive normalized numbers
* positive denormalized numbers
* negative normalized numbers
* negative denormalized numbers
* zero, both +0 and -0
* infinity, both +infinity and -infinity (note the `math.h` library is useful here)
* +1, -1
    - Why is this a special case? Because 1.0 and -1.0 are at the edges between 
    numbers with negative exponents and numbers with positive exponents!

A good mantra for this kind of testing: zero, 1, many, and the edges, in both positive and negative directions.

**How many tests should you have?** Each call to `float_le` or `float_ge` takes
in two numbers. Given two numbers that are equal, we can usefully make two test calls
(one each to `float_le` and `float_ge`). Given two numbers that are not equal,
we can usefully make four calls (both orderings of the numbers to both `float_le` and `float_ge`). Given
the categories above, it isn't hard to come up with 16-22 pairings you would want to test,
which leads you to 60-80 actual test calls.

Steps in planning tests:
* Write out a listing of the pairings you think you should test. 
* Determine simple numbers that fit the requirements of each pairing 
    - You don't need to compare values that are extremely close together, except
    for values that are equal
    - To double-check yourself, you may construct a binary representation, assign
    it to an unsigned int using hex notation, and then use the `convertBits2Float`
    function to turn it back into a normal float
* As you implement parts of `float_le` or `float_ge` that relate to a given pairing,
  add the test case to your `main` function


We are fairly generous. You will get full credit if you have at least 30 test calls,
and they cover the categories listed above, at least partially. You will get
extra credit for covering more than 20 pairings, each distinct.

#### Correctly formatted tests

Your tests should include:
* a comment describing what is being tested
* assert statements that call `float_le` or `float_ge` and check the result against the correct answer

Do not include print statements. You may add them for debugging, but comment them out
or remove them in the final code.

**Your executable should, in its final form, produce no output.**

## Submission

When you have completed the **code** for this assignment, make sure to complete the **report** 
before final submission. Submit your report in a new file called `TURNIN.md`. Your report should include:

* A list of known bugs or issues in the code.
    * Give as much detail as necessary for a grader to understand the issue! Do not write only that something does not work.
* What challenges you faced while completing the assignment.
    * Reflect on the experience of doing this work. What were some of the sticking points? Did you get help? How did you solve them?
* What you learned through completing this assignment.
    * Reflect on your learning. Did the assignment illustrate any course concepts or build on what you practiced in the activities? Is there anything that you understand better because of this homework?



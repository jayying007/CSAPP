/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  return ~(x & y) & ~(~x & ~y);
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // add !!(x+1) because of the 0xffffffff
  //return !((x + 1) ^ (~x)) & !!(x + 1);
  // another solution
  return !(x ^ ~(1 << 31));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // try to build the mask 1010....1010
  int mask = (0xAA << 8) + 0xAA;
  mask = (mask << 16) + mask;

  return !((mask & x) ^ mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // 0x30 <= x <= 0x39;
  // x - 0x30 >= 0
  // x - 0x3a < 0
  int var0 = x + ~0x30 + 1;
  int var1 = x + ~0x3a + 1;
  
  return !((var0 >> 31) & 1) & ((var1 >> 31) & 1);
  /*
  int var0 = 0x30 ^ x;
  int var1 = 0x31 ^ x;
  int var2 = 0x32 ^ x;
  int var3 = 0x33 ^ x;
  int var4 = 0x34 ^ x;
  int var5 = 0x35 ^ x;
  int var6 = 0x36 ^ x;
  int var7 = 0x37 ^ x;
  int var8 = 0x38 ^ x;
  int var9 = 0x39 ^ x;
  
  return !var0 | !var1 | !var2 | !var3 | !var4 | !var5 | !var6 | !var7 | !var8 | !var9;
  */
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  return (~(~(!x) + 1) & y) + ((~(!x) + 1) & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int signX = (x >> 31) & 1;
  int signY = (y >> 31) & 1;
  // if sign is diff, that x must be negative and y must be positive;
  int signDiff = (signX ^ signY) & signX & !signY;
  // x - y = x + ~y + 1
  int signSame = !(signX ^ signY) & (!(x + ~y + 1) | (((x + ~y + 1) >> 31) & 1));
  
  // make sure to be 0 or 1
  return !!(signDiff | signSame);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // x != 0 ==> x and -x is one positive, the other is negtive, so x | -x , the sign bit must be 1;
  return ((x | (~x + 1)) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // if x == 0 then 1
  int val1 = !(x ^ 0);
  // if x == -1 then 1
  int val2 = !(x ^ (~0));
  // if x != 0 && x != -1 then 0xffffffff
  // if x == 0 || x == -1 then 0
  int val3 = ~(~(val1 | val2) + 1);
  
  int bit_16, bit_8, bit_4, bit_2, bit_1;
  int sum;
  // x < 0 ? op = ~x : op = x
  int op = x ^ (x >> 31);
  
  // whether pre 16 bits have 1
  bit_16 = (!!(op >> 16)) << 4;
  op = op >> bit_16;
  bit_8 = (!!(op >> 8)) << 3;
  op = op >> bit_8;
  bit_4 = (!!(op >> 4)) << 2;
  op = op >> bit_4;
  bit_2 = (!!(op >> 2)) << 1;
  op = op >> bit_2;
  bit_1 = (!!(op >> 1));
  op = op >> bit_1;
  
  sum = 2 + bit_16 + bit_8 + bit_4 + bit_2 + bit_1;
  
  return val1 | val2 | (val3 & sum);
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  int sign = (uf & 0x80000000) >> 31;
  int exp = (uf & 0x7f800000) >> 23;
  int frac = uf & 0x007fffff;
  
  if(exp == 0xff) {
    return uf;
  } else if(exp == 0) {
    if(frac & 0x400000) {
      exp = 1;
    }
    frac = (frac << 1) & 0x007fffff;
  } else {
    exp = (exp + 1) & 0xff;
  }

  return (sign << 31) + (exp << 23) + frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  int sign = uf & 0x80000000;
  int exp = (uf & 0x7f800000) >> 23;
  int frac = uf & 0x007fffff;
  int E = exp - 127;
  
  if(exp == 0xff || E > 30) {
    return 0x80000000u;
  }
  if(E < 0) {
    return 0;
  }
  
  int ans = (frac >> (23 - E)) + (1 << E);
  if(sign) {
    ans = ~ans + 1;
  }
  return ans;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  // somebody says it works in vs2017, but in there, it is a loop.
  if(x >= -126 && x <= 127) {
    return (x + 127) << 23;
  } else if(x < -126) {
    return 0;
  } else {
    return 0xff << 23;
  }
}

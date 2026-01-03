# Intel-Intrinsic-Simplified
A library consisting of easy to use functions of Intel Intrinsic Datatype, the vectors. The library allows for cleaner code writing, without explicitly using Intel's provided functions for intrinsic vector extensions.
Please note that the library is usable ONLY for INTEL based processors.

Intrinsic Type: AVX512F & AVX2

The contents are:
  1. intrin_generic.h  --  All the datatypes, operator overloads
  2. intrin_print.h  --  The printing method
  3. driver.cpp  --  Example implementation of usage of the library
  4. Makefile  --  A windows-usable Makefile for necessary flags for compilation

The datatypes available for usage are as follows:
  1.  **int_4_array_a16**  <>  **long_2_array_a16**
      -> This holds four(4) 32 bit integers or two(2) 64 bit integers(long), all aligned on the 16 byte boundary.
      -> For doing operations with four(4) 32 bit integer operands, or two(2) 64 bit integers at one time.

  2.  **int_8_array_a32**  <>  **long_4_array_a32**
      -> This holds eight(8) 32 bit integers or four(4) 64 bit integers(long), all aligned on the 32 byte boundary.
      -> For doing operations with eight(8) 32 bit integer operands, or four(4) 64 bit integers at one time.

  3.  **int_16_array_a32**  <>  **long_8_array_a32**
      -> This holds sixteen(16) 32 bit integers or eight(8) 64 bit integers(long), all aligned on the 32 byte boundary.
      -> For doing operations with sixteen(16) 32 bit integer operands, or eight(8) 64 bit integers at one time.

  4.  **float_4_array_a16**  <>  **double_2_array_a16**
      -> This holds four(4) 32 bit floating-point numbers or two(2) 64 bit floating-point numbers(double), all aligned on the 16 byte boundary.
      -> For doing operations with four(4) 32 bit floating-point numbers operands, or two(2) 64 bit floating-point numbers at one time.

  5.  **float_8_array_a32**  <>  **double_4_array_a32**
      -> This holds eight(8) 32 bit floating-point numbers or four(4) 64 bit floating-point numbers(double), all aligned on the 32 byte boundary.
      -> For doing operations with eight(8) 32 bit floating-point numbers operands, or four(4) 64 bit floating-point numbers at one time.

  6.  **float_16_array_a32**  <>  **double_8_array_a32**
      -> This holds sixteen(16) 32 bit floating-point numbers or eight(8) 64 bit floating-point numbers(double), all aligned on the 32 byte boundary.
      -> For doing operations with sixteen(16) 32 bit floating-point numbers operands, or eight(8) 64 bit floating-point numbers at one time.

----------------

The operations done on vector usually require intel's intrinsic functions like _mm_add_si128(vecA, vecB), etc.
But, these are directly handled by just using '+' operator (for add) and others correspondingly. (SEE driver.cpp for the example)

Operations Allowed (Happen simultaneously):
  1.  Addition: 
      -> Add 4, 8 or 16 integers, floating-point numbers (32 bit)
      -> Add 2, 4 or 8 integers, floating-point numbers (64 bit)

  2.  Subtraction:
      -> Subtract 4, 8 or 16 integers, floating-point numbers (32 bit)
      -> Subtract 2, 4 or 8 integers, floating-point numbers (64 bit)

  3.  Multiplication:
      -> Multiply 4, 8 or 16 integers, floating-point numbers (32 bit)
      -> Multiply 2, 4 or 8 integers, floating-point numbers (64 bit)

  4.  Division:
      -> Divide 4, 8 or 16 floating-point numbers (32 bit) -- no integers
      -> Divide 2, 4 or 8 floating-point numbers (64 bit) -- no integers

----------------

Printing the vector just involves using std::cout << delim(vector_to_print, delimiter);
Any delimiter string can be used, and the starting and ending limits are "| " and " |" respectively (can be changed in intrin_print.h)

Please provide a star if the library is usable for you! :)

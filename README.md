#Assembly_Compiler

A compiler's backend to produce x86-64 architecture assembly code on Ubuntu Linux, transitioning from a stack machine code format, and integrated support for three new instructions:

1. **Factorial (fact):**
   - The fact function takes one argument (n) and returns the factorial of that number.
   - Example: 5! = 5 * 4 * 3 * 2 * 1 = 120.

2. **Logarithm Base Two (lntwo):**
   - The lntwo function takes one argument (x) and returns the logarithm base two of that number.
   - Example: log₂(8) = 3 because 2^3 = 8.

3. **Greatest Common Divisor (gcd):**
   - The gcd function takes two arguments (a and b) and returns their greatest common divisor.
   - Example: The GCD of 36 and 24 is 12.

To run the compiler:

1. Execute 'make' to build the compiler executables.
2. Run the compiler program, indicating the hypothetical stack machine code.
3. Observe the resulting assembly code and its executable file.

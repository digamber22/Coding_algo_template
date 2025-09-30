

/* Iterative Function to calculate (x^y). TC->  O(logy) and  SC -> O(1) */
int power(int x, unsigned int y)
{
    int res = 1; // Initialize result

    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = res * x;

        // y must be even now
        y = y >> 1; // y = y/2
        x = x * x; // Change x to x^2
    }
    return res;
}

/*
1 .  Custom powerfn(x,y) (Binary Exponentiation):

Works only for integers (int, long long)
Exponent must be an integer.
Exact results (no floating-point errors).
Time complexity: O(log y).
Faster for integer powers.
Cannot handle fractional exponents.
May overflow if result exceeds data type range.
Best for competitive programming, modular arithmetic, and integer math problems.

2.   Built-in pow(x,y):

Works with integers, floats, and doubles.
Exponent can be integer or fractional.
May lose precision due to floating-point representation.
Time complexity: O(1) (but with heavy constants).
Slower for pure integer powers.
Handles fractional and negative exponents.
Can also overflow/underflow with very large or small results.
Best for general math, scientific computing, and cases requiring fractional exponents.

👉 Final summary:
Use custom power for fast, exact integer exponentiation.
Use pow when fractional or floating-point exponents are needed.

*/
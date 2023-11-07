#include <iostream>
#include <cmath> // for sqrt() function

// A modular square root function
double mySqrt(double x)
{
    // If the user entered a negative number, this is an error condition
    if (x < 0.0)
        throw "Can not take sqrt of negative number"; // throw exception of type const char*

    return std::sqrt(x);
}

int main() //Using the catch-all handler to wrap main(), only in production release, disabled in debug mode
{
    std::cout << "Enter a number: ";
    double x;
    std::cin >> x;

	#ifdef DEBUG //for debug
		std::cout << "The sqrt of " << x << " is " << mySqrt(x) << '\n';
		std::cerr << "we have an unexpected exception\n";
	#else //for production release
		try
		{
			std::cout << "The sqrt of " << x << " is " << mySqrt(x) << '\n';
		}
		catch(...)
		{
			std::cerr << "will this #ifdef work?\n";
		}
		// clear up and exit program
		std::cerr << "we unwound the stack, no information left for debugging.\n"; // mock printing
		return 1;
	#endif

    return 0;
}

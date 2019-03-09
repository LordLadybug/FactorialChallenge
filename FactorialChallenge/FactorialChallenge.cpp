// FactorialChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <assert.h>

uint64_t ZerosFactorial(uint64_t InputNumber);

int main()
//given integer, find number of trailing zeros in its factorial
{
	uint64_t NumberToFactorial;
	uint64_t NumberOfZeroes;
	//Test case 1: 0! = 1 -> 0 trailing zeroes
	NumberToFactorial = 0;
	NumberOfZeroes = ZerosFactorial(NumberToFactorial);
	assert(NumberOfZeroes == 0);

	//Test case 2: 5! = 120 -> 1 trailing zero
	NumberToFactorial = 5;
	NumberOfZeroes = ZerosFactorial(NumberToFactorial);
	assert(NumberOfZeroes == 1);

	//add some sample numbers to factorial above
	std::cout << "Enter positive number to take factorial of: " << std::endl;
	std::cin >> NumberToFactorial;
	NumberOfZeroes = ZerosFactorial(NumberToFactorial);
	std::cout << "Number of trailing zeroes is: " << std::endl << NumberOfZeroes;
}

uint64_t ZerosFactorial(uint64_t InputNumber)
{
	if (InputNumber<0)
	{
		throw std::invalid_argument("Factorial only accepts integers greater than 0."); //does not ensure input value is positive
	}
	//Better algorithm: Simple divide number by 5 and take floor (already handled by integer division)
	uint64_t Zeroes = 0;	//counter for number of zeroes
	uint64_t fiveCounter;
	for (fiveCounter = 5; fiveCounter <= InputNumber; fiveCounter *= 5) {
		Zeroes += InputNumber / fiveCounter;
	}
	return Zeroes;
	/*New trailing zero only added for each 10 that can be factorized out of the factorial; since the density of numbers divisible by 2
	is much higher than the density of numbers divisible by 5, we can solve this problem for large numbers by simply noting
	that a new trailing zero is generated every time we multiply by another multiple of 5, or better yet, multiple of 10. */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

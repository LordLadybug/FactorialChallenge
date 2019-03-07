// FactorialChallenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>

uint64_t ZerosFactorial(uint64_t InputNumber);

int main()
//given integer, find number of trailing zeros in its factorial
{
	uint64_t NumberToFactorial;
	uint64_t NumberOfZeroes;
	//Test case 1: 0! = 1 -> 0 trailing zeroes
	NumberToFactorial = 0;
	NumberOfZeroes = ZerosFactorial(NumberToFactorial);
	//assert equal to 0

	//Test case 2: 5! = 120 -> 1 trailing zero
	NumberToFactorial = 5;
	NumberOfZeroes = ZerosFactorial(NumberToFactorial);
	//assert equal to 1

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
	//Naive algorithm; won't handle large integers (handles up to 9)
	uint64_t Zeroes = 0;	//counter for number of zeroes
	uint64_t Factorial = InputNumber;
	while (InputNumber > 1) {
		InputNumber--;
		Factorial = Factorial * InputNumber;
	}
	while (Factorial % 10 == 0 && Factorial > 0) {
		Factorial = Factorial / 10;
		Zeroes += 1;
	}
	return Zeroes;
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

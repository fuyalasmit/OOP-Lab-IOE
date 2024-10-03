/*Assume that you want to check whether the number is prime or not. Write a program that asks for numbers repeatedly. When it finishes checking a number the program asks if the user wants to do another calculation. The response can be 'y' or 'n'. Don't forget to use the object-oriented concept.*/
#include <iostream>  // Include necessary header
class PrimeChecker
{
public:
    bool isPrime(int num)
    {
        if (num <= 1)
        {
            return false; // Numbers less than or equal to 1 are not prime
        }

        // Check divisibility from 2 up to num-1
        for (int i = 2; i < num; ++i)
        {
            if (num % i == 0)
            {
                return false; // Found a divisor, hence not prime
            }
        }

        return true; // If no divisors found, number is prime
    }

    void checkPrimeLoop()
    {
        char choice;

        do
        {
            int number;
            std::cout << "Enter a positive integer: ";
            std::cin >> number;

            if (isPrime(number))
            {
                std::cout << number << " is a prime number." << std::endl;
            }
            else
            {
                std::cout << number << " is not a prime number." << std::endl;
            }

            std::cout << "Do you want to check another number (y/n)? ";
            std::cin >> choice;
        } while (choice == 'y' || choice == 'Y'); // Repeat if user inputs 'y' or 'Y'
    }
};

int main()
{
    PrimeChecker pc; // Create an object of PrimeChecker
    pc.checkPrimeLoop(); // Call checkPrimeLoop method
    return 0;
}

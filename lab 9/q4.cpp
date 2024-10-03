//Write any program that demonstrates the use of multiple catch handling, re-throwing an exception, and catching all exceptions.

#include <iostream>

int main()
{
    int a , b ;
    std::cout<<"Enter two numbers: ";
    std::cin>>a>>b;

    try
    {
        try
        {
            if (b == 0)
            {
                throw "Division by zero!";
            }

            std::cout << a / b << '\n';
        }
        catch (const char *e)
        {
            std::cout << "Inner catch: " << e << '\n';

            // Rethrow the exact same exception that was just caught
            throw;
        }
    }
    catch (const char *e)
    {
        std::cout << "Outer catch: " << e << '\n';
    }
    catch (int)
    {
        // Handle an exception of type int
        // Executed if the previous try-catch block throws an exception of type int
        std::cout << "Error: Exception of type int!\n";
    }
    catch (...)
    {
        // Catch all other exceptions
        std::cout << "Error: Unknown error!\n";
    }

    return 0;
}

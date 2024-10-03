//Create a function called sum() that returns the sum of the elements of an array. Make this function into a template so it will work with any numerical type. Write a program that applies this function to data of various types.

#include <iostream>

// Function template
template <typename T>
T sum(T arr[], int size)
{
    T sum = 0; // Initialize sum to zero of type T

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return sum;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    float arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    // Apply the sum function to arrays of different types
    std::cout << "Sum of int array: " << sum(arr1, 5) << '\n';
    std::cout << "Sum of float array: " << sum(arr2, 5) << '\n';

    return 0;
}

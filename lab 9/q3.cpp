//Modify the stack class given in the previous lab to add the exception when a user tries to add an item while the stack is full and when the user tries to add the item while the stack is empty. Throw exceptions in both of the cases and handle these exceptions.
#include <iostream>
using namespace std;

template <class T>
class Stack
{
    T *arr;
    int Max;
    int top;

public:
    class Full {};
    class Empty {};

    Stack(int size = 5) : Max(size), arr(new T[Max]), top(-1) {}

    void push(T data)
    {
        if (top == Max - 1)
        {
            throw Full();
        }
        arr[++top] = data;
        cout << "Data pushed successfully" << endl;
    }

    T pop()
    {
        if (top == -1)
        {
            throw Empty();
        }
        return arr[top--];
    }

    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack<int> values;
    try
    {
        values.push(1);
        values.push(2);
        values.push(3);
        values.push(4);
        values.push(5);
        values.push(6);
    }
    catch (Stack<int>::Full)
    {
        cout << "Stack is full" << endl;
    }

    try
    {
        cout << values.pop() << endl;
        cout << values.pop() << endl;
        cout << values.pop() << endl;
        cout << values.pop() << endl;
        cout << values.pop() << endl;
        cout << values.pop() << endl;
    }
    catch (Stack<int>::Empty)
    {
        cout << "Stack is empty" << endl;
    }

    return 0;
}

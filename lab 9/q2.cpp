//Write a class template for queue class. Assume the programmer using the queue won't make mistakes, like exceeding the capacity of the queue or trying to remove an item when the queue is empty. Define several queues of different data types and insert and remove data from them.
#include <iostream>

template <class T>
class Queue
{
    int Max;
    T *arr;
    
    int back;

public:
    Queue(int size = 10) : Max(size), arr(new T[Max]), back(-1) {}

    void push(T d) { arr[++back] = d; }

    T pop()
    {
        T first = arr[0];
        for (int i = 0; i < back; i++) arr[i] = arr[i + 1];
        back--;
        return first;
    }

    ~Queue() { delete[] arr; }
};

int main()
{
    Queue<int> intQueue;
    intQueue.push(1);
    intQueue.push(2);
    intQueue.push(3);
    std::cout << intQueue.pop() << std::endl;
    std::cout << intQueue.pop() << std::endl;
    std::cout << intQueue.pop() << std::endl;

    Queue<char> charQueue;
    charQueue.push('a');
    charQueue.push('b');
    charQueue.push('c');
    std::cout << charQueue.pop() << std::endl;
    std::cout << charQueue.pop() << std::endl;
    std::cout << charQueue.pop() << std::endl;

    return 0;
}

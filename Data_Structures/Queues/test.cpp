#include <iostream>
#include "Queue.hpp"


int main()
{
    QUEUE::Queue<int> queue;

    queue.enqueue(0);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    queue.display();

    queue.dequeue();
    queue.dequeue();
    queue.dequeue();

    queue.display();

    return 0;
}
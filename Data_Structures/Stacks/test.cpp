#include <iostream>
#include <stdexcept> // throw

/*
#define MAX 101 

int *arr = new int[MAX]; // 0 - 100 elements
int top = -1;

void push(int i)
{
    if(top == MAX - 1)
    {
        throw std::out_of_range("Error: Overflow\n");
        return;
    }
    arr[++top] = i;
}

void pop()
{
    if(top == -1)
    {
        std::cout << "Pila vacía!\n";
        return;
    }
    top--;
}

void print()
{
    for(int i = 10; i > 0; --i)
        std::cout << arr[i] << "\n";
}

int get_top()
{
    return arr[top];    
}
*/

// STACK - ( LIFO )
// Last in First out
// Es una lista con la característica de que solo se pueden insertar y eliminar nodos por un lado de esta
// Se aplica en el llamado de funciones, recursividad, al borrar en un editor, balanceo de paréntesis

// Tiempo en sus funciones O(1)

// En un arreglo como Stack, si existe desbordamiento de sa en un tiempo de O(n) -> n = length of array

#include "Stack.hpp"

int main()
{
    STACK::Stack<int>* stack = new STACK::Stack<int>();

    stack->push(0);
    stack->push(1);
    stack->push(2);
    stack->push(3);

    stack->pop();
    stack->pop();

    stack->print();

    return 0;
}
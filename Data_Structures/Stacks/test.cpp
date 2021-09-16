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

#include <string>
#include "Stack.hpp"

bool validate(std::string);

int main()
{
    STACK::Stack<char>* stack = new STACK::Stack<char>();

    std::string line = "()"; 
    std::cout << validate(line);

    return 0;
}

// *REVERSE LIKED LIST CODE with stack
/*
template <class T, class U>
void reverse()
{
    if(head == nullptr)
        return;
    STACK::Stack<T> *stack = new STACK::Stack<T>();
    LList::Node<U> *temp = head;
    while(temp != nullptr)
    {
        stack->push(temp);
        temp = temp->get_next();
    }
    temp = stack->get_top();
    head = temp;
    while(!stack->itsEmpty())
    {
        temp->set_next(stack->get_top());
        stack->pop();
        temp = temp->get_next();
    }
    temp->set_next(nullptr);
}
*/

// ? {} () [] BALANCE PARENTHESES
bool validate(std::string line)
{
    STACK::Stack<char> *stack = new STACK::Stack<char>();
    for(auto value : line)
    {
        if(value == '(' || value == '[' || value == '{')
            stack->push(value);
        else 
        {
            if(stack->itsEmpty()) return false;
            else
            {
                if(value == ')' && stack->get_top() == '(')
                    stack->pop();
                else if(value == ']' && stack->get_top() == '[')
                        stack->pop();
                else if(value == '}' && stack->get_top() == '{')
                        stack->pop();
                else 
                    return false;  
            }
        } 
    }
    return stack->itsEmpty();
}



#ifndef Stack_hpp
#define Stack_hpp

#include "Stack_Node.hpp"
#include <stdexcept> // throw
#include <iostream>

namespace STACK
{

    template <class T>

    class Stack
    {
    private:
        Node<T> *top;
        int length;

        Node<T>* create(T new_data)
        {
            Node<T> *new_node = (Node<T> *)malloc(sizeof(Node<T>));
            Node<T> node(new_data);
            *new_node = node;
            return new_node;
        }

        void destroy(Node<T> *item_to_remove) { free(item_to_remove); }

        void insert(T new_data)
        {
            Node<T> *new_node = create(new_data);
            new_node->set_next(top);
            top = new_node;
            length++;
        }   

        void remove()
        {
            if(itsEmpty())
            {
                throw std::out_of_range("Pila Vacía!\n");
                return;
            }
            Node<T> *node_remove = top;
            top = top->get_next();
            destroy(node_remove);
            length--;
        }

    public:
        Stack() : top(nullptr), length(0) {}

        bool itsEmpty() { return top == nullptr; }

        void push(T new_item) { insert(new_item); }

        void pop() { remove(); }

        T get_top() { return top->get_data(); }

        void print()
        {
            Node<T> *current = top;
            std::cout << "Top -> ";
            for(int i = 0; i < length; ++i)
            {
                std::cout << current->get_data() << " -> ";
                current = current->get_next();
            }
            std::cout << "NULL" << std::endl;
        }

    };
}

#endif /* Stack_hpp */ 


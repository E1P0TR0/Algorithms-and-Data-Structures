#ifndef Queue_hpp
#define Queue_hpp

#include "Queue_Node.hpp"
#include <iostream>

namespace QUEUE
{
    
    template <class T>
    
    class Queue
    {
        private:
            Node<T> *front;
            Node<T> *back;
            int length;
            Node<T>* create(T new_data) 
            { 
                Node<T> *new_node = new Node<T>(new_data); 
                return new_node;
            }
            void remove(Node<T> *node_remove) { delete(node_remove); }
        public:
            Queue() : front(nullptr), back(nullptr) {}
            bool empty() { return front == nullptr && back == nullptr; }
            void enqueue(T new_data)
            {
                Node<T> *new_node = create(new_data);

                if(empty())
                    front = back = new_node;
                else
                {
                    back->set_next(new_node);
                    new_node->set_next(nullptr);
                    back = new_node;
                }
                length++;
            }
            void dequeue()
            {
                if(empty()) std::cerr << "Cola vacia!\n";
                else
                {
                    Node<T> *temp = front;
                    front = temp->get_next();
                    remove(temp);
                    length--;
                }
            }
            void display()
            {
                Node<T> *cursor = front;
                std::cout << "FRONT";
                while(cursor != nullptr)
                {
                    std::cout << " -> " << cursor->get_data();
                    cursor = cursor->get_next();
                }
                std::cout << " <- BACK\n";
            }
    };
}

#endif /* Queue_hpp */
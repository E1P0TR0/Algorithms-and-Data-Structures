#ifndef Linked_List_hpp
#define Linked_List_hpp

#include <cstdlib> // malloc
#include <stdexcept> // throw
#include "Linked_List_Node.hpp"

namespace MRS
{

    template <class T>

    class LinkedList
    {
    private:
        Node<T> *head;
        int length;

        Node<T>* create(T new_data)
        {
            Node<T> *new_node = (Node<T> *)malloc(sizeof(Node<T>));
            Node<T> node(new_data);
            *new_node = node;
            return new_node;
        }

        void destroy(Node<T> *item_to_remove) { free(item_to_remove); }

    public:
        LinkedList() : head(nullptr), length(0) {}

        void insert(T new_data, int index)
        {
            Node<T> *item_to_insert = create(new_data);
            // Lista vacia
            if(index == 0)
            {
                item_to_insert->set_next(head);
                head = item_to_insert;
            }
            else
            {
                Node<T>* current = iterate(index - 1); // Restamos para ubicarnos antes de la posición a insertar
                item_to_insert->set_next(current->get_next());
                current->set_next(item_to_insert);
            }
            length += 1;
        }

        void remove(int index)
        {
            if(index == 0)
            {
                Node<T> *item_to_remove = head;
                head = head->get_next();
                destroy(item_to_remove);
            }
            else
            {
                Node<T> *current = iterate(index - 1); // Restamos para ubicarnos antes de la posición a eliminar
                Node<T> *item_to_remove = current->get_next();
                current->set_next(item_to_remove->get_next());
                destroy(item_to_remove);
            }
            length -= 1;
        }

        // Iterar hasta llegar a la posición que buscamos
        Node<T>* iterate(int index)
        {
            if(index < 0 || index >= length)
                throw std::out_of_range("Indice fuera de rango!");
            Node<T> *current = head;
            for(int i = 0; i < index; ++i)
                current = current->get_next(); 
            return current;
        }

        // Imprimir elementos
        void print()
        {
            Node<T> *current = head;
            for(int i = 0; i < length; ++i)
            {
                std::cout << current->get_data() << " -> ";
                current = current->get_next();
            }
            std::cout << "NULL" << std::endl;
        }
    };

}

#endif /* Linked_List_hpp */
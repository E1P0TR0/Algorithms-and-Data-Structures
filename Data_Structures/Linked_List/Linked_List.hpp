#ifndef Linked_List_hpp
#define Linked_List_hpp

#include <iostream>
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

        // Crear nodo en memoria
        Node<T>* create(T new_data)
        {
            Node<T> *new_node = (Node<T> *)malloc(sizeof(Node<T>));
            Node<T> node(new_data);
            *new_node = node;
            return new_node;
        }

        // Eliminar nodo en memoria
        void destroy(Node<T> *item_to_remove) { free(item_to_remove); }

        // Insertat Nodo
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

        // Eliminar nodo
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

        // Obtener posición de nodo
        int getPos(T new_data)
        {
            Node<T> *current = head;
            int cont = -1;
            while(current != nullptr)
            {
                cont++;
                if(current->get_data() == new_data)
                    return cont;
                current = current->get_next();
            }
            return cont;
        }

        // Revertir lista manera iterativa
        void iterative_reverse()
        {
            Node<T> *previous = nullptr;
            Node<T> *current = head;
            Node<T> *next = nullptr;
            while(current != nullptr)
            {
                next = current->get_next();
                current->set_next(previous);
                previous = current;
                current = next;
            }
            head = previous;
        }

        // Revertir lista manera recursiva
        void recursive_reverse(Node<T> *current)
        {
            if(current == nullptr || current->get_next() == nullptr)
            {
                head = current;
                return;
            }
            recursive_reverse(current->get_next());
            Node<T> *current_next = current->get_next();
            current_next->set_next(current);
            current->set_next(nullptr);
        }

        // Impresión reversa
        void print_reverse(Node<T> *current)
        {
            if(current == nullptr)
                return;
            print_reverse(current->get_next());
            std::cout << current->get_data();
            (current != head) ? std::cout << " -> " : std::cout << " -> NULL\n";
        }

    public:
        LinkedList() : head(nullptr), length(0) {}

        void insert_begin(T new_data) { insert(new_data, 0); }

        void insert_pos(T new_data, int position) { insert(new_data, position); }

        void insert_end(T new_data) { insert(new_data, length); }

        void remove_begin() { remove(0); }

        void remove_pos(int position) { remove(position); }

        void remove_end() { remove(length - 1); }

        void update_begin(T new_data)
        {
            remove_begin();
            insert_begin(new_data);
        }

        void update_by(T old_data, T new_data)
        {
            int new_data_pos = getPos(old_data);
            remove_pos(new_data_pos);
            insert_pos(new_data, new_data_pos);
        }

        void update_end(T new_data)
        {
            remove_end();
            insert_end(new_data);
        }

        void reverse() { recursive_reverse(head); }
        
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

        void reverse_print() { print_reverse(head); }

    };

}

#endif /* Linked_List_hpp */
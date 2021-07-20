#ifndef Double_Linked_List_hpp
#define Double_Linked_List_hpp

#include <iostream>
#include "Double_Linked_List_Node.hpp"

namespace DLList
{

    template <class T>

    class DoubleLinkedList
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
            if(head == nullptr)
            {
                head = item_to_insert;
                return;
            }
            // Insersión primera posición
            if(index == 0)
            {
                item_to_insert->set_next(head);
                head->set_prev(item_to_insert);
                head = item_to_insert;
            }
            else // demás posiciones 
            {
                Node<T>* current = iterate(index - 1); // Restamos para ubicarnos antes de la posición a insertar
                item_to_insert->set_next(current->get_next());
                current->set_prev(item_to_insert);

                current->set_next(item_to_insert);
                item_to_insert->set_prev(current);
            }
            length += 1;
        }

        // Eliminar Nodo
        void remove(int index)
        {
            if(head == nullptr)
                return;
            if(index == 0)
            {
                Node<T> *item_to_remove = head;
                head = head->get_next();
                head->set_prev(nullptr);
                destroy(item_to_remove);
            }
            else
            {
                Node<T> *current = iterate(index - 1); // Restamos para ubicarnos antes de la posición a eliminar
                Node<T> *item_to_remove = current->get_next();

                current->set_next(item_to_remove->get_next());
                item_to_remove->get_next()->set_prev(current);
                
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

    public:
        DoubleLinkedList() : head(nullptr), length(0) {}

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
        
        // Imprimir elementos
        void print()
        {
            Node<T> *current = head;
            for(int i = 0; i < length; ++i)
            {
                std::cout << current->get_data() << " <-> ";
                current = current->get_next();
            }
            std::cout << "NULL" << std::endl;
        }
    };

}

#endif /* Double_Linked_List_hpp */
#ifndef Linked_List_hpp
#define Linked_List_hpp

#include <iostream>
#include <cstdlib> // malloc
#include <stdexcept> // throw
#include "Linked_List_Node.hpp"

namespace LList
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
            if(head == nullptr)
            {
                head = item_to_insert;
                return;
            }
            // Insersión primera posición
            if(index == 0)
            {
                item_to_insert->set_next(head);
                head = item_to_insert;
            }
            else // demás posiciones 
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
            // Lista vacia
            if(head == nullptr)
                return;
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

        // Obtener posición de nodo - lista sin duplicados
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

        T retrieve(int index)
        {
            Node<T> *cursor = iterate(index);
            return cursor->get_data();
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

        // Ordenar lista - unir listas ordenadas a una ordenada
        void merge_sort(Node<T> **head_ref)
        {
            Node<T> *new_head = *head_ref;  
            Node<T> *left_list, *right_list;
            // Caso base - Lista con un elemento o vacía
            if(new_head == nullptr || new_head->get_next() == nullptr)
                return;
            // Crear las dos sublistas
            front_back_split(new_head, &left_list, &right_list);
            // Las ordenamos de manera recursiva
            merge_sort(&left_list);
            merge_sort(&right_list);
            // Juntamos las dos listas ya ordenadas y asignamos el nuevo head
            *head_ref = sorted_merge(left_list, right_list);        
        }
        Node<T>* sorted_merge(Node<T> *left_list, Node<T> *right_list)
        {
            Node<T> *result = nullptr;
            // Caso base - Una de las dos listas está vacía, retornamos la no vacía
            if(left_list == nullptr)
                return right_list;
            else if(right_list == nullptr)
                return left_list;
            // Evaluamos el criterio de ordenamiento - de menor a mayor
            if(left_list->get_data() <= right_list->get_data())
            {
                result = left_list;
                result->set_next(
                    sorted_merge(left_list->get_next(), right_list)
                );
            }
            else
            {
                result = right_list;
                result->set_next(
                    sorted_merge(left_list, right_list->get_next())
                );
            }
            return result;
        }
        void front_back_split(Node<T> *source, Node<T> **left_ref, Node<T> **right_ref)
        {
            Node<T> *fast;
            Node<T> *slow;
            slow = source;
            fast = source->get_next();
            // Avanzamos el nodo 'fast' dos veces y el nodo 'slow' solo una vez
            while(fast != nullptr)
            {
                fast = fast->get_next();
                if(fast != nullptr)
                {
                    slow = slow->get_next();
                    fast = fast->get_next();
                }
            }
            // El nodo slow se encuentra en medio del punto medio, asi que lo usamos de referencia
            *left_ref = source;
            *right_ref = slow->get_next();
            slow->set_next(nullptr);
        }

        // Eliminar duplicados -> modo iterativo // Mas de dos iguales no los elimina
        void delete_duplicates_iterative()
        {
            // Lista vacía o con solo un elemento
            if(!head || !head->get_next()) return;
            // Creamos puntero para recorrer lista
            Node<T> *current = head;
            Node<T> *new_next = nullptr;
            // Recorremos lista
            while(current->get_next() != nullptr)
            {
                if(current->get_data() == current->get_next()->get_data())
                {
                    new_next = current->get_next()->get_next();
                    destroy(current->get_next());
                    current->set_next(new_next);
                    length -= 1;
                }
                else 
                    current = current->get_next();
            }
        }

        // Eliminar duplicados -> modo recursivo // Mas de dos iguales no los elimina
        Node<T>* delete_duplicates_recursive(Node<T> **head_ref)
        {
            Node<T> *new_head = *head_ref;
            if(!new_head || !new_head->get_next())
                return new_head;
            Node<T> *aux = new_head->get_next();
            new_head->set_next(delete_duplicates_recursive(&aux));
            if(new_head->get_data() == new_head->get_next()->get_data())
            {
                length--;
                return new_head->get_next(); 
            }  
            else
                return new_head;
            return new_head;
        }


    public:
        LinkedList() : head(nullptr), length(0) {}

        Node<T>* get_head() { return head; }
        
        int get_length() { return length; }
        
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

        void sort() { merge_sort(&head); }

        void remove_duplicates() { head = delete_duplicates_recursive(&head); }
    };

}

#endif /* Linked_List_hpp */
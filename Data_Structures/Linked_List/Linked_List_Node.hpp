#ifndef Linked_List_Node_hpp
#define Linked_List_Node_hpp

namespace LList
{

    template <class T>

    class Node
    {
    private:  
        T data;
        Node<T> *next;
    public:
        // Constructors
        Node() : data(NULL), next(nullptr) {}
        Node(T item_data) : data(item_data), next(nullptr) {}
        Node(T item_data, Node<T> *next_node_address) : data(item_data), next(next_node_address) {}
        
        // Sets and Getters
        void set_data(T item_data) { this->data = item_data; }
        T get_data() { return this->data; }

        void set_next(Node<T> *next_node_address) { this->next = next_node_address; }
        Node<T>* get_next() { return this->next; }
    };

}

#endif /* Linked_List_Node_hpp */


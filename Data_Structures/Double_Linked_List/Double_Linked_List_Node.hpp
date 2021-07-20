#ifndef Double_Linked_List_Node_hpp
#define Double_Linked_List_Node_hpp

namespace DLList
{

    template <class T>

    class Node
    {
    private:  
        T data;
        Node<T> *next;
        Node<T> *prev;
    public:
        // Constructors
        Node() : data(NULL), next(nullptr), prev(nullptr) {}
        Node(T item_data) : data(item_data), next(nullptr), prev(nullptr) {}
        Node(T item_data, Node<T> *next_node_address, Node<T> *prev_node_address) : data(item_data), next(next_node_address), prev(prev_node_address) {}
        
        // Sets and Getters
        void set_data(T item_data) { this->data = item_data; }
        T get_data() { return this->data; }

        void set_next(Node<T> *next_node_address) { this->next = next_node_address; }
        Node<T>* get_next() { return this->next; }

        void set_prev(Node<T> *prev_node_address) { this->prev = prev_node_address; }
        Node<T>* get_prev() { return this->prev; }

    };
}

#endif /* Double_Linked_List_Node_hpp */
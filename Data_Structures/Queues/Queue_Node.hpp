#ifndef Queue_Node_hpp
#define Queue_Node_hpp

namespace QUEUE
{

    template <class T>

    class Node
    {
        private:    
            T data;
            Node<T> *next;
        public:
            Node() : data(NULL), next(nullptr) {}
            Node(T item_data) : data(item_data), next(nullptr) {}

            void set_next(Node<T> *next_address) { this->next = next_address; }
            Node<T>* get_next() { return this->next; }

            T get_data() { return this->data; }
    };
}


#endif



#include <iostream>

#include "Linked_List.hpp"

int main()
{
    MRS::LinkedList<int>* list = new MRS::LinkedList<int>(); 

    list->insert_begin(4);
    list->insert_begin(-1);
    list->insert_end(1);
    list->insert_end(2);
    list->insert_end(7);
    list->insert_pos(3, 3);
    list->insert_end(0);

    list->print();

    list->sort();

    list->print();

    return 0;
}
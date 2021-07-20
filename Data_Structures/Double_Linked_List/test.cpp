#include <iostream>

#include "Double_Linked_List.hpp"

int main()
{
    DLList::DoubleLinkedList<int>* list = new DLList::DoubleLinkedList<int>();

    list->insert_begin(-3);
    list->insert_end(-2);
    list->insert_end(-1);
    list->insert_pos(456, 2);
    list->insert_end(0);
    list->insert_end(1);
    list->insert_end(2);

    list->remove_end();
    list->remove_begin();

    list->print();
    
    return 0;
}
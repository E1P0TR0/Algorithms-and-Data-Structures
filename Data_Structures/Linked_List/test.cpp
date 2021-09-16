#include <iostream>

#include "Linked_List.hpp"

int main()
{
    LList::LinkedList<int>* list = new LList::LinkedList<int>(); 

    list->insert_begin(3);
    list->insert_begin(3);
    list->insert_begin(2);
    list->insert_begin(1);
    list->insert_begin(1);

    list->print();

    list->remove_duplicates();

    list->print();

    return 0;
}
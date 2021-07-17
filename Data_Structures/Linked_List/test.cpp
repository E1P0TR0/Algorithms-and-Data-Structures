#include <iostream>

#include "Linked_List.hpp"

int main()
{
    MRS::LinkedList<int>* list = new MRS::LinkedList<int>(); 

    list->insert_begin(0);
    list->insert_begin(-1);
    list->insert_end(2);
    list->insert_end(4);
    list->insert_pos(3, 3);
    list->insert_end(5);

    // list->print();

    // list->remove_pos(1);

    // list->print();

    // list->update_by(2, 123);

    list->print();

    list->reverse();

    list->print();

    return 0;
}
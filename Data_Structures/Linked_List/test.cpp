#include <iostream>

#include "Linked_List.hpp"

int main()
{
    MRS::LinkedList<int>* list = new MRS::LinkedList<int>(); 

    list->insert(0, 0);
    list->insert(1, 1);
    list->insert(2, 2);
    list->insert(3, 3);

    list->print();
    return 0;
}
#include <iostream>

// Time Complexity O(n)

int linearSearch(int number, int arr[], int size)
{
    // Si existe en el arreglo retorna su posición, en caso contrario retorna -1
    for (int i = 0; i < size; i++)
        if (number == arr[i])
            return i;
    return -1;
}

void verify(int index)
{
    if (index == -1)
        std::cout << "No existe ese numero." << std::endl;
    else
        std::cout << "Numero encontrado !" << std::endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int index = linearSearch(12, arr, size);
    verify(index);
    return 0;
}
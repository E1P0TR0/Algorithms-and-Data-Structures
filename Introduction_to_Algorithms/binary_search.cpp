#include <iostream>
#include <vector>

// Time Complexity O(log n) // Constant Space

int binarySearch(int number, std::vector<int> vect)
{
    // Se ubica en la mitad del arreglo, luego veificamos si el número es mayor, igual o menor. 
    // De acuerdo al resultado ser dirige a la mitad de numeros menores o de mayores partiendo de la mitad.
    // Se repite el proceso con la posibilidad encontrar el numero
    // Tener en cuenta que el arreglo debe estar ordenado

    int left = 0;
    int right = vect.size() - 1;

    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (number == vect[middle])
            return middle;
        else 
            if (number < vect[middle])
                right = middle - 1;
            else
                left = middle + 1;
    }

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
    std::vector<int> vect = {1, 2, 3, 4, 5, 6, 7};
    int index = binarySearch(14, vect);
    verify(index);
    return 0;
}
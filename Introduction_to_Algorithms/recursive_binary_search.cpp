#include <iostream>
#include <vector>
#include <string>

// Time Complexity O(log n)

int recursiveBinarySearch(int number, std::vector<int> vect, int left, int right)
{
    // Se ubica en la mitad del arreglo, luego veificamos si el número es mayor, igual o menor. 
    // De acuerdo al resultado ser dirige a la mitad de numeros menores o de mayores partiendo de la mitad.
    // Se repite el proceso con la posibilidad encontrar el numero
    // Tener en cuenta que el arreglo debe estar ordenado

    if (right >= left)
    {
        int middle = left + (right - left) / 2;
        if (number == vect[middle])
            return middle;
        else 
            if (number < vect[middle])
                return recursiveBinarySearch(number, vect, left, middle - 1);
            else
                return recursiveBinarySearch(number, vect, middle + 1, right);
    }
    return -1;
}

void verify(int result)
{
    (result == -1) ? std::cout << "Valor no encontrado." : std::cout << "Valor encontrado !" << std::endl;
}

int main()
{
    std::vector<int> vect = {1, 2, 3, 4, 5, 6, 7};
    int result = recursiveBinarySearch(1, vect, 0, vect.size() - 1);
    verify(result);
    return 0;
}
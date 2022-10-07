#ifndef LAB5_BMSTU_ARRAY_H
#define LAB5_BMSTU_ARRAY_H

#include <cstdlib>

void fillArrays(int *arr1, int *arr2, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        arr1[i] = rand() % 40;
        arr2[i] = arr1[i];
    }
}

void printArray(const std::string& msg, int *arr, size_t size, const int *swaps)
{
    std::cout << msg;
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << " -- "<< (size * (size-1))/2 << " comparisons; " << *swaps << " swaps\n";
}

void printArray(const std::string& msg, int *arr, size_t size)
{
    std::cout << msg;
    for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    std::cout << "\n";
}

#endif
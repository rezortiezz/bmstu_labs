#include <iostream>
#include <stdlib.h> //! to use rand()

void swap(int *_first, int *_second)
{
    int tmp = *_first;
    *_first = *_second;
    *_second = tmp;
}

void bubble_sort(int *arr, int n)
{
    int tmp, counter = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            counter++;
            if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j+1]);
        }
    }
    printf("\n%d comparisons done by ", counter);
}

void selection_sort(int *arr, int n)
{
    unsigned int counter = 0, minIndex, i, j;

    for (i = 0; i < n - 1; i++)
    {   
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
                counter++;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }

    printf("\n%d comparisons done by ", counter);
}

int main(int argc, char const *argv[])
{   
    std::cout << "n = ";
    int n; std::cin >> n;
    int *arr_bubble = new int[n];
    int *arr_selection = new int[n];

    for (int i = 0; i < n; i++)
    {
        arr_bubble[i] = rand() % 40;
        arr_selection[i] = arr_bubble[i];
    }
    //* arr_selection is a copy of arr_bubble now

    std::cout << "start array: ";
    for (int i = 0; i < n; i++) std::cout << arr_bubble[i] << " ";

    bubble_sort(arr_bubble, n);
    std::cout << "bubble sort: ";
    for (int i = 0; i < n; i++) std::cout << arr_bubble[i] << " ";

    selection_sort(arr_selection, n);
    std::cout << "selection sort: ";
    for (int i = 0; i < n; i++) std:: cout << arr_selection[i] << " ";
    std::cout << '\n';  

    return 0;
}
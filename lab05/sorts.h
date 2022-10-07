#ifndef LAB5_BMSTU_SORTS_H
#define LAB5_BMSTU_SORTS_H

#include "utils.h"

#define DEFAULT {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
#define DESCENDING {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
#define len(ARR) (sizeof(ARR)/sizeof(ARR[0]))

void BubbleSort(int *arr, size_t size, int *swaps)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                (*swaps)++;
            }
        }
    }
}

void SelectionSort(int *arr , size_t size, int *swaps)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
                (*swaps)++;
            }
        }
        swap(&arr[minIndex], &arr[i]);
    }
}

void sortArrays(int *arr1, int *arr2, size_t size, int *swapsBubble, int *swapsSelect)
{
    BubbleSort(arr1, size, swapsBubble);
    SelectionSort(arr2, size, swapsSelect);
}

void printDefaults(int *BubbleSwaps, int *SelectionSwaps)
{
    *BubbleSwaps = 0; *SelectionSwaps = 0;
    int sorted[] = DEFAULT;
    BubbleSort(sorted, len(sorted), BubbleSwaps);
    SelectionSort(sorted, len(sorted), SelectionSwaps);
    printArray("\n\nbubble sort on sorted array: ", sorted, len(sorted), BubbleSwaps);
    printArray("selection sort on sorted array: ", sorted, len(sorted), SelectionSwaps);

    *BubbleSwaps = 0; *SelectionSwaps = 0;
    int descending[] = DESCENDING;
    BubbleSort(descending, len(descending), BubbleSwaps);
    printArray("backwards bubble sorted array: ", descending, len(descending), BubbleSwaps);
    int descending_copy[] = DESCENDING;
    SelectionSort(descending_copy, len(descending_copy), SelectionSwaps);
    printArray("backwards selection sorted array: ", descending, len(descending), SelectionSwaps);
}

#endif //LAB5_BMSTU_SORTS_H

#include <iostream>
#include <vector>

#include "array.h"
#include "sorts.h"
#include "table.h"

#define COMP(SIZE) ((SIZE * (SIZE - 1))/2)

using std::vector;
using std::cout;
using std::cin;

int main()
{
    size_t size;
    int BubbleSwaps, SelectionSwaps;
    char userInput;
    vector<table *> printer;
    do {
        BubbleSwaps = 0; SelectionSwaps = 0;
        cin >> size;
        int *arrBubble = new int[size];
        int *arrSelection = new int[size];

        fillArrays(arrBubble, arrSelection, size);
        printArray("\nstart array: ", arrBubble, size);
        sortArrays(arrBubble, arrSelection, size, &BubbleSwaps, &SelectionSwaps);
        printArray("bubble sort: ", arrBubble, size, &BubbleSwaps);
        printArray("selection sort: ", arrSelection, size, &SelectionSwaps);

        printer.push_back(toTable(size, BubbleSwaps, SelectionSwaps, COMP(size)));

        delete[] arrBubble;
        delete[] arrSelection;

        cout << "continue(y/n)?\n";
        cin >> userInput;
    } while (userInput != 'n');

    cout << "\n\n\t----------------RESULTS----------------\n\n" <<
    setw(12) << "size of arr " <<
    setw(26) << "bubble sort comp, swaps\t " <<
    setw(26) << "selection sort comp, swaps\n";
    printTable(printer);
    printDefaults(&BubbleSwaps, &SelectionSwaps);
    return 0;
}

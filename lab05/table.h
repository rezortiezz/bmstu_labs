#ifndef LAB5_BMSTU_TABLE_H
#define LAB5_BMSTU_TABLE_H

#include <cstdlib>
#include <iomanip>

using std::setw;

typedef struct table {
    size_t size;
    int comparisons;
    int b_swaps;
    int s_swaps;
} table;

table * toTable(size_t _size, int _b_swaps, int _s_swaps, int _comparisons)
{
    auto *this_sort = (table *)malloc(sizeof(table));

    this_sort->size = _size;
    this_sort->s_swaps = _s_swaps;
    this_sort->b_swaps = _b_swaps;
    this_sort->comparisons = _comparisons;

    return this_sort;
}

void printTable(const std::vector<table *>& printer)
{
    for (auto row : printer)
    {
        std::cout << setw(5) << row->size << setw(16) << row->comparisons << ", " << row->b_swaps << setw(29)
                                << row->comparisons << ", " << row->s_swaps << "\n";
    }
}

#endif //LAB5_BMSTU_TABLE_H

/* Selection Sort
Properties:
- Not stable
- In-place
- Online
- Time complexity: O(n^2) comparisons and swaps
- Auxilariary Space: O(1)
*/
#include<iostream>

// Swap values of two numbers, passed by address
template <class T>
void swap(T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}

// Find the minimal element in an array
// Returns pointer to that element
template <class T>
const T* minElementPointer(const T* const array, const size_t size) {
    const T* min = array;
    for (size_t i = 1; i < size; ++i) {
        if (array[i] < *min)
            min = array+i;
    }
    return min;
}

// Selection sort.
// A simple and short implementation, using pointers
template <class T>
void selectionSortPointers(T* array, const size_t size) {
    for(size_t i = 0; i < size-1; ++i) {
        swap(array+i, array+(minElementPointer(array+i, size-i)-array));
    }
}

template <class T>
const size_t minElementIndex(const T* const array, const size_t from, const size_t to) {
    size_t min = from;
    for (size_t i = from+1; i < to; ++i) {
        if (array[i] < array[min])
            min = i;
    }
    return min;
}
// Selection sort.
// A simple implementation, without pointers
template <class T>
void selectionSort(T* array, const size_t size)
{
    for(size_t i = 0; i < size-1; ++i) {
        size_t min = minElementIndex(array, i, size);
        swap(array+i, array+min);
    }
}
/* Bubble Sort
Properties:
- Stable
- In-place
- Not online
- Time complexity: O(n^2) comparisons and swaps
- Adaptive: O(n) when nearly sorted
- Auxilariary Space: O(1)
*/
#include<iostream>

template <class T>
void swap(T* a, T* b) {
    T t = *a;
    *a = *b;
    *b = t;
}

// Bubble sort
template <class T>
void bubbleSort(T* array, size_t size) {
    bool changed = false; // If an element was moved in the last pass
    size_t sorted = 0;    // The number of already sorted elements
    do {
        changed = false;  // At the beginning there are no moved elements
        // Then we check all pairs of adjoining elements
        for(size_t i = size-1; i > sorted; --i) {
            if(array[i] < array[i-1]) {      // and if there is a pair with not proper order
                swap(array+i, array+(i-1));  // swap the elements
                changed = true;              // and mark the move
            }
        }
        ++sorted;         // update the size of already sorted part
    }while(changed);
}

int main() {
    return 0;
}
/* Quick Sort
Properties:
- Not stable
- In-place
- Not online
- Time complexity: O(n*log(n)) comparisons and swaps
- Adaptive
- Auxilariary Space: O(n)
*/
#include<iostream>

template <class T>
int partition_hoare(T* array, int low, int high) {
    T pivot = array[low];
    int i = low-1;
    int j = high+1;
    while(true) {
        do {
            --j;
        }while(array[j] > pivot);
        do {
            ++i;
        }while(array[i] < pivot);
        if(i >= j) {
            return j;
        }
        std::swap(array[i], array[j]);
    }
}

template <class T>
void quickSortHelper(T* array, int low, int high) {
    if(low < high) {
        int mid = partition_hoare(array, low, high);
        quickSortHelper(array, low, mid);
        quickSortHelper(array, mid+1, high);
    }
}

template <class T>
void quickSort(T* array, int size) {
    quickSortHelper(array, 0, size-1);
}
/* Insertion Sort
Properties:
- Stable
- In-place
- Online
- Time complexity: O(n^2) comparisons and swaps
- Adaptive: O(n) when nearly sorted
- Auxilariary Space: O(1)
*/
#include<iostream>

template <class T>
void insertSorted(T* const arr, T x, const size_t size) {
    size_t i = size;
    while(i > 0 && arr[i-1] > x) {
        arr[i] = arr[i-1];
        --i;
    }
    arr[i] = x;
}
template <class T>
void insertionSort(T* const arr, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		insertSorted(arr, arr[i], i);
	}
}
/* Insertion Sort
Properties:
- Stable
- In-place
- Online
- Time complexity: O(n^2) comparisons and swaps
				   Adaptive: O(n) when nearly sorted
- Auxilariary Space: O(1)
*/
#include<iostream>

void insertSorted(int* arr, int x, size_t size) {
    size_t i = size;
    while(i > 0 && arr[i-1] > x) {
        arr[i] = arr[i-1];
        --i;
    }
    arr[i]=x;
}
void insertionSort(int* arr, size_t size) {
	for (size_t i = 0; i < size; i++) {
		insertSorted(arr, arr[i], i);
	}
}

int main() {
    return 0;
}
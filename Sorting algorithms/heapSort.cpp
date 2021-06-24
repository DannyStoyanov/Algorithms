/* Heap Sort
Properties:
- Not stable
- In-place
- Not online
- Time complexity: O(n*log(n)) comparisons and swaps
- Not really adaptive
- Auxilariary Space: O(1)
*/
#include<iostream>
#include<vector>

template <class T>
void heapify(std::vector<T>& array, size_t size, size_t i) {
    size_t largest = i; // root
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    // If left child is larger than root
    if(left < size && array[left] > array[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if(right < size && array[right] > array[largest]) {
        largest = right;
    }

    // if largest is not root
    if(largest != i) {
        std::swap(array[i], array[largest]);
        heapify(array, size, largest); // Recursively heapify the affected subtree
    }
}

template <class T>
void buildHeap(std::vector<T>& array) {
    size_t size = array.size();
    for(int i = size/2 - 1; i>=0; i--) {
        heapify(array, size, i);
    }
}

template <class T>
void heapSort(std::vector<T>& array) {
    size_t size = array.size();
    buildHeap(array);                  // Build heap - rearrange array
    for (int i = size-1; i > 0; --i) { // One by one extract an element from heap
        std::swap(array[0], array[i]); // Move current root to end
        heapify(array, i, 0);          // Call max heapify on the reduced heap
    }
}

int main() {
    return 0;
}
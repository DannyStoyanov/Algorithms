/* Merge Sort
Properties:
- Stable
- In-place
- Not online
- Time complexity: O(n*log(n)) comparisons and swaps
- Not adaptive
- Auxilariary Space: O(n)
*/
#include<iostream>
#include<vector>

template <class T>
void merge(T* leftArr, int leftLen, T* rightArr, int rightLen) {
    T* result = new T[leftLen + rightLen];
    if(!result) {
        return;
    }
    int left = 0;
    int right = 0;
    int mergedIndex = 0;

    while(left < leftLen && right < rightLen) {
        if(leftArr[left] < rightArr[right]) {
            result[mergedIndex++] = leftArr[left++];
        }
        else {
            result[mergedIndex++] = rightArr[right++];
        }
    }
    while(left < leftLen) {
        result[mergedIndex++] = leftArr[left++];
    }
    while(right < rightLen) {
        result[mergedIndex++] = rightArr[right++];
    }
    for (int i = 0; i < leftLen + rightLen; i++) {
        leftArr[i]=result[i];
    }
    delete[] result;
}

template <class T>
void mergeSort(T* array, int size) {
    if(size <= 1) {
        return;
    }
    int mid = size/2;
    mergeSort(array, mid);
    mergeSort(array+mid, size - mid);
    merge<T>(array, mid, array+mid, size - mid);
}
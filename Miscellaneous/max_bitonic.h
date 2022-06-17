#include <iostream>

// A Bitonic Sequence is a sequence of numbers that is 
// first strictly increasing then after a point decreasing.

int max_bitonic_helper(int arr[], int left, int right) {
    if (left == right) {
        return arr[left];
    }
    int mid = (left + right)/2;
    if (arr[mid] < arr[mid+1]) {
        return max_bitonic_helper(arr, mid + 1, right);
    }
    else if (arr[mid] > arr[mid+1]) {
        return max_bitonic_helper(arr, left, mid);
    }
    else {
        return arr[mid];
    }
}

int max_bitonic(int arr[], std::size_t size) {
    return max_bitonic_helper(arr, 0, size-1);
}
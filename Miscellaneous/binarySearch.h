#include <iostream>

// Array must be sorted before using!

int binarySearch_iterative(int* arr, int size, int x) {
    int left = 0;
    int right = size-1;
    while(left <= right) {
        int mid = left + (right-left)/2;
        if(arr[mid] == x) {
            return mid;
        }
        else if(arr[mid] < x) {
            left = mid + 1;
        }
        else if(arr[mid] > x) {
            right = mid;
        }
    }
    return -1;
}

int binarySearch_rec_helper(int* arr, int x, int left, int right) {
    if(left > right) {
    return -1;
    }
    int mid = left + (right-left)/2;
    if(arr[mid] == x) {
        return mid;
    }
    if(arr[mid] < x) {
        return binarySearch_rec_helper(arr, x, mid+1, right);
    }
    return binarySearch_rec_helper(arr, x, left, mid-1);
}

int binarySearch_rec(int* arr, int size, int x) {
    int left = 0;
    int right = size-1;
    return binarySearch_rec_helper(arr, x, left, right);
}
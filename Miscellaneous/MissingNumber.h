#include <iostream>

// You are given a list of n-1 integers and these 
// integers are in the range of 1 to n. There are 
// no duplicates in the list. One of the integers 
// is missing from the list. Write an efficient 
// code to find the missing integer.

int missingNumber(int arr[], size_t size) {
    int left = 0;
    int right = size-1;
    while(left < right) {
        int mid = left +(right-left)/2;
        if(arr[mid] == mid) {
            left = mid+1;
        }
        else if(arr[mid] > mid) {
            right = mid;
        }
        else {
            return mid;
        }
    }
    if(arr[size-1]+1 == size) {
        return left+1;
    }
    return left;
}
#include <iostream>
#include <stack>
#include "mergeSort.h"

// You are given an array of integers of size N. 
// Your task is to find the dominant number in the array.
// A dominant number in an array is an integer that occurs
// more than N/2 times in the array, where N is the array’s length.

// Time complexity: O(nlgn)
int predominantElementV2(int arr[], std::size_t size) {
    mergeSort(arr, size);
    return arr[size/2];
}

// Time complexity: O(n)
int predominantElement(int arr[], std::size_t size) {
    std::stack<int> st;
    for(size_t i=0; i<size; i++) {
        if(st.empty() || arr[i] == st.top()) {
            st.push(arr[i]);
        }
        else {
            st.pop();
        }
    }
    return st.top();
}
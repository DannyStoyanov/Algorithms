#include <iostream>
#include <list>
#include "mergeSort.h"

// Given an array of integers and a target we have to
// check if there exists a triplet such that their 
// combined sum is equal to the given target. 
// Popularly known as 3 sum problem algorithm.

std::list<int> threeSum(int arr[], std::size_t size) {
    mergeSort(arr, size);
    std::list<int> ans;
    int j = 0;
    int k = 0;
    for (size_t i = 0; i < size-2; i++) {
        if(arr[i] >= 0) {
            break;
        }
        j = i+1;
        k = size-1;
        while (j < k) {
            if(arr[i]+arr[j]+arr[k] == 0) {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
                ans.push_back(arr[k]);
                j++;
                k--;
            }
            else if(arr[i]+arr[j]+arr[k]<0) {
                j++;
            }
            else {
                k--;
            }
        }
    }
    return ans;
}
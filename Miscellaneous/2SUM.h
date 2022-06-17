#include <iostream>

// Array must be sorted before using!

bool twoSum(int arr[], int size, int sum) {
    int i=0;
    int j=size-1;
    while(i < j) {
        if((arr[i] + arr[j]) == sum) {
            return true;
        }
        else if (arr[i] + arr[j] < sum) {
            i++;
        }
        else {
            j--;
        }
    }
    return false;
}
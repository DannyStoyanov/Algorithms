#include<iostream>

int kadane(int array[], size_t size) {
    int tempMax = INT_MIN;
    int maxEndingHere = 0;
    for (size_t i = 0; i < size; i++) {
        maxEndingHere = maxEndingHere + array[i];
        if(tempMax < maxEndingHere) {
            tempMax = maxEndingHere;
        }
        if(maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }
    return tempMax;
}

int main() {
    int arr[] = {2, -3, 1, -4, 5, 2, -1, 4, -3};
    size_t size = sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Kadane: "<<kadane(arr, size);
    return 0;
}
// MaxMinPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>>

using namespace std;

void quickSort(int* a, int low, int high);
int partition(int* a, int low, int high);

int main()
{
    int a[] = {4,6,2,4,3,1,5,5,3,6,5,4,54,5 };
    quickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    int currCount=1;
    int maxCount = 0;
    int maxElement = 0;
    for (int i = 1; i < sizeof(a) / sizeof(a[0]); i++) {
        if (a[i] == a[i - 1])
            currCount += 1;
        else
            currCount = 1;
        if (currCount > maxCount) {
            maxCount = currCount;
            maxElement = a[i];
        }
    }
    printf("Mode: %d\n", maxElement);
    
}

void quickSort(int* a, int low, int high) {
    if (low >= high)
        return;
    int p = partition(a, low, high);
    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

int partition(int* a, int low, int high) {
    int pivot = high;
    int first_high = low;
    for (int i = low;i < high;i++) {
        if (a[i] < a[pivot]) {
            int temp = a[i];
            a[i] = a[first_high];
            a[first_high] = temp;
            first_high++;
        }
    }
    int temp = a[pivot];
    a[pivot] = a[first_high];
    a[first_high] = temp;
    //for (int i = low; i <= high; i++)
    //    printf("%d ", a[i]);
    return first_high;

}
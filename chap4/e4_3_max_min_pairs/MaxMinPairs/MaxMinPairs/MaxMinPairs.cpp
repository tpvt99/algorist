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
    int a[] = { 9, 5, 3, 1, 10, 20 };
    quickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    
    vector<pair<int, int>> pairs;
    int start = 0;
    int end = sizeof(a) / sizeof(a[0]) - 1;
    while (start < end) {
        pairs.push_back(make_pair(a[start], a[end]));
        start++;
        end--;
    }
    printf("Sum of pairs: ");
    int maxSum = 0; // assume elements in a >0
    for (auto v : pairs) {
        int temp = v.first + v.second;
        if (temp > maxSum)
            maxSum = temp;
        printf("%d ", temp);
    }
    printf("\nMin of max sum is : %d\n", maxSum);
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
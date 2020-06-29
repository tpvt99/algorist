// SumPairs2Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <utility>>

using namespace std;

void quickSort(int* a, int low, int high);
int partition(int* a, int low, int high);

// sort 2 arrays and using 2-pointer approach. Complexity: 2*O(nlogn) + O(n)
int sumPairs(int* a, int* b, int n_a, int n_b, int sum);

// sort 1 array and using loop + binarySearch to find sum. Complexity: O(nlogn) + O(n) * O(logn)
int sumPairsMethod2(int* a, int* b, int n_a, int n_b, int sum);

int main()
{
    int a[] = { 9, 5, 3, 1, 10, 20 };
    int b[] = { 3,4,5,6 };
    if (sumPairs(a, b, sizeof(a) / sizeof(a[0]), sizeof(b) / sizeof(b[0]), 16) == 0)
        printf("No pairs satisfy the sum.\n");

    if (sumPairsMethod2(a, b, sizeof(a) / sizeof(a[0]), sizeof(b) / sizeof(b[0]), 16) == 0)
        printf("No pairs satisfy the sum.\n");
    
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
    return first_high;

}

int sumPairs(int* a, int* b, int n_a, int n_b, int sum) {
    quickSort(a, 0, n_a - 1);
    quickSort(b, 0, n_b - 1);

    int start = 0;
    int end = n_b - 1;
    while (start <= n_a - 1 && end >= 0) {
        if (a[start] + b[end] == sum) {
            printf("Pairs are: %d of a and %d of b.\n", a[start], b[end]);
            return 1;
        }
        else if (a[start] + b[end] < sum) {
            start++;
        }
        else if (a[start] + b[end] > sum) {
            end--;
        }
    }
    return 0;
}

int binarySearch(int *a, int low, int high, int x) {
    if (low > high)
        return -1;
    int middle = (low + high) / 2;
    if (a[middle] == x)
        return 1;
    else if (a[middle] > x)
        return binarySearch(a, low, middle - 1, x);
    else if (a[middle] < x)
        return binarySearch(a, middle + 1, high, x);
}

int sumPairsMethod2(int* a, int* b, int n_a, int n_b, int sum) {
    quickSort(a, 0, n_a - 1);
    for (int i = 0; i < n_b; i++) {
        int num = sum - b[i];
        if (binarySearch(a, 0, n_a - 1, num) == 1) {
            printf("Pairs are: %d of a and %d of b.\n", num, b[i]);
            return 1;
        }
            
    }
    return 0;
}
// PairSUm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int pairSumPartA(int* a, int n, int sum);
int pairSumPartB(int* a, int n, int sum);
void quickSort(int* a, int low, int high);
int partition(int* a, int low, int high);
int binarySearch(int* a, int low, int high, int x);

int main()
{
    int a[] = { 12,32,43,1,2,3,4,59,99,99,18 };
    pairSumPartA(a, sizeof(a) / sizeof(a[0]), 198);
    pairSumPartB(a, sizeof(a) / sizeof(a[0]), 198);
}

int pairSumPartA(int* a, int n, int sum) {
    quickSort(a, 0, n - 1);
    // After sorting, we can use 2-pointer approach or binary search. Here I use binary search
    for (int i = 0; i < n ;i++) {
        int x = sum - a[i];
        if (binarySearch(a, i + 1, n - 1, x) == 1) {
            printf("Find the pair: %d and %d\n", a[i], x);
            return 1;
        }
    }
    printf("No pairs satisfying the sum\n");
    return -1;
}

int pairSumPartB(int* a, int n, int sum) {
    quickSort(a, 0, n - 1);
    // After sorting, we can use 2-pointer approach or binary search or sum array. Here I use sum array
    int* new_array = new int[n];
    for (int i = 0; i < n;i++) { 
        new_array[i] = sum - a[i];
    }

    for (int i = 0, j = n-1; i < n - 1 && j >=0;) {
        if (new_array[j] == a[i] && i != j) {// for sum method, i must be different from j or it will find elements has sum = 2 *elements;
            printf("Find the pair: %d and %d\n", new_array[i], sum - new_array[i]);
            return 1;
        }
        else if (new_array[j] > a[i])
            i++;
        else
            j--;

    }
    printf("No pairs satisfying the sum\n");
    return -1;
}

int binarySearch(int* a, int low, int high, int x) {
    if (low > high)
        return -1;
    int middle = (low + high) / 2;
    if (a[middle] == x)
        return 1;
    else if (a[middle] > x)
        return binarySearch(a, low, middle - 1, x);
    else
        return binarySearch(a, middle + 1, high, x);
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

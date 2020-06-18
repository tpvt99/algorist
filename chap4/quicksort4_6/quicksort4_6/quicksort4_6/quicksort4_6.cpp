// quicksort4_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>

void quicksort(int* a, int low, int high);
int partition_ascending(int* a, int low, int high);
int partition_descending(int* a, int low, int high);
int partition_ascending_random_pivot(int* a, int low, int high);

int main()
{
    int a[] = { 3,4,1,54,65,32,12,34,54,65,12,312,45,65,76,7687,988 };
    quicksort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    printf("Array a after sorted: ");
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
}

void quicksort(int* a, int low, int high) {
    if (low >= high)
        return;
    int p;
    p = partition_ascending_random_pivot(a, low, high);
    quicksort(a, low, p - 1);
    quicksort(a, p + 1, high);
}

int partition_ascending(int* a, int low, int high) {
    int first_high = low;
    int pivot_index = high;
    for (int i = low; i < high; i++) {
        if (a[i] < a[pivot_index]) {
            int temp = a[i];
            a[i] = a[first_high];
            a[first_high] = temp;
            first_high += 1;
        }
    }
    int temp = a[first_high];
    a[first_high] = a[pivot_index];
    a[pivot_index] = temp;
    return first_high;
}

int partition_ascending_random_pivot(int* a, int low, int high) {
    int first_high = low;
    int pivot_index = rand() % (high - low + 1) + low;
    for (int i = low; i <= high; i++) {
        if (a[i] < a[pivot_index]) {
            if (first_high == pivot_index)
                pivot_index = i;
            int temp = a[i];
            a[i] = a[first_high];
            a[first_high] = temp;
            first_high += 1;
        }
    }
    int temp = a[first_high];
    a[first_high] = a[pivot_index];
    a[pivot_index] = temp;
    return first_high;
}

int partition_descending(int* a, int low, int high) {
    int first_high = low;
    int pivot_index = high;
    for (int i = low; i < high; i++) {
        if (a[i] > a[pivot_index]) {
            int temp = a[i];
            a[i] = a[first_high];
            a[first_high] = temp;
            first_high += 1;
        }
    }
    int temp = a[first_high];
    a[first_high] = a[pivot_index];
    a[pivot_index] = temp;
    return first_high;
}


// mergesort4_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

void mergesort(int* a, int low, int high);
void merge(int* a, int low_a, int high_a, int low_b, int high_b);

int main()
{
    int a[] = { 1,5,95,32,4,5,7,8,65,12,45,78,9,6,3,66,55,22,11,44 };
    mergesort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
        printf("%d ", a[i]);
}


void mergesort(int* a, int low, int high) {
    if (low == high)
        return;

    int middle = (low + high) / 2;
    mergesort(a, low, middle);
    mergesort(a, middle + 1, high);
    merge(a, low, middle, middle + 1, high);
}

void merge(int* a, int low_a, int high_a, int low_b, int high_b) {
    int *temp = new int[high_a - low_a + high_b - low_b +2];
    int counter = 0;
    int i, j;
    for (i = low_a, j = low_b; i <= high_a && j <= high_b;) {
        if (a[i] >= a[j]) {
            temp[counter] = a[i];
            i++;
        }
        else {
            temp[counter] = a[j];
            j++;
        }
        counter++;
    }
    for (;i <= high_a;) {
        temp[counter] = a[i];
        i++;
        counter++;
    }
    for (;j <= high_b;) {
        temp[counter] = a[j];
        j++;
        counter++;
    }
    counter = 0;
    for (i = low_a; i <= high_a; i++, counter++)
        a[i] = temp[counter];
    for (j = low_b; j <= high_b; j++, counter++)
        a[j] = temp[counter];
}

void ascendingMerge(int* a, int low_a, int high_a, int low_b, int high_b) {

}
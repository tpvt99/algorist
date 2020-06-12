// heapsort4_3_MinHeap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#define MAX_QUEUE 100

typedef struct priority_queue {
    int queues[MAX_QUEUE + 1]; // Index always start from 1
    int n;
} priority_queue;


int pq_parent(int index);
int pq_child(int index);
void init_pq(priority_queue* q);
void insert_pq(priority_queue* q, int n);
void bubble_up(priority_queue* q, int index);
void print_pq(priority_queue* q);
int extract_min(priority_queue*);
void bubble_down(priority_queue* q, int index);
void make_heap(priority_queue* q, int s[], int n);
void heap_sort(int *s, int n);
void make_heap_by_heapify(priority_queue* q, int s[], int n);

int main()
{
    priority_queue* q = (priority_queue*)malloc(sizeof(priority_queue));
    int s[] = { 1,4,3,7,8,9,10 };
    make_heap(q, s, sizeof(s) / sizeof(s[0]));
    printf("Heap by incremental insertion: ");
    print_pq(q);

    int ss[] = { 10, 9, 8, 5, 3, 2, 1 };
    priority_queue* q_2 = (priority_queue*)malloc(sizeof(priority_queue));
    make_heap_by_heapify(q_2, ss, sizeof(ss) / sizeof(ss[0]));
    printf("Heap by heapify: ");
    print_pq(q_2);

    // Extracting min and using bubble_down is 1 step of heapsort

    int x = extract_min(q);
    printf("Min item after extracted: %d\n", x);
    std::cout << "Min heap after extracting min: ";
    print_pq(q);

    heap_sort(s, sizeof(s) / sizeof(s[0]));
    std::cout << "Min heap after sorting: ";
    for (int i = 0; i < sizeof(s) / sizeof(s[0]);i++)
        printf("%d ", s[i]);
    
}

int pq_parent(int index) {
    if (index == 1) // no parent at the root node
        return -1;
    return (int)(index / 2);
}

int pq_child(int index) {
    return 2 * index;
}

void init_pq(priority_queue* q) {
    q->n = 0;
}

void make_heap(priority_queue* q, int s[], int n) {
    init_pq(q);
    for (int i = 0; i < n; i++)
        insert_pq(q, s[i]);
}

void make_heap_by_heapify(priority_queue* q, int s[], int n) {
    init_pq(q);
    for (int i = 0; i < n; i++) {
        q->queues[++q->n] = s[i];
    }
    for (int i = q->n; i >= 1; i--)
        bubble_down(q, i);
}

void bubble_up(priority_queue* q, int index) { // bubble_up for min heap
    if (index == 1) // parent node
        return;

    int parent_index = pq_parent(index);
    if (q->queues[parent_index] > q->queues[index]) {
        int temp = q->queues[parent_index];
        q->queues[parent_index] = q->queues[index];
        q->queues[index] = temp;
        bubble_up(q, parent_index);
    }

}

void bubble_down(priority_queue* q, int index) { // bubble_down for min heap
    int minElement = q->queues[index];
    int minIndex = index;
    int child_1 = pq_child(index);
    int child_2 = child_1 + 1;
    if (child_1 <= q->n) {
        if (q->queues[child_1] < minElement) {
            minElement = q->queues[child_1];
            minIndex = child_1;
        }
    }
    if (child_2 <= q->n) {
        if (q->queues[child_2] < minElement) {
            minElement = q->queues[child_2];
            minIndex = child_2;
        }
    }

    if (minIndex != index) {
        int temp = q->queues[index];
        q->queues[index] = minElement;
        q->queues[minIndex] = temp;
        bubble_down(q, minIndex);
    }
}

void insert_pq(priority_queue* q, int number) {
    if (q->n == MAX_QUEUE) {
        printf("Full queue. Cannot add any numbers.\n");
        return;
    }

    q->n = q->n + 1;
    int current_index = q->n;
    int parent_index = current_index / 2;

    q->queues[current_index] = number;
    bubble_up(q, current_index);
}

void print_pq(priority_queue* q) {
    for (int i = 1; i < q->n + 1;i++) {
        printf("%d ", q->queues[i]);
    }
    printf("\n");
}

int extract_min(priority_queue* q) {
    if (q->n == 0) {
        printf("Empty queue.\n");
        return -1;
    }
    int min = q->queues[1];
    q->queues[1] = q->queues[q->n];
    q->n -= 1;
    bubble_down(q, 1);
    return min;
}

void heap_sort(int *s, int n) {
    priority_queue q;
    make_heap(&q, s, n);

    for (int i = 0; i < n; i++) {
        s[i] = extract_min(&q);
    }
}
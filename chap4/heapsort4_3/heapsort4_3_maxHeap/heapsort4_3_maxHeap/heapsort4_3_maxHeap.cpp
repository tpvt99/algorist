// heapsort4_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
int extract_max(priority_queue* q);
void bubble_down(priority_queue* q, int index);

int main()
{
    priority_queue* q = (priority_queue*)malloc(sizeof(priority_queue));
    init_pq(q);
    insert_pq(q, 1);
    insert_pq(q, 4);
    insert_pq(q, 3);
    insert_pq(q, 7);
    insert_pq(q, 8);
    insert_pq(q, 9);
    insert_pq(q, 10);
    print_pq(q);

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

void bubble_up(priority_queue* q, int index) {
    int parent_index = pq_parent(index);
    if (parent_index == -1) // parent node
        return;
   
    if (q->queues[parent_index] < q->queues[index]) {
        int temp = q->queues[parent_index];
        q->queues[parent_index] = q->queues[index];
        q->queues[index] = temp;
        bubble_up(q, parent_index);
    }

}

void bubble_down(priority_queue* q, int index) {

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

int extract_max(priority_queue* q) {
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
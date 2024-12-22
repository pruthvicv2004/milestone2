#include <stdio.h>
#include <string.h>
#include "include/queue.h"

Request queue[MAX_QUEUE];
int front = -1, rear = -1;

void enqueue(char *studentName, char *bookTitle) {
    if (rear == MAX_QUEUE - 1) {
        printf("Request queue is full.\n");
        return;
    }
    if (front == -1) front = 0;
    rear++;
    strcpy(queue[rear].studentName, studentName);
    strcpy(queue[rear].bookTitle, bookTitle);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("No requests to process.\n");
        return;
    }
    printf("Processing request: %s requested %s\n", queue[front].studentName, queue[front].bookTitle);
    front++;
}

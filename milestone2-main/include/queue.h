#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 50

typedef struct {
    char studentName[100];
    char bookTitle[100];
} Request;

void enqueue(char *studentName, char *bookTitle);
void dequeue();

#endif

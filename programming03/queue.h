#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int value;
    struct node*next;
}node;

typedef struct queue{
    struct node*head, *tail;
}queue;

queue*new_queue();
node*new_node(int);
void enqueue(queue*, int);
node*dequeue(queue*);
bool in_list(queue*, int);
void destroy(queue*);


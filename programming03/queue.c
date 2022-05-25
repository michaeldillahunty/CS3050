#include "queue.h"

queue*new_queue(){
    queue*q = malloc(sizeof(queue));
    if(!q){
        perror("malloc failed");
        return q;
    }
    q->head = NULL;
    q->tail = NULL;
    return q;
}

node*new_node(int value){
    node*newNode = malloc(sizeof(node));
    if(!newNode){
        perror("malloc failed");
        return newNode;
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void enqueue(queue*q, int value){
    if(!q){
        return;
    }
    node*newNode = new_node(value);
    if(newNode){
        if(!q->head){
            q->head = newNode;
            q->tail = newNode;
        } else {
            q->tail->next = newNode;
            q->tail = newNode;
        }
    } else {
        return;
    }
}

node*dequeue(queue*q){
    if(!q || !q->head){ 
        return NULL;
    }
    node*temp = q->head;
    q->head = temp->next;
    return temp;
}

bool in_list(queue*list, int value){
    if(!list){     // if there is not a list, there is nothing to find
        return false;
    }
    node*curr = list->head;
    while(curr){
        if(curr->value == value){
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void destroy(queue*q){
    if(!q){
        return;
    }
    node*curr = q->head;
    while(curr){
        curr = curr->next;
        q->head->next = NULL;
        free(q->head);
        q->head = curr;
    }
    q->tail = NULL;
    free(q);
}
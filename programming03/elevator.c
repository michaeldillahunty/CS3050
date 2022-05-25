#include "queue.h"
queue*BFS(int, int, int, int, int);
void input(int*, int*, int*, int*, int*);
void printList(queue* );

void display(){
    printf("Homework 4 - Skyscraper\n");
    printf("Please enter input in <floors> <start> <goal> <up> <down> :\n");
}

queue*BFS(int floors, int start, int goal, int up, int down){
    queue*q = new_queue();
    queue*list = new_queue(); // printable list
    enqueue(q, start);
    node*curr = NULL;
    
        while(q->head){ 
        curr = dequeue(q);
        enqueue(list, curr->value);
        if(curr->value == goal){
            destroy(q);
            free(curr);
            return list;    
        }

        if(curr->value < goal && curr->value + up <= floors && !in_list(list, curr->value + up)){
            enqueue(q, curr->value + up);
        } else if (curr->value - down > 0 && !in_list(list, curr->value - down)) {
            enqueue(q, curr->value - down);
        } free(curr);
    }
    destroy(q);
    destroy(list);
    return NULL;
}

void input(int*floors, int*start, int*goal, int*up, int*down){
    char holder[100] = {0};
    fgets(holder, 100, stdin);
    // fgets reference:
    // www.tutorialspoint.com/c_standard_library/c_function_fgets.htm}
    while(sscanf(holder, "%d %d %d %d %d", floors, start, goal, up, down) != 5){
        printf("Error: Invalid input. Please try again.\n");
        fgets(holder, 100, stdin);
    }
}

void printList(queue*list){
    node*curr = list->head;
    while(curr->next){
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("%d\n", curr->value);
}

int main(){
    int floors = -1;
    int start = 0;
    int goal = 0;
    int up = 0;
    int down = 0;

    do{
        display();
        input(&floors, &start, &goal, &up, &down);
    } while (&floors <= 0 || floors < start || floors < goal);
    queue*list = BFS(floors, start, goal, up, down);
    if(list){
        printf("In order floor travel: ");
        printList(list);
    } else {
        printf("Use the stairs. \n");
    }
    destroy(list);
    return 78;
}
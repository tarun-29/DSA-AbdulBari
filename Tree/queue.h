#include<iostream>

using namespace std;

struct Node{
    int data;;
    struct Node *lptr;
    struct Node *rptr;
};

struct Q{
    struct Node **q;//*Q for array and another one is for Node;
    int front;
    int rear;
    int size;
};

void create(struct Q *p, int size){
    p->size = size;
    p->front = p->rear = NULL;
    p->q = (struct Node **)malloc(p->size*sizeof(struct Node*));
}

void enqueue(struct Q *p, struct Node* x){
    if((p->rear +1)%p->size == p->rear){
        cout<<"Queue is full\n";
    }
    else{
        p->rear = (p->rear+1)%p->size;
        p->q[p->rear] = x;
    }
}

struct Node* dequeue(struct Q *p){
    struct Node *x;
    if(p->rear == p->front){
        cout<<"No element to dequeue\n";
    }
    else{
        p->front=(p->front+1)%p->size;
        x=p->q[p->front];
    }
    return x;
}

int isEmpty(struct Q *p){
    return p->front == p->rear;
}
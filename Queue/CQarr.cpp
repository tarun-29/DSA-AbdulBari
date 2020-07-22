#include<iostream>

using namespace std;

struct Q{
    int *a;
    int front;
    int rear;
    int size;
};

void create(struct Q *p, int size){
    p->size = size;
    p->front = -1;
    p->rear = -1;
    p->a = (int *)malloc(p->size*sizeof(int));
}

void enqueue(struct Q *p, int x){
    if(((p->rear + 1)%p->size) == p->front){
        cout<<"Queue is Full\n";
    }
    else
    {
        p->rear = (p->rear + 1)%p->size;
        p->a[p->rear] = x;
    }
    
}

int dequeue(struct Q *p){
    int x = -1;
    if(p->rear == p->front){
        cout<<"No element to dequeue\n";
    }
    else{
        p->front = (p->front+1)%p->size;
        x = p->a[p->front];
    }
    return x;
}

void display(struct Q *p){
    int i=0;
    if(p->front == p->rear){
        cout<<"No items to show in queueue";
    }
    else
    {
        for(int i=p->front+1; i<=p->rear; i++){
            cout<<p->a[i];
        }
    }
    
}

int main(){
    struct Q q;
    int n;
    cout<<"Enter the size of queue\n";
    cin>>n;
    create(&q,n);
}
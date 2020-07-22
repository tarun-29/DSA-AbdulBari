#include<iostream>

using namespace std;

struct Q{
    int data;
    struct Q*nptr;
};

struct Q *front, *rear;

void enqueue(int n){
    struct Q *temp;
    for(int i=0; i<n; i++){
        temp = (struct Q*)malloc(sizeof(struct Q));
        cout<<"Enter the element"<<endl;
        cin>>temp->data;
        temp ->nptr = NULL;
        if(front == NULL){
            front = rear = temp;
        }
        else{
            rear->nptr = temp;
            rear = temp;
        }
    }
}

void display(){
    struct Q *p =front;
    while(p){
        cout<<p->data<<" "<<endl;
        p = p->nptr;
    }
}

int pop(){
    struct Q *temp;
    int x;
    if(front == rear){
        front = rear = NULL;
        cout<<"No element to pop"<<endl;
    }
    else
    {
        x = front->data;
        temp = front;
        front = front->nptr;
        free(temp);
    }
    return x;
}

int main(){
    int n;
    cout<<"Enter how many element you want to enter"<<endl;
    cin>>n;
    enqueue(n);
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
    pop();
    display();
}
#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *nptr;
};

struct Node *top = NULL;

void push(int x){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL){
        cout<<"No stack space is available"<<endl;
    }
    else{
        temp->data = x;
        temp->nptr = top;
        top = temp;
    }
}

int pop(){
    struct Node *temp;
    int x;
    if(top==NULL){
        cout<<"No node to delete"<<endl;
    }
    else{
        temp = top;
        top = top->nptr;
        x = temp->data;
    }
    return x;
}

void display(){
    struct Node *p;
    p = top;
    while(p!=NULL){
        cout<<p->data<<endl;
        p = p->nptr;
    }
    cout<<endl;
}

int main(){
    push(20);
    push(10);
    push(30);
    push(50);
    push(40);
    display();
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
    pop();
}
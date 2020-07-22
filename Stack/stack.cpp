#include<iostream>

using namespace std;

struct Stack{
    int *a;
    int top;
    int size;
};

int isEmpty(struct Stack *p){
    if(p->top==-1){
        cout<<"Stack is empty"<<endl;
    }
}

void display(struct Stack *p){
    for(int i=p->top; i>=0; i--){
        cout<<p->a[i]<<endl;
    }
}

void push(struct Stack *p, int x){
    if(p->top == p->size-1){
        cout<<"Stack is Full"<<endl;
    }
    else
    {
        p->top++;
        p->a[p->top] = x;
    }
}

int pop(struct Stack *p){
    int x = -1;
    if(p->top==-1){
        cout<<"Stack is empty no element to remove"<<endl;
    }
    else
    {
        x = p->a[p->top];
        p->top --;
    }
    return x;
}

int peek(struct Stack *p, int index){
    int x = -1;
    if(p->top<index-1){
        cout<<"No element available at particular index"<<endl;
    }
    else
    {
        x = p->a[index];
    }
    return x;
}

int main(){
    struct Stack *st;
    int n;
    cout<<"\n Enter the size of stack\n";
    cin>>st->size;
    st->a = (int*)malloc(n*sizeof(struct Stack));
    st->top = -1;
    return 0;
}
#include<iostream>

using namespace std;

struct Node{
    char data;
    struct Node *nptr;
};

struct Node *top = NULL;

void push(char x){
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

int isBalanced(string input){
    int i;
    for(int i=0; input[i]!='\0'; i++){
        if(input[i]=='('){
            push(input[i]);
        }
        if(input[i]==')'){
            if(top==NULL){
                return 0;
            }
            pop();
        }
    }
    if(top==NULL){
        return 1;
    }
    else
    {
        return 0;
    }
    
}

int main(){
    char input[100];
    cout<<"Please enter the expression"<<endl;
    gets(input);
    cout<<isBalanced(input);
}
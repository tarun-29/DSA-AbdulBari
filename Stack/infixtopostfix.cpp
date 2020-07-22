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

int isOperand(char x){
    // cout<<"From Operand Function"<<endl;
    if(x=='+' || x=='-' || x=='/' || x=='*'){
        return 0;
    }
    else
    {
        return 1;
    }   
}

int precedence(char x){
    // cout<<"From p[recedentce"<<endl;
    if(x == '/' || x =='*'){
        return 2;
    }
    else if(x == '+' || x == '-')
    {
        return 1;
    }
    return 0;
}


char * infixtopostfix(char * input){
    int i=0,j=0;
    char *postfix;
    int len=strlen(input);
    postfix=(char *)malloc((len+2)*sizeof(char));
    while(input[i]!='\0')
    {
        if(isOperand(input[i]))
            postfix[j++]=input[i++];
        else
        {
            if(precedence(input[i])>precedence(top->data))
                push(input[i++]);
            else{
                postfix[j++]=pop();
            }
        }
    }
    // cout<<"OK";
    while(top!=NULL)
    postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}


int main(){
    // char input[100];
    char *input = "a+b*c-d/e";
    // cout<<"Please enter the expression"<<endl;
    // gets(input);
    push('#');
    char *postfix = infixtopostfix(input);
    cout<<postfix;
    return 0;
}

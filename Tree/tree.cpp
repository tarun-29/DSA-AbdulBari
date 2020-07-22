#include<iostream>
#include "queue.h"

using namespace std;

struct Node *root =NULL;

void TreeCreate(){
    struct Node *p, *t;
    int x;
    struct Q *q;
    create(q, 100);
    cout<<"Enter root value"<<endl;
    cin>>x;
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->lptr = root->rptr = NULL;
    enqueue(q,root);
    while(!isEmpty(q)){
        p = dequeue(q);
        cout<<"Enter Left child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t = (struct Node*)malloc(sizeof(struct Node));    
            t->data = x;
            t->lptr = NULL;
            t->rptr = NULL;
            p->lptr = t;
            enqueue(q, t);
        }
        cout<<"Enter Right child of "<<p->data<<endl;
        cin>>x;
        if(x!=-1){
            t = (struct Node*)malloc(sizeof(struct Node*));    
            t->data = x;
            t->lptr = NULL;
            t->rptr = NULL;
            p->rptr = t;
            enqueue(q, t);
        }
    }
}

void preorder(struct Node *p){
    if(p){
        cout<<p->data<<endl;
        preorder(p->lptr);
        preorder(p->rptr);
    }
}

int main(){
    TreeCreate();
    preorder(root);

    return 0;
}
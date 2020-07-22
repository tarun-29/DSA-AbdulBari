#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *lptr;
    struct Node *rptr;
}*root = NULL;

void insert(int data){
    struct Node *t = root;
    struct Node *r = NULL;
    struct Node *p;

    if(root == NULL){
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = data;
        p->lptr = NULL;
        p->rptr = NULL;
        root = p;
        return;
    }
    while(t!=NULL){
        r = t;
        if(data<t->data){
            t = t->lptr;
        }
        else if(data>t->data){
            t = t->rptr;
        }
        else
            return;
    }
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = data;
    p->lptr = NULL;
    p->rptr = NULL;
    if(data<r->data){
        r->lptr = p;
    }
    else
    {
        r->rptr = p;
    }
    
}

void printing(struct Node *temp){
    // cout<<temp<<endl;
    if(temp){
    // cout<<"Ok/";
        printing(temp->lptr);
        cout<<temp->data;
        printing(temp->rptr);
    }
}

int main(){
    int n;
    int x;
    cout<<"Enter the number of values you want to insert in BST\n";
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        insert(x);
    }
    printing(root);
    return 0;
}
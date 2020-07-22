#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *pptr;
    struct Node *nptr;
}*rptr = NULL;


void create(int a[], int n){
    struct Node *temp, *t;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = a[0];
    temp->nptr = NULL;
    temp->pptr = NULL;
    for(int i=1; i<n; i++){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = a[i];
        t->pptr = temp;
        t->nptr = temp->nptr;
        temp->nptr = t;
        temp = t;
    }
}

int length(struct Node *p)
{
    int len=0;
    while(p){
        len++;
        p=p->nptr;
    }
    return len;
}

void display(struct Node *p){
    while(p!=NULL){
        cout<<p->data<<endl;
        p = p->nptr;
    }
}

void insert(struct Node *p, int n, int x){
    struct Node *temp;
    if(n<0 || n>length(p)){
        return;
    }
    if(n==0){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp ->data = x;
        temp ->pptr = NULL;
        temp ->nptr = rptr;
        rptr->pptr = temp;
        rptr = temp;
    }
    else{
        for(int i=0; i<n-1; i++){
            p = p->nptr;
        }
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = x;
        temp->pptr = p;
        temp->nptr = p->nptr;
        if(p->nptr)
        p->nptr->pptr = temp;
        p->nptr = temp;
    }
}

void deletenode(struct Node *p, int x){
    struct Node *temp;
    if(x<0 || x>length(p)){
        return;
    }
    if(x == 0){
        rptr = rptr->nptr;
        if(rptr) rptr->pptr = NULL;
        free(p);
    }
    else
    {
        for(int i=0; i<x-1; i++){
            p = p->nptr;
        }
        p->pptr->nptr = p->nptr;
        if(p->nptr){
            p->nptr->pptr = p->pptr;
            free(p);
        }
    }
    
}

void reverse(struct Node *p, int n){
    int a[n+1];
    int i=0;
    while (p!=NULL)
    {
        a[i] = p->data;
        i++;
        p = p->nptr;
    }
    for(; i!=0; i--){
        p->data = a[i];
        p = p->nptr;
    }
    
}

int main(){
    int a[] = {1,2,3,4,5,6};
    create(a, 6);
}

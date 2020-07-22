#include<iostream>

using namespace std;

struct Node {
    int data;
    struct Node *nptr;
};

struct Node *rptr;

void create(int a[], int n){
    struct Node *temp, *t;
    rptr = (struct Node*)malloc(sizeof(struct Node));
    rptr->data = a[0];
    rptr->nptr = rptr;
    t = rptr;
    for(int i=1; i<n; i++){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = a[1];
        temp->nptr = t->nptr;
        t->nptr = temp;
        t = temp;
    }
}

void display(struct Node *p){
    do{
        cout<<p->data<<endl;
        p = p->nptr;
    }while(p->nptr!=rptr);
}

int length(struct Node *rptr){
    int len =0 ;
    do{
        len++;
        rptr = rptr->nptr;
    }while(rptr!=rptr);
    return len;
}

void insert(struct Node *p, int n, int x){
    struct Node *temp;

    if(n<0 || n>length(p)){
        return;
    }
    if(n==0){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = x;
        if(rptr == NULL){
            rptr = temp;
            rptr->nptr = rptr; 
        }
        else{
            while(p->nptr!=rptr){
                p = p->nptr;
            }
            p->nptr = temp;
            temp->nptr = rptr;
            rptr = temp;
        }
    }
    else{
        for(int i=0; i<n-1; i++){
            p = p->nptr;
        }
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = x;
        temp->nptr = p->nptr;
        p->nptr = temp;
    }
}

void delete1(struct Node *p, int x){
    struct Node *q;
    if(x<0 || x > length(p)){
        return;
    }
    if(x == 1){
        do{
            p = p->nptr;
        }while(p!=rptr);
        if(p == rptr){
            free(rptr);
            rptr = NULL;
        }
        else
        {
            p->nptr = rptr->nptr;
            free(rptr);
            rptr = NULL;
        }
    }
    else
    {
        for(int i=0; i<x-2; i++){
            p = p->nptr;
        }
        q = p->nptr;
        p->nptr = q->nptr;
        free(q);
    }
    
}

struct Node *rptr;

int main(){
    int A[] = {2,3,4,5,6};
    create(A,5);
}
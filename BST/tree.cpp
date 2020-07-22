#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *rptr;
    struct Node *lptr;
};

struct Node *root = NULL;

void insert(int x){
    struct Node *t = root;
    struct Node *r = NULL;
    struct Node *p;
    if(root == NULL){
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = x;
        p->lptr =NULL;
        p->rptr = NULL;
        root = p;
        return;
    }
    while(t!=NULL){
        r = t;
        if(x < t->data){
            t = t->lptr;
        }
        else if(x>t->data){
            t = t->rptr;
        }
        else{
            cout<<"Not inserted"<<endl;
            return;
        }
    }
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = x;
    p->lptr = NULL;
    p->rptr = NULL;
    if(x < r->data){
        r->lptr = p;
    }
    else
    r->rptr = p;
}

void inorder(struct Node *p){
    if(p){
        inorder(p->lptr);
        cout<<p->data<<endl;
        inorder(p->rptr);
    }
}

struct Node *search(int x){
    struct Node* p = root;
    while(p!=NULL){
        if(x == p->data){
            return p;
        }
        if(x<p->data){
            p = p->lptr;
        }
        else if(x> p->data){
            p = p->rptr;
        }
    }
    return NULL;
}

int Height(struct Node *p){
    int x,y;
    if(p == NULL){
        return 0;
    }
    x = Height(p->lptr);
    y = Height(p->rptr);
    return x>y ?x+1 : y+1;
}

struct Node * Inpre(struct Node *p){
    if(p && p->rptr!=NULL){
        p = p->rptr;
    }
    return p;
}

struct Node * Insucc(struct Node *p){
    if(p && p->lptr!=NULL){
        p = p->lptr;
    }
    return p;
}

struct Node *deleteNode(struct Node *p, int x){
    struct Node *temp;
    if(p == NULL){
        return NULL;
    }
    if(p->lptr == NULL && p->rptr == NULL){
        if(p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if(x < p->data){
        p->lptr = deleteNode(p->lptr, x);
    }
    else if(x > p->data){
        p->rptr = deleteNode(p->rptr, x);
    }
    else{
        if(Height(p->lptr) > Height(p->rptr)){
            temp = Inpre(p->lptr);
            p->data = temp->data;
            p->lptr = deleteNode(p->lptr, p->data);
        }
        if(Height(p->lptr) < Height(p->rptr)){
            temp = Inpre(p->rptr);
            p->data = temp->data;
            p->rptr = deleteNode(p->rptr, p->data);
        }
    }
    return p;
}

int main(){
    int n;
    int x;
    struct Node *temp;
    cout<<"Enter the number of element  you want to insert\n";
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Enter number";
        cin>>x;
        insert(x);
    }
    cout<<"Enter the element you want to search\n";
    cin>>x;
    inorder(root);
    temp = search(x);
    if(temp!=NULL){
        cout<<"ELement found";
    }
    else{
        cout<<"No element";
    }
    return 0;
}

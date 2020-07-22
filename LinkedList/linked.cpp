//you have to make different function to insert in node you can generalize it 
//but in this it is like this
#include<iostream>

using namespace std;

struct Node{
    int x;
    struct Node *nptr;
};

struct Node *third = NULL;
struct Node *rptr = NULL;
struct Node *rptr1 = NULL;


void insert(int A[], int n){
    int i;
    struct Node *t,*last;
    rptr = (struct Node*)malloc(n*sizeof(struct Node));
    rptr->x = A[0];
    rptr->nptr = NULL;
    last = rptr;
    for(i=1; i<n; i++){
        t = (struct Node*)malloc(n*sizeof(struct Node));
        t->x = A[i];
        t->nptr = NULL;
        last->nptr = t;
        last = t;
    }
    while(rptr!=NULL){
        rptr = rptr->nptr;
    }
}

void insert1(int A[], int n){
    int i;
    struct Node *t,*last;
    rptr1 = (struct Node*)malloc(n*sizeof(struct Node));
    rptr1->x = A[0];
    rptr1->nptr = NULL;
    last = rptr1;
    for(i=1; i<n; i++){
        t = (struct Node*)malloc(n*sizeof(struct Node));
        t->x = A[i];
        t->nptr = NULL;
        last->nptr = t;
        last = t;
    }
}

//Node Count in linked list
int nodeCount(struct Node *rptr){
    int k=0;
    while(rptr!= NULL){
        k++;
        rptr = rptr->nptr;
    }
    // cout<<"No of nodes are: "<<k<<endl;
    return k;
}

//sum of all element in linked list
void sumele(struct Node *rptr){
    int sum = 0;
    while(rptr!=NULL){
        sum = sum + rptr->x;
        rptr = rptr->nptr; 
    }
    cout<<"Sum of all element in Node is: "<<sum<<endl;
}

//find the max element in linked list
int maxelement (struct Node *rptr){
    int max = rptr->x;
    while (rptr!=NULL)
    {
        if(rptr->x>max){
            max = rptr->x;
        }
        rptr = rptr->nptr;
    }
    return max;
}

//searching 
int search(struct Node *rptr, int x){
    while(rptr!=NULL){
        if(rptr->x == x){
            return  rptr->x;
        }
        rptr = rptr->nptr;
    }
}

//insert at a particular position
void add(struct Node *rptr, int x, int n){
    struct Node *temp;
    // cout<<"ok"<<endl;
    // cout<<nodeCount(rptr)<<endl;
    if(n<0 || n>nodeCount(rptr)){
        return;
    }
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->x = x;
    if(n==0){
        cout<<rptr<<"rptr:"<<endl;
        cout<<temp<<"temp:"<<endl;
        temp->nptr = rptr;
        rptr = temp;
        cout<<rptr<<"rptr"<<endl;
        cout<<rptr->nptr<<"rptr->nptr"<<endl;
    }
    else{
        for(int i=1; i<n-1; i++){
            rptr = rptr->nptr;
        }
        temp->nptr = rptr->nptr;
        rptr->nptr = temp;
    }   
}

//insert in sorted list or in sorted position
void sort(struct Node *rptr){
    
}

//recursive display
void display1(struct Node *rptr){
    if(rptr!=NULL){
        cout<<rptr->x<<endl;
        display1(rptr->nptr);
    }
}

//simple display
void display(struct Node *rptr){
    while(rptr!=NULL){
        cout<<rptr->x<<endl;
        rptr = rptr->nptr;
    }
}

void addlast(struct Node *rptr, int x){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->x = x;
    int count = 0;
    temp->nptr = NULL;
    while(rptr!=NULL){
        // cout<<count++;
        if(rptr->nptr == NULL){
            // cout<<rptr->nptr<<endl;
            rptr->nptr = temp;
            break;
        }
            rptr = rptr->nptr;
    }
}

void addatsortedpos(struct Node *rptr, int x){
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->x = x;
    while(rptr!=NULL){
        if(rptr->x<x && x<rptr->nptr->x){
            temp->nptr = rptr->nptr;
            rptr->nptr = temp;
            break;
        }
        rptr = rptr-> nptr;
    }
}

void deletenode(struct Node *rptr, int n){
    if(n==0){
        struct Node *p = rptr;
        rptr = rptr->nptr;
        delete p;
    }
    // while(rptr!=NULL){
    //     cout<<rptr->x;
    //     rptr = rptr->nptr;
    // }
}

//check if linked list is sorted
bool isSorted(struct Node *rptr){
    int x = -32768;
    while(rptr!=NULL){
        if (rptr->x<x)
        {
            return false;
        }
        x = rptr->x;
        rptr = rptr->nptr;
    }
    return true;
    
}

void removeDup(struct Node *rptr, int maxe){
    int hash[maxe+1] ;
    for(int i=0; i<maxe; i++){
        hash[i] = 0;
        // cout<<hash[i]<<endl;
    }
    struct Node*temp, *temp1;
    temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp = rptr;
    while (rptr!=NULL)
    {
        cout<<"OK"<<endl;
        cout<<"hash["<<rptr->x<<"]"<<hash[rptr->x]<<endl;
        if(hash[rptr->x] ==1){
            cout<<"OK thankyou"<<endl;
            temp1->nptr = rptr->nptr;
            rptr = temp1;
            delete(temp1->nptr);
        }
        temp1 = rptr;
        cout<<"thankyou"<<endl;
        hash[rptr->x] = 1;
        rptr = rptr->nptr;
    }
    cout<<"Answer";
    while(temp!=NULL){
        cout<<"bhsdk"<<endl;
        cout<<temp->x<<endl;
        temp = temp->nptr;
    }
}

//reverse linked list
void reverselist(struct Node*rptr){
    int rev[50];
    int i=0;
    struct Node *temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp = rptr;
    while(rptr!=NULL){
        rev[i] = rptr->x;
        i++;
        rptr = rptr->nptr;
    }
    cout<<"i: "<<i<<endl;
    rev[i] = 8999;
    rptr = temp;
    while(rptr!=NULL && i!=0){
        // cout<<rev[i-1]<<endl;
        rptr->x = rev[i-1];
        i--;
        rptr = rptr->nptr; 
    }
    rptr = temp;
    while (rptr!=NULL)
    {
        cout<<rptr->x<<endl;
        rptr = rptr->nptr;
    }
    
}

//reverse linked list using sliding pointer
void reverse1(struct Node *rptr){
    struct Node *p;
    struct Node *q;
    struct Node *r;
    p = (struct Node*)malloc(sizeof(struct Node));
    q = (struct Node*)malloc(sizeof(struct Node));
    r = (struct Node*)malloc(sizeof(struct Node));
    p = rptr;
    q = NULL;
    r = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->nptr;
        q->nptr = r;
    }
    rptr = p;
    while(rptr!=NULL){
        cout<<rptr->x;
        rptr = rptr->nptr;
    }
}

//concatination of two list
void join(struct Node *rptr, struct Node *rptr1){
    struct Node * temp;
    temp = rptr;
    while(temp->nptr!=NULL){
        temp = temp->nptr; 
    }
    // cout<<temp->nptr<<endl;
    // cout<<"rptr1"<<rptr1<<endl;
    temp->nptr = rptr1;
    // cout<<temp->nptr<<endl;
    rptr1 = NULL;
    while(rptr!=NULL){
        cout<<rptr->x<<endl;
        rptr = rptr->nptr;
    }
}


//merging list in sorted order
void merge(struct Node *rptr, struct Node *rptr1){
    struct Node *last;
    if(rptr->x < rptr1->x){
        last = third = rptr;
        rptr = rptr->nptr;
        third->nptr = NULL;
    }
    else if(rptr->x > rptr1->x){
        last = third = rptr1;
        rptr1 = rptr1->nptr;
        third->nptr = NULL;
    }
    while(rptr && rptr1){
        if(rptr->x < rptr1->x){
            last->nptr = rptr;
            last = rptr;
            rptr = rptr->nptr;
            last->nptr = NULL;
        }
        else{
            last->nptr = rptr1;
            last =rptr1;
            rptr1 = rptr1->nptr;
            last->nptr = NULL;
        }
    }
    if(rptr){
        last->nptr = rptr;
    }
    if(rptr1){
        last->nptr = rptr1;
    }
}


//check for loop in linked list
int chkloop(struct Node  *rptr){
    struct Node *p, *q;
    p = q = rptr;
    do{
        p = p->nptr;
        q = q->nptr;
        q = q?q->nptr : q;
    }while(p && q && p!=q);
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int A[] = {2,8,10,15};
    int B[] = {4,7,12,14};
    insert(A, 4);
    insert1(B,4);
    // insert(B, 6);
    // nodeCount(rptr);
    // sumele(rptr);
    // int x;
    // int m;
    // cout<<"Maximum element is : "<<maxelement(rptr)<<endl;
    // cout<<"Enter the element you want to search : "<<endl;
    // cin>>x;
    // cout<<search(rptr, x);
    // cout<<"Enter the element you want to insert"<<endl;
    // cin>>x;
    // cout<<"Enter the position where you want to insert the element"<<endl;
    // cin>>m;
    // add(rptr,x,m);
    // addatsortedpos(rptr, x);
    // addlast(rptr, x);
    // deletenode(rptr, 0);
    // display(rptr);
    // cout<<isSorted(rptr)<<endl;
    // removeDup(rptr, 8);
    // display(rptr);
    // reverse1(rptr);
    merge(rptr, rptr1);
    display(third);
    // join(rptr,rptr1);
    return 0;
}

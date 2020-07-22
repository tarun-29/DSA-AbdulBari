#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node* nptr;
    struct Node* pptr;
};

struct Node *rptr, *last = NULL;

void createElement(struct Node *p){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    int n;
    cout<<endl<<"Enter the number you want to insert"<<endl;
    cin>>n;
    temp->data = n;
    temp->nptr = temp;
    temp->pptr = temp;
    if(last==NULL){
        rptr = last = temp;
    }
    else{
        last->nptr = temp;
        temp->pptr = last;
        last = temp;
        rptr->pptr = last;
    }
        last->nptr = rptr;    
}

void display(){
    struct Node * temp;
    temp = rptr;
    if(temp == NULL){
        cout<<"Empty List"<<endl;
    }
    else
    {
        do{
            cout<<temp->data;
            temp = temp->nptr;
        }while(temp!=rptr);
    }
    
}

void deleteNode(){
    int n;
    cout<<"enter the position you want to delete element"<<endl;
    cin>>n;
    struct Node *temp;
        temp = rptr;
    if(n==1){
        temp->pptr->nptr = temp->nptr;
        temp->nptr->pptr = temp->pptr;
        rptr = temp->nptr;
        free(temp);
    }
    else{
        for(int i=2; i<=n; i++){
            temp = temp->nptr;
        }
        temp->pptr->nptr = temp->nptr;
        temp->nptr->pptr = temp->pptr;
    }
    temp->nptr = NULL;
        free(temp);
}

int main(){
    int chc;
    cout<<"endl";
    do{
        cout<<"To enter the element press 1:"<<endl;
        cout<<"To display element press 2:"<<endl;
        cout<<"To delete element press 3:"<<endl;
        cout<<"Press 4  to exit"<<endl;
        cout<<endl<<"Please enter the choice"<<endl;
        cin>>chc;
        switch (chc)
        {
        case 1:
            createElement(rptr);
            break;
        case 2:
            display();
            break;
        case 3:
            deleteNode();
            break;
        case 4:
            return 1;
        default:
            cout<<"Invalid Choicce";
        }
    }while(1);
    return 0;
}
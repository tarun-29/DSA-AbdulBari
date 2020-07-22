#include<iostream>

using namespace std;

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse{
    int m;
    int n;
    int num;
    struct Element *e;
};


void insert(struct Sparse *s){
    int k;
    int p,q,r;
    cout<<"Enter the Dimension of array row and column respetivly"<<endl;
    cin>>s->m>>s->n;
    cout<<"Enter the number of non-zero element in matirx"<<endl;
    cin>>s->num;
    s->e = (struct Element*)(malloc(s->num * sizeof(struct Element)));
    cout<<"Remeber start your i, j index from zero set according to that"<<endl;
    for(k=0; k<s->num; k++){
        cout<<"Enter i, j and value respectively"<<endl;
        cin>>p>>q>>r;
        s->e[k].i = p;
        s->e[k].j = q;
        s->e[k].x = r;
    }
}

void display(struct Sparse s){
    int i,j;
    int k=0;
    for(i=0;i<s.m;i++){
        for(j=0;j<s.n;j++){
            if(i==s.e[k].i && j==s.e[k].j){
                cout<<s.e[k++].x<<" ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

struct Sparse * addition(struct Sparse *s1, struct Sparse *s2){
    // if(s1->m != s2->m && s1->n != s2->n){
    //     cout<<"Addition Can't be performed"<<endl;
    //     return 0;
    // }
    struct Sparse * sum;
    int i=0,j=0,k =0;
    sum = (struct Sparse *)malloc(sizeof(struct Sparse));
    sum->m = s1->m;
    sum->n = s1->n;
    sum->e = (struct Element *)malloc((s1->num+s2->num)*sizeof(struct Element));

    while(i<s1->num && j<s2->num){
        if(s1->e[i].i>s2->e[j].i){
            sum->e[k] = s1->e[i];
            k++; i++;
        }
        else if(s1->e[i].i<s2->e[j].i){
            sum->e[k] = s2->e[j];
            k++; j++;
        }
        else
        {
            if(s1->e[i].j<s2->e[j].j){
                sum->e[k] = s1->e[i];
                k++; i++;
            }
            else if(s1->e[i].j>s2->e[j].j){
                sum->e[k] = s2->e[j];
                k++; j++;
            }
            else
            {
                sum->e[k] = s1->e[i];
                sum->e[k].x = s1->e[i].x + s2->e[j].x;
                i++;j++;k++;
            }
            
        }   
    }
    for(; i<s1->num; i++){
        sum->e[k] = s1->e[i];
        k++;
    }
    for(; j<s2->num; j++){
        sum->e[k] = s2->e[j];
        k++;
    }
    sum->num = k;
    return sum;
}

int main(){
    struct Sparse s1;
    struct Sparse s2;
    struct Sparse *s3;
    insert(&s1);
    insert(&s2);
    s3 = addition(&s1, &s2);
    display(*s3);
}
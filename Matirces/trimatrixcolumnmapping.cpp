//code not working formula is correct

#include<iostream>

using namespace std;

class trimatrix{
    private: 
        int *a;
        int n;
    public:
        trimatrix(int n){
            this->n = n;
            n = (n*(n+1))/2;
            a = new int[n];
        }
        ~trimatrix(){
            delete[]a;
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
};

void trimatrix :: set(int i, int j, int x){
    if(i>=j){
        int k = (n*(j-1) - ((j-2)*(j-1))/2)+(i-j);
        a[k] = x;
    }
}

int trimatrix :: get(int i, int j){
    if(i>=j){
        int k = (n*(j-1) - ((j-2)*(j-1))/2)+(i-j);
        return a[k];
    }
    else
        return 0;
}

void trimatrix :: display(){
    cout<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i>=j){
                int k = (n*(j-1) - ((j-2)*(j-1))/2)+(i-j);
                cout<<endl<<"k: "<<k<<endl;
                cout<<a[k];
            }
            else
            {
                cout<<"0";
            }
        }
    cout<<endl;

    }
}

int main(){
    int n;
    int x;
    cout<<"enter dimension of matrix"<<endl;
    cin>>n;
    trimatrix d(n);
    cout<<"Enter the element in matrix"<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++ ){
                cin>>x;
                d.set(i, j, x);
        }
    }
    d.display();
}
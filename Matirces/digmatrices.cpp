#include<iostream>

using namespace std;

class digmatrix{
    private: 
        int *a;
        int n;
    public:
        digmatrix(int n){
            this->n = n;
            a = new int[n];
        }
        ~digmatrix(){
            delete[]a;
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
};

void digmatrix :: set(int i, int j, int x){
    if(i==j)
        a[i-1] = x;
}

int digmatrix :: get(int i, int j){
    if(i==j){
        return a[i-1];
    }
}

void digmatrix :: display(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){
                cout<<a[i-1]<<" ";
            }
            else
            {
                cout<<"0";
            }
            cout<<endl;
        }
    }
}

int main(){
    int n;
    int x;
    cout<<"enter dimension of matrix"<<endl;
    cin>>n;
    digmatrix d(n);
    cout<<"Enter the element in matrix"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j){
                cin>>x;
                d.set(i,j,x);
            }
        }
    }
    d.display();
}
#include<iostream>

using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

//single missing element in array if start with 1
int miselesingle(struct Array *arr){
    // cout<<endl<<arr->size<<endl;
    // cout<<endl<<arr->length<<endl;
    int sum = 0;
    int asum =0, i =0;
    for(i=0; i<arr->length; i++){
        sum = sum + arr->A[i];
    }
    asum = (arr->A[arr->length-1]) * (arr->A[arr->length-1] + 1);
    asum = asum/2;
    return asum - sum;
}

//in between missing single element not starting with 1 start with any number
int miselesingle1(struct Array *arr){
    int dif = arr->A[0] - 0;
    int mdif = 0;
    int i;
    for(i=0; i<arr->length; i++){
        mdif = arr->A[i] - i;
        if(mdif != dif){
            return i+dif;
            break;
        }
    }
}

//many missing element(in between) not start with 1 
void miselemany(struct Array *arr){
    struct Array *misarr = (struct Array *)malloc(arr->length * sizeof(struct Array));
    int dif = arr->A[0]-0;
    int mdif = 0;
    int k=0;
    int i;
    for(i=0; i<arr->length; i++){
        mdif = arr->A[i] - i;
        if(mdif!=dif){
            while(dif<mdif){
                cout<<endl<<i+dif<<endl;
                dif++;
            }
        }
    }
}

//find missing elements using hashing table 
struct Array * misshash(struct Array *arr, int max){
    int hash[max];
    // struct Array*hash = (struct Array *)malloc(max * sizeof(struct Array));
    // cout<<sizeof(hash->A);
    // hash->length = max;
    // hash->size = max;
    // cout<<"\t hash length and size: "<<hash->length<<"\t"<<hash->size<<endl;
    // cout<<"\t length and size: "<<arr->length<<"\t"<<arr->size<<endl;
    int i,j;
    for(i=0; i<max; i++){
        hash[i] = 0;
    }
    // for(int k=0; k<max; k++){
    //     cout<<endl<<hash[k]<<endl;
    // }
    for(j=0; j<arr->length; j++){
        // cout<<endl<<arr->A[j]<<endl;
        hash[arr->A[j]]++;
    }
    cout<<endl<<"Missing Elements are: ";
    for(int k=1; k<max; k++){
        if(hash[k] != 1)
        cout<<k<<"\t";
    }
    // return hash;

}

//finding duplicate elements sorted
void duplicate(struct Array *arr){
    int count;
    int j=0;
    for(int i=0; i<arr->length-1; i++){
        if(arr->A[i] == arr->A[i+1]){
            j = i+1;
            while (arr->A[j] == arr->A[i])
            {
                j++;
            }
            cout<<endl<<"Duplicate elemnts is: "<<arr->A[i]<<" "<<j-i<<" times";
            i = j-1;
        }
    }
}

//finding duplicate using hashing sorted
void duplicatehash(struct Array *arr, int maxno){
    int duphash[maxno+1];
    int i;
    for(i=0; i<arr->length; i++){
        duphash[i] = 0;
    }
    for(i=0; i<arr->length; i++){

        duphash[arr->A[i]] = duphash[i] + 1;
    }
    for(i=0; i<=maxno; i++){
        if(duphash[i] != 0 && duphash[i]<maxno && duphash[i]>0){
            cout<<endl<<"the duplicate elements is: "<<i<<"and frequency is: "<<duphash[i]<<endl;
        }
    }
}

//finding duplicate element in unsorted array
void duplicateunsorted(struct Array *arr){
    int j;
    for(int i=0; i<arr->length-1; i++){
        int count =1;
        if(arr->A[i] != -1){
            for(int j = i+1; j<arr->length; j++){
                if(arr->A[i] == arr->A[j]){
                    count++;
                    arr->A[j] = -1;
                }
            }
            if(count>1){
                cout<<endl<<"element: "<<arr->A[i]<<" count is : "<<count<<endl;
            }
        }
    }
}

//finding duplicate element in unsorted array
//may be no completed
void duplicatehashunsort(struct Array *arr, int maxno){
    int duphash[maxno+1];
    int i;
    for(i=0; i<arr->length; i++){
        duphash[i] = 0;
    }
    for(i=0; i<arr->length; i++){

        duphash[arr->A[i]] = duphash[i] + 1;
    }
    cout<<endl;
    for(int k=0; k<maxno+1; k++){
        cout<<duphash[k]<<"\t";
    }
    for(i=0; i<=maxno; i++){
        if(duphash[i] != 0 && duphash[i]<maxno && duphash[i]>0){
            cout<<endl<<"the duplicate elements is: "<<i<<"and frequency is: "<<duphash[i]<<endl;
        }
    }
}

//without hashing
void kpair(struct Array *arr, int msum){
    for(int i=0; i<arr->length; i++){
        for(int j=0; j<arr->length; j++){
            if(arr->A[i] + arr->A[j] == msum){
                cout<<i<<j<<endl;
            }
        }
    }
}


//with hashing 
void hashpair(struct Array *arr, int sum, int maxvalue){
    int hash1[maxvalue+1];
    for(int i=0; i<maxvalue; i++){
        hash1[i] = 0;
    }
    for(int i=0; i<arr->length; i++){
        if(arr->A[i]<sum)
        hash1[arr->A[i]] = 1;
    }
    for(int j=0; j<arr->length; j++){
        if(hash1[sum - arr->A[j]]!=0 && arr->A[j]<sum){
            cout<<arr->A[j]<< " + " << sum-arr->A[j]<< " = "<< sum<<endl;
        }
        hash1[arr->A[j]]++;
    }
}

//without hashing sorted array
void kpairsorted(struct Array *arr, int sum){
    int i=0, j = arr->length-1;
    while(i<j){
       if(arr->A[i] + arr->A[j] == sum){
           cout<<arr->A[i]<< " + "<< arr->A[j]<< " = "<< sum<<endl;
           i++;
           j--;
       }
       else if(arr->A[i] + arr->A[j]< sum){
           i++;
       }
       else
       j--;
    }
}

//finding max and min in one search
void minmax(struct Array *arr){
    int i=0;
    int max = arr->A[0];
    int min = arr->A[0];
    for(i=0; i<arr->length-1; i++){
        if(min<arr->A[i]){
            min = arr->A[i];
        }
        if(max>arr->A[i]){
            max = arr->A[i];
        }
    }
    cout<<"Max is: "<<max<<" Min is: "<<min<<endl;
}

int main(){
    struct Array arr;
    struct Array *miss;
    struct Array *hash;
    cout<<endl<<"enter the size of array"<<endl;
    cin>>arr.size;
    arr.A = (int* )malloc(arr.size*sizeof(int));
    cout<<"Enter the number of element you want to enter"<<endl;
    cin>>arr.length;
    for(int i=0; i<arr.length; i++){
        cin>>arr.A[i];
    }
    minmax(&arr);
    // kpairsorted(&arr, 10);
    // hashpair(&arr, 10, 16) ; 
    // kpair(&arr, 10);
    // duplicateunsorted(&arr);
    // duplicatehash(&arr, 8);
    // duplicate(&arr);
    // hash = misshash(&arr, 19);
    // display(*hash);
    
    // miselemany(&arr);
    // display(*miss)
    // cout<<endl<<"missing number is :"<< miselesingle1(&arr)<<endl ;
    
}
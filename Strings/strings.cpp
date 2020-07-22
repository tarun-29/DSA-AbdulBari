#include<iostream>
using namespace std;

// int main(){

//     //calculating the length of string
//     char *n = "welcome";
//     int i;
//     for(i=0; n[i]!='\0'; i++){

//     }
//     cout<<endl<<"Length of string is : "<<i<<endl;
// }

// int main(){
//     //convert uppercase letter of string in lower case
//     char string[] = "welcome";

//     for(int i=0; i<string[i]!='\0'; i++){
//         string[i] = string[i] - 32;
//         cout<<string[i]<<endl;
//     }
//     cout<<endl<<string<<endl;
// }

// int main(){
//     //counting words and vowel in string
//     int j = 1;
//     char A[] = "How are    you";
    
//     int count = 0;
//     for(int i=0; A[i]!='\0'; i++){
//             if(A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u'){
//                 cout<<"OK"<<endl;
//                 count++;
//             }
//             if(A[i] == ' ' && A[i-1]!= ' '){
//                 j++;
//             }
//     }
//     cout<<"No of Vowels are: "<<count<<endl;
//     cout<<"No of words are: "<<j<<endl;
// }

//string validation no special character
int valid(char * name){
    for(int i=0; name[i]!='\0'; i++){
        if(!(name[i]>=65 && name[i]<=90) && !(name[i]>=97 && name[i]<=122) && !(name[i]>=48 && name[i]<=57)){
            return 0;
        }   
    }
       return 1;
}
//reverse give string
void reverseString(char * name){
    char R[80];
    int i;
    for(i=0; name[i]!='\0'; i++){

    }
    i = i-1;
    int j;
    for(j=0; i>=0 ; i--, j++){
        R[j] = name[i];
    }
    R[j] = '\0';
    for(int k=0; k<R[k]!='\0'; k++){
        cout<<R[k];
    }
}

//checking palindrom
int checkingPalindrom(char * name){
    int flag = 0;
    char R[80];
    int i;
    for(i=0; name[i]!='\0'; i++){

    }
    i = i-1;
    int j;
    for(int k=0; i>=0, name[i]!='\0'; k++, i-- ){
        if(name[i] != name[k]){
            return 1;
        }
    }
}

//find the number of duplicates in given string using hashtable
void dupli(char *name){
    int hash[27];
    int j;
    for(int i=0; i<27; i++){
        hash[i] = 0;
    }

    for(j=0; name[j]!='\0'; j++){
        hash[name[j] - 65]+=1;
    }
    for(int k=0; k<27; k++){
        if(hash[k] >1){
            cout<<"The Duplicate character is : "<<(char)(k+65)<<endl;
            cout<<"Count is : "<<hash[k]<<endl;
        }
    }
}


//finding duplicate using the bitwise operator can't count the number of duplicate
void duplibitwise(char *name){
    long int h;
    long int x;
    for(int i=0; name[i]!='\0'; i++){
        x = 1;
        x = x << (name[i] - 65);
        if((x & h)>0){
            cout<<"Duplicate character are : "<<name[i]<<endl;
        }
        else
        {
            h = h|x;
        }
    }
}

//checking the string is anagram or not
void anagram(char *A, char *B){
    int hash[26] = {0};
    for(int i=0; A[i]!='\0'; i++){
        hash[A[i]-97] = hash[A[i]-97] + 1;
    }
    cout<<endl;
    for(int i=0; B[i]!='\0'; i++){
        // cout<<"Before"<<hash[A[i]-97];
        hash[B[i]-97] = hash[B[i]-97] - 1;
        // cout<<"After"<<hash[A[i]-97]<<endl;
    }
    cout<<endl;
    for(int i=0; A[i]!='\0'; i++){
        if(hash[A[i]-97]!=0){
            cout<<"Hello";
            cout<<"Given string is not an anagram"<<endl;
            break;
        }
        if(A[i]=='\0'){
            cout<<"Given string is anagram"<<endl;
            break;
        }
    }
}

//permutation of string using bruteforce recursion tree
void perm(char * name, int k){
    static int flag[10] = {0};
    static char ans[10];
    if(name[k]=='\0'){
        ans[k] = '\0';
        cout<<ans<<endl;
    }
    else
    {
        for(int i=0; name[i]!='\0'; i++){
            if(flag[i]==0){
                ans[k] = name[i];
                flag[i] = 1;
                perm(name, k+1);
                flag[i]=0;
            }
        }
    }
}

void swap(char *a, char *b){
    // cout<<"from swap function"<<endl; .
    char temp = *a;
    *a = *b;
    *b = temp;
}

void perm1(char * name, int l, int h){
    if(l==h){
        cout<<name<<endl;
    }
    else{
        for(int i=l; i<=h; i++){
            swap(name[l], name[i]);
            perm1(name, l+1, h);
            swap(name[l], name[i]);
        }
    }
}

int main(){ 
    //you can't mutate the string literal so you have to use char array to use perm1 function
    //otherwise go to perm function to get permutation of string
    char C[] = "ABC";
    char *A = "ABC";
    char *B = "verbose";
    // perm1(C, 0, 2);
    // anagram(A, B);
    // int a = checkingPalindrom(A);
    // if(a){
    //     cout<<endl<<"The given string is not an Palindrom"<<endl;
    // }
    // else
    // {
    //     cout<<endl<<"Yes, given string is an palindrom"<<endl;
    // }
    
    // int a = valid(A);
    // if(a){
    //     cout<<"Valid String"<<endl;
    // }
    // else
    // {
    //     cout<<"Invalid String"<<endl;
    // }
    
    // int b = valid(B);
    // if(b){
    //     cout<<"String Valid"<<endl;
    // }
    // else
    // {
    //     cout<<"String is not valid"<<endl;
    // }
}
#include<iostream>

using namespace std;

// void fun(int x){
//     if(x>0)
//     {
//         cout<<x<<endl;
//         fun(x-1);
//     }
// }

// int main(){
//     int a= 5;
//     fun(a);
// }

//tree recursion

// void fun(int x){
//     if(x>0){
//         cout<<x<<endl;
//         fun(x-1);
//         fun(x-1);
//     }
// }

// int main(){
//     int a = 3;
//     fun(a);
// }

//indirect recursion

//  int fun(int n)
//  {
//  if(n>100)
//  return n-10;
//  return fun(fun(n+11));
//  }
//  int main()
//  {
//  int r;
//  r=fun(95);
//  printf("%d\n",r);
//  return 0;
//  }

    //sum of n natural number using recursion

// int sum(int x){
//     if(x>0){
//         cout<<x<<endl;
//         return sum(x-1) + x;
//     }
//     return 0;
// }

// int main(){
//     int a = 10;
//     int tsum = 0;
//     tsum = tsum + sum(a);
//     cout<<tsum<<endl;
// }

//factorial using recursion

// int fact(int x){
//     if(x==0){
//         return 1;
//     }
//     else
//     {
//         return x*fact(x-1);
//     }
    
// }

// int main(){
//     int a = ;
//     int ans = fact(a);
//     cout<<ans<<endl;
// }

//power function using recursion

// int pow(int m, int n){
//     if(n == 0){
//         return 1;
//     }
//     else
//     {
//         return pow( m, n-1)*m;
//     }
// }

// int powerreduction(int m, int n){

//     if(n==0){
//         return 1;
//     }
//     if(n%2!=0){
//         return m*powerreduction(m*m, (n-1)/2);
//     }
//     if(n%2==0){
//         return (powerreduction(m*m,n/2));
//     }
// }

// int main(){
//     int tans;
//     int a = 2;
//     int b = 6;
//     tans = powerreduction(2,6);
//     cout<<tans<<endl;
// }

//taylor formula recursion

// double tailor(int n, int x){
//     static double p = 1, f = 1;
//     double r;
//     if(n==0){
//         return 1;
//     }
//     else
//     {
//         r = tailor(n-1,x);
//         p = p*x;
//         f = f*n;
//         return r + p/f;
//     }
// }

// int main(){
//     cout<<tailor(15,4);
//     return 0;
// }

//taylor series horner's rules O(n) time

// double hornertailor(int x, int n){
//     static double s;
//     if(n==0){
//         return s;
//     }
//     s = 1+x*s/n;
//     return hornertailor(x, n-1);
// }

// int main(){
//     cout<<hornertailor(4,15);
//     return 0;
// }

// fibonaci series using recursion

// int fib(int n){
//     if(n==1 || n==0){
//         return 1;
//     }
//     return (fib(n-2) + fib(n-1));
// }

// int main(){
//     int a = 5;
//     int j = 0;
//     for(int i=1; i<=a; i++){
//         cout<<fib(j)<<endl;
//         j++;
//     }
//     return 0;
// }

//using tabular form
//     int a[10];
// int fib(int n){

//     if(n==0 || n==1){
//         a[n] = n;
//         return n;
//     }
//     else{
//         if(a[n-2] == -1){
//             a[n-2] = fib(n-2);
//         }
//         if(a[n-1] == -1){
//             a[n-1] = fib(n-1);
//         }
//         return fib(n-2) + fib(n-1);
//     }
// }

// int main(){
//     int n;
//     cout<<endl<<"enter the fib number to find sequence"<<endl;
//     cin>>n;
//     int i=0;
//     for(int i=0; i<n+1; i++){
//         a[i] = -1;
//     }
//     for(int j=0; j<=n; j++){
//         cout<<fib(i)<<endl;
//         i++;
//     }
// }


//combination formula nCr

// int nCr(int n, int r){
//     if(n==r || r == 0){
//         return 1;
//     }
//         return nCr(n-1, r-1) + nCr(n-1, r);
// }

// int main(){
//     int n = 4;
//     int r = 2;
//     int ans = nCr(4,2);
//     cout<<ans<<endl;
//     return 0;
// }

//Tower of hanoi

int toh(int n, int A, int B, int C){
    if(n>0){
        toh(n-1, A, C, B);
        cout<<"from"<<A<<"to"<<C<<endl;
        toh(n-1, B, A, C);
    }
}

int main(){
    toh(4,1,2,3);
}
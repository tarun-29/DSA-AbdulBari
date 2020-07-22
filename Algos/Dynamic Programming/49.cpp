#include<iostream>
#include<vector>

using namespace std;
#define K 16

vector<string> DP[K][K];

void printCombination(int k){
    string str = "";
    for(int len = 0; len<=k; len++){
        DP[len][0].push_back(str);
        str = str + "0";
    }

    for(int len = 1; len<=k; len++){
        for(int n=1; n<=len; n++){

            for(string str: DP[len-1][n])
                DP[len][n].push_back("0"+str);
            
            for(string str: DP[len-1][n-1])
                DP[len][n].push_back("1"+str);
        }
    }

    for(int n=0; n<=k; n++){
        for(string str: DP[k][n])
            cout<<str<<" ";

        cout<<endl;
    }
}

int main(){
    int k;
    cin>>k;

    printCombination(k);
    return 0;
}

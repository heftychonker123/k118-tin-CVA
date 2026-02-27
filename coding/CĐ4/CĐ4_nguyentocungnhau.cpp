#include <bits/stdc++.h>
using namespace std;
#define pb push_back


vector<vector<long long>> spiral_matrix(long long n){
    long long num=1;
    long long top=0 , left=0;
    long long bottom=n-1 , right=n-1;
    vector<vector<long long>> matrix={};
    for (int i=0; i<n; i++){
        vector<long long> temp={};
        for (int i=0; i<n; i++) temp.pb(0);
        matrix.pb(temp);
    }
    while (num<=n*n){
        //left to right;
        for (int i=0; i<right ; i++){
            matrix[top][i]=num;
            num++;
        }
        top+=1;
        //top to left
    }
}
int main(){
    long long n; cin >> n;
    
}
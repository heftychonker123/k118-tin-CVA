#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("daycondn.inp" , "r" , stdin);
    freopen("daycondn.out" , "w" , stdout);
    int n; cin >> n;
    vector<long> v={};
    for(int i=0 ; i<n ; i++){
        long t; cin >> t;
        v.push_back(t);
    }
    int max=0;
    int temp=0;
    vector<long> subarr={};
    vector<long> temp_subarr={};
    for (const long i : v){
        if (i>0){
            temp+=1;
            temp_subarr.push_back(i);
        }
        else{
            if (temp>max) {
                max=temp;
                subarr=temp_subarr;
                temp_subarr={};
            }
            temp=0;
        }
    }
    if (temp>0){
        if (temp>max) {
            max=temp;
            subarr=temp_subarr;
        }
    }
    cout << max << endl;
    for (long i : subarr){
        cout << i << " ";
    }
}
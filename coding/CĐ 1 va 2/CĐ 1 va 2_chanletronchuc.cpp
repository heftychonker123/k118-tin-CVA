#include <bits/stdc++.h>
using namespace std;
void check2(long long n){
    if (n%2==0) cout << "TRUE"<< endl;
    else cout << "FALSE" << endl;
}
void check10(long long n){
    if (n%10==0) cout << "TRUE"<< endl;
    else cout << "FALSE" << endl;
}
void checkcp(long long n){
    long long a = sqrt(n);
    if (a*a==n){
        cout << "TRUE"<< endl;
    }
    else{
        cout << "FALSE"<<endl;
    }
}
int main(){
    long long N;cin>> N;
    check2(N);
    check10(N);
    checkcp(N);
    return 0;
}
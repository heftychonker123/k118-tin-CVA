#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
void solve(str n){
    int length = n.size();
    int r = length%3;
    if (r!=0){
        int pad = 3 - r;
        for (int i=0 ; i<pad ; i++){
            n="0"+n;
        }
        length+=pad;
    }
    str ans="";
    for (int i=0 ; i<length ; i+=3){
        ll coef = (n[i]-'0')*4 + (n[i+1]-'0')*2 + (n[i+2] - '0');
        ans+=to_string(coef);
    }
    cout << ans;
    return;

}


int main(){
    freopen("NPBP.INP" , "r" , stdin);
    freopen("NPBP.OUT" , "w" , stdout);
    str n; getline(cin , n);
    solve(n);
    return 0;
}
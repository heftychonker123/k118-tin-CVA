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
    ll length = n.size();
    for (int i=length-1 ; i>0 ; i--){
        if  (length%i == 0){
            str s= n.substr(0 , i);
            str temp="";
            for (int j=0 ; j< (length/i) ; j++) temp+=s;
            if (temp == n) {
                cout << s;
                return;
            }
        }
    }
    cout << "0";
    return;
}



int main(){
    freopen("xaughep.inp" , "r" , stdin);
    freopen("xaughep.out" , "w" , stdout);
    str n ; getline(cin , n);
    solve(n);
    return 0;
}
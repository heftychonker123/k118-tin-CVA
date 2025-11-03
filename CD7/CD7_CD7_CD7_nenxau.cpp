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
void solve_compress(str n){
    ll length = n.size();
    ll sl=1;
    char temp=n[0];
    for (int i=1 ; i<length ; i++){
        char l = tolower(n[i]);
        if (l == temp){
            sl++;
        }
        else{
            if (sl> 2) cout << sl << temp;
            else{
                for (int j=0 ; j<sl; j++){
                    cout << temp;
                }
            }
            sl=1;
            temp = l;
        }
    }
    if (sl > 2) cout << sl<< temp;
    else{
        for (int j=0 ; j<sl; j++){
            cout << temp;
        }
    }
    return;
}

int main(){
    freopen("nenxau.inp" , "r" , stdin);
    freopen("nenxau.out" , "w" , stdout);
    str n ; getline(cin , n);
    solve_compress(n);
    return 0;
}
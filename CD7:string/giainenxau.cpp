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

void solve_decompress(str n){
    ll length = n.size();
    str temp="";
    for (int i=0 ; i<length ; i++){
        if (isdigit(n[i])){
            temp+=n[i];
        }
        else{
            char c = tolower(n[i]);
            if (not temp.empty()){
                ll com_coef=stoi(temp);
                for (int j=0 ; j< com_coef ; j++){
                    cout<< c;
                }
                temp="";
            }
            else cout << c;
        }
    }
}
int main(){
    freopen("giainenxau.inp" , "r" , stdin);
    freopen("giainenxau.out" , "w" , stdout);
    str n ; getline(cin , n);
    solve_decompress(n);
    return 0;
}
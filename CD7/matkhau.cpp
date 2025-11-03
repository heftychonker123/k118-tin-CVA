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
#define umap unordered_map

void solve(str n){
    ll length = n.size();
    ll ans=0;
    for (int i=0 ; i<length-5 ; i++){
        ll temp_l=0;
        ll upper=0;
        ll lower=0;
        ll num=0;
        for (int j=i ; j<length ; j++){
            temp_l++;
            if (isupper(n[j])) upper++;
            else if (islower(n[j])) lower++;
            else num++;
            if (temp_l>5 && upper>0 && lower>0 && num>0){
                ans+=length-j;
                break;
            }
        }
    }
    cout << ans;
}
int main(){
    freopen("matkhau.inp" , "r" , stdin);
    freopen("matkhau.out" , "w" , stdout);
    str s; getline(cin , s);
    solve(s);
    return 0;
}
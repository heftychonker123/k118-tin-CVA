#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
void solve(str n){
    reverse(n.begin() , n.end());
    ll temp=0;
    ll ans=0;
    for (const char &i : n){
        ll coef;
        if (isdigit(i)) coef=i-'0';
        else coef=i-'A'+10;
        ans+=coef * pow(16,temp);
        temp++;
    }
    cout << ans;
}
int main(){
    freopen("TLPTP.inp" , "r" , stdin);
    freopen("TLPTP.out" , "w" , stdout);
    ios::sync_with_stdio(false); // Tăng tốc độ nhập xuất
    cin.tie(nullptr);
    str n; getline(cin , n);
    solve(n);
    return 0;
}
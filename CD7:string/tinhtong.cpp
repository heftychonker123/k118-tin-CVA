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
    str temp="0";
    ll ans=0;
    for (const char &i : n){
        if (isdigit(i)) temp+=i;
        else{
            ll t = stoi(temp);
            ans+=t;
            temp="0";
        }
    }
    ans+=stoi(temp);
    cout << ans;
}
int main(){
    ios::sync_with_stdio(false); // Tăng tốc độ nhập xuất
    cin.tie(nullptr);
    freopen("TINHTONG.INP" , "r" , stdin);
    freopen("TINHTONG.OUT" , "w" , stdout);
    str n ; getline(cin , n);
    solve(n);
    return 0;
}
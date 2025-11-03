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
string dectobin(ll n){
    string ans = "";
    while (n > 0){
        ans = to_string(n % 2)+ans;
        n /= 2;
    }
    // padding
    while (ans.size()%4 !=0) ans = '0' + ans;
    return ans;
}

void solve(string n){
    string ans = "";
    for (int i = 0; i < n.size(); i++){
        ll dec_coef;
        if (isdigit(n[i])) dec_coef = n[i] - '0';
        else dec_coef = n[i] - 'A' + 10;
        string bin_coef = dectobin(dec_coef);
        ans += bin_coef;
    }
    while (ans.size() > 1 && ans[0] == '0') ans.erase(0, 1);
    cout << ans;
}


int main(){
    freopen("msnp.inp" , "r" , stdin);
    freopen("msnp.out" , "w" , stdout);
    str n; cin >> n;
    solve (n);
    return 0;
}
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
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve(string n) {
    reverse(n.begin(), n.end());
    str ans="";
    // Pad with zeros to make length a multiple of 3
    int pad = (3 - n.size() % 3) % 3;
    n.append(pad, '0');

    // Process in chunks of 3
    for (size_t i = 0; i < n.size(); i += 3) {
        ll temp = (n[i]-'0') + (n[i+1]-'0')*2 + (n[i+2]-'0')*4;
        ans+= to_string(temp);
    }
    cout << ans;
}

int main(){
    freopen("npbp.inp" , "r" , stdin);
    freopen("npbp.out" , "w" , stdout);
    ios::sync_with_stdio(false); // Tăng tốc độ nhập xuất
    cin.tie(nullptr);
    str n ; getline(cin , n);
    solve(n);
    return 0;
}
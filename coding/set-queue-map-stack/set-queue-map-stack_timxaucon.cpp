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

ll helper_function(str n, ll substring_length){
    ll length = n.size();
    vector<string> shit;
    for (int i = 0; i <= length - substring_length; i++){
        str temp = "";
        for (int t = 0; t < substring_length; t++){
            temp += n[i+t];
        }
        shit.push_back(temp);
    }
    set<string> s(shit.begin() , shit.end());
    return s.size();
}

void solve(str n){
    ll res = 0;
    for (int i = 1; i <= n.size(); i++){
        res += helper_function(n, i);
    }
    cout << res;
    cout << "\n";
    return;
}

int main(){
    //freopen("xaucon.inp", "r", stdin);
    //freopen("xaucon.out", "w", stdout);
    str n; 
    cin >> n;
    solve(n);
}

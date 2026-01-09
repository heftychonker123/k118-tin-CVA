#include <bits/stdc++.h>
using namespace std;
#define filename "Bai4"
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    str n ; getline(cin,n);
    set<ll> s;
    str temp = "";
    for (const char &i : n){
        if (isdigit(i)){
            temp+=i;
        }
        else{
            if (!temp.empty()) s.insert(stoll(temp));
            temp = "";
        }
    }
    if (!temp.empty()) s.insert(stoll(temp));
    cout << s.size() << "\n";
    for (const ll &i : s) cout << i << "\n"; 
}
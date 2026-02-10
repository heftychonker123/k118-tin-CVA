#include <bits/stdc++.h>
using namespace std;
#define filename "xaunhiphan"
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
void solve(str start , str end){
    while (true){
        cout << start << "\n";
        if (start == end) break;
        for (auto i = start.rbegin() ; i!=start.rend() ; i++){
            if (*i=='Y'){
                *i = 'X';
                break;
            }
            else if (*i == 'X') *i = 'Y';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n ; cin >> n;
    str start = "" , end = "";
    for (int i=0 ; i<n ; i++){
        start += "Y";
        end += "X";
    }
    solve(start,end);
    return 0;
}
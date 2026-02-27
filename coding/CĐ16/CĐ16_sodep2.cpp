#include <bits/stdc++.h>
using namespace std;
#define filename "sodep2"
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
vect<char> choice = {'6' , '8'};
//Solve with bfs
void solve(ll n){
    vect<str> visited;
    queue<str> q;
    q.push("6");
    q.push("8");
    while (!q.empty()){
        str t = q.front(); q.pop();
        visited.pb(t);
        if (t.size()!=n){
            for (const char &i : choice){
                q.push(t+i);
            }
        }
    }
    reverse(visited.begin() , visited.end());
    for (const str &i : visited){
        cout << i << " ";
    }
    cout << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll q ; cin >> q;
    while (q--){
        ll t ; cin >> t;
        solve(t);
    }
    return 0;
}
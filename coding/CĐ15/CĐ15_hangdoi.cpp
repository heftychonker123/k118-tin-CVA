#include <bits/stdc++.h>
using namespace std;
#define filename "hangdoi"
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

void solve(){
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    ll queries ; cin >> queries;
    queue<ll> q;
    while (queries--){
        ll type ; cin >> type;
        switch(type){
            case 1:
                cout << q.size();
                cout << "\n";
                break;
            case 2:
                if (q.empty()) cout << "YES";
                else cout << "NO";
                cout << "\n";
                break;
            case 3:
                ll t ; cin >> t;
                q.push(t);
                break;
            case 4:
                if (!q.empty()){
                    q.pop();
                }
                break;
            case 5:
                if (q.empty()) cout << -1;
                else cout << q.front();
                cout << "\n";
                break;
            case 6:
                if (q.empty()) cout << -1;
                else cout << q.back();
                cout << "\n";
                break;
        }
    }
    return 0;
}
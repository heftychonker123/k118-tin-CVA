#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vect vector
#define filename "luckynum"
void solve(ll maxLength , ll modulo){
    queue<pair<str,ll>> q;
    q.push({"6" , 6 % modulo});
    q.push({"8" , 8 % modulo});
    vect<str> choice;

    while (!q.empty()){
        auto curr = q.front(); q.pop();

        if (curr.second == 0){
            cout << curr.first << "\n";
            return;
        }

        if (curr.first.back() == '8'){
            choice = {"6" , "8"};
        } else {
            choice = {"6"};
        }

        for (const str &i : choice){
            ll t = stoll(i);
            str nxt = curr.first + i;
            if (nxt.size() <= maxLength){
                q.push({nxt , (curr.second * 10 + t) % modulo});
            }
        }
    }
    cout << "-1\n";
    return;
}

int main(){
    freopen(filename".inp" , "r" , stdin); freopen(filename".out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n; cin >> n;
    solve(200, n);
}

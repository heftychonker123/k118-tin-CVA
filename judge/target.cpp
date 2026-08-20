#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector
struct update{
    ll d , id , c;
};

int main(){
    ll n,g; ; cin >> n >> g;
    vect<update> v(n);
    for (int i = 0 ; i<n ; i++) cin >> v[i].d >> v[i].id >> v[i].c;
    sort(v.begin() , v.end() , [&](auto a , auto b){return a.d < b.d;});
    unordered_map<ll,ll> cows;
    for (int i = 0 ; i<n ; i++) cows[v[i].id] = g;
    set<ll> res;
    map<ll,ll> prod;
    prod[g] = cows.size();
    ll curr = 0 , cnt = 0;
    for (int i = 0 ; i<n ; i++){
        ll curr = v[i].id;
        ll date = v[i].d;
        if (--prod[cows[curr]] == 0) prod.erase(cows[curr]);
        cows[curr] += v[i].c;
        prod[cows[curr]]++;
        auto bestCow = *(prod.end()--);

        if ((bestCow).first != curr || (bestCow).second != cnt){
            res.insert(date);
        }
        curr = (bestCow).first ; cnt = (bestCow).second;
    }
    cout << res.size();
}
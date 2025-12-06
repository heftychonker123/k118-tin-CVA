#include <bits/stdc++.h>
using namespace std;
#define filename "marathon"
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
    int n ; cin >> n;
    vect<pair<ll,ll>> v;
    while (n--){
        ll a,b ; cin >> a >> b;
        v.pb({a,b});
    }
    sort(v.begin() , v.end() , [&](auto a, auto b){
        if((a.first+a.second)==(b.first+b.second)){
            if (a.first==b.first) return a.second<b.second;
            else return a.first<b.first;
        }
        return (a.first+a.second)<(b.first+b.second);
    });
    ll currtime=0;
    for (auto i:v){
        if (currtime>i.first){
            currtime+=i.second;
        }
        else currtime = i.first + i.second;
    }
    cout << currtime;
    return 0;
}
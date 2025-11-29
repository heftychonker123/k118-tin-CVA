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

void solve(vect<ll> v , ll length){
    umap<ll , int> cnt;
    for (const ll &i : v){
        cnt[i%5]++;
    }
    int x1,x2,x3,x4,x5,x6,x7;
    x1 = cnt[0];
    x2 = min(cnt[1], cnt[4]);
    x3 = min(cnt[2], cnt[3]);
	x4 = max(0, cnt[1] - x2)/5;
	x5 = max(0, cnt[4] - x2)/5;
	x6 = max(0, cnt[2] - x3)/5;
	x7 = max(0, cnt[3]-x3)/5;
    cout << x1+x2+x3+x4+x5+x6+x7 << "\n";
    return;
}

int main(){
    int q ; cin >> q;
    while(q--){
        int n; cin >> n;
        vect<ll> v(n);
        for(int i=0 ; i<n ; i++) cin >> v[i];
        solve(v,n);
    }
}
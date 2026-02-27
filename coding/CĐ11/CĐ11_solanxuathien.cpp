#include <bits/stdc++.h>
using namespace std;
#define filename "solanxuathien"
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
    umap<ll,ll> freq;
    ll n ; cin >> n;
    for (int i=0 ; i<n ; i++){
        ll t ; cin >> t;
        cout << freq[t]+1 << " ";
        freq[t]++;
    }
    return 0;
}
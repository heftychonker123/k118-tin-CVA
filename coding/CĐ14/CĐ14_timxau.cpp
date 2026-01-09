#include <bits/stdc++.h>
using namespace std;
#define filename "timxau"
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
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll n ; cin >> n;
    vect<str> v(n);
    for (int i=0 ; i<n ; i++) cin >> v[i];
    sort(v.begin() , v.end());
    ll seq=1;
    for (int i=0 ; i<n-1 ; i++){
        if (v[i]==v[i+1]){
            seq++;
        }
        else{
            if (seq%2==1){
                cout << v[i] << "\n";
                return 0;
            }
            seq = 1;
        }
    }
    if (seq % 2 == 1) {
        cout << v[n - 1] << "\n";
        return 0;
    }
    cout << "0\n";
    return 0;
}
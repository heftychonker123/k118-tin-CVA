#include <bits/stdc++.h>
using namespace std;
#define filename "sogannhat"
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

str find_closest_permutation(string n , ll i){
    ll first_large = 0;
    for (int j=i+1 ; j<n.size() ; j++){
        if (n[j]>n[i]){
            first_large=j;
        }
    }
    str res=""; res+=n[first_large];
    vect<char> v;
    for (int j=i ; j<n.size() ; j++){
        if (j!=first_large) v.pb(n[j]);
    }
    sort(v.begin() , v.end());
    for (const char &i:v){
        res+=i;
    }
    return res;
}


int main(){
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    str n ; cin >> n;
    ll pos = 0;
    for (int i = n.size() - 2; i >= 0; i--) {
        if (n[i] < n[i + 1]) {
            pos = i;
            break;
        }
    }

    if (pos==0) {
        cout << "0\n";
        return 0;
    }
    str res = find_closest_permutation(n,pos);
    str front = n.substr(0,pos);
    cout << front+res << "\n";
    return 0;
}
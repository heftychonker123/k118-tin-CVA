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

vect<int> xoa_lap(vector<int> v){
    umap<int , int> set;
    vect<int> ans;
    for (auto i=ans.rbegin() ; i!=ans.rend() ; i++){
        set[*i]++;
    }
    for (auto &i:set){
        ans.pb(i.first);
    }
    return ans;
}
vect<int> nhap(){
    int n; cin >> n;
    vect<int> ans(n);
    for (int i=0 ; i<n ; i++){
        cin >> ans[i];
    }
    return ans;
}
void in(vect<int> ans){
    for (const int &i : ans){
        cout << i << " ";
    }
    return;
}

int main(){
    vector<int> v = nhap();
    vect<int> ans=xoa_lap(v);
    in(ans);
    return 0;
}
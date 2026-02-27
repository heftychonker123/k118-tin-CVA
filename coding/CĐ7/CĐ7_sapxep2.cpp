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
bool compare_length(str a , str b){
    return a.size()>b.size();
}
void solve(str n){
    sstream ss(n);
    vect<str> words;
    str t;
    while (ss>>t){
        words.pb(t);
    }
    
}
int main(){
    //freopen("kstring.inp" , "r" , stdin);
    //freopen("kstring.out" , "w" , stdout);
    return 0;
}
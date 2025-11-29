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

bool check(ll n){
    if (n<2) return false;
    if (n==2) return true;
    for (int i=2 ; i*i<=n ; i++){
        if (n%i == 0) return false;
    }
    return true;
}

int main(){
    
}
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
vect<ll> freq(str a){
    vect<ll> frequency(52,0);
    for (const char &i : a){
        ll t;
        if (islower(i)) t=i-'a';
        else t=i - 'A'+26;
        frequency[t]++;
    }
    return frequency;
}
void solve(str a, str b){
    vect<ll> fa=freq(a);
    vect<ll> fb=freq(b);
    str intersect="";
    str uni="";
    for (int i=0 ; i<52 ; i++){
        char t;
        if (i<26) t=i+'a';
        else t=i+'A'-26;
        if (fa[i]>0 && fb[i]>0){
            intersect+=t;
        }
    }
    for (int i=0 ; i<52 ; i++){
        char t;
        if (i<26) t=i+'a';
        else t=i+'A'-26;
        if (fa[i]>0 || fb[i]>0){
            uni+=t;
        }
    }
    sort(intersect.begin() , intersect.end());
    sort(uni.begin() , uni.end());
    cout << intersect << "\n";
    cout << uni << "\n";
}
int main(){
    str n; cin >> n; 
    str m; cin >> m;
    solve(n,m);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define filename "contest"
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
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    ll c,p,s ; cin >> c >> p >> s;
    vect<str> contestant(c);
    for (int i=0 ; i<c ; i++) cin >> contestant[i];
    umap<str,ll> problem;
    while (p--){
        str problems;cin>>problems;
        ll scores; cin >> scores;
        problem[problems]=scores;
    }
    umap<str,ll> score;
    for (int i=0 ; i<s ; i++){
        str player;
        str prob,result;
        cin >> player >> prob >> result;
        if (result=="AC"){
            score[player]+=problem[prob];
        }
    }
    for (const str &i : contestant){
        cout << i << " " << score[i] << "\n";
    }
    return 0;
}
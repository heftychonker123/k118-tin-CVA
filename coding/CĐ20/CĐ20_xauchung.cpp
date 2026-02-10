#include <bits/stdc++.h>
using namespace std;
#define filename "number"
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

void IO(){
    if (fopen(filename".inp" , "r"))
    {
    freopen(filename".inp" , "r" , stdin);
    freopen(filename".out" , "w" , stdout);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    IO();
    str s1,s2 ; cin >> s1 >> s2;
    vect<ll> prevdp(s2.size()+1 , 0);
    vect<vect<str>> trace(s1.size() + 1 , vect<str>(s2.size()+1 , ""));
    for (int i=1 ; i<=s1.size() ; i++){
        vect<ll> currdp(s2.size()+1,0);
        for (int j=1 ; j<=s2.size() ; j++){
            ll include = LLONG_MIN , exclude = LLONG_MIN;
            if (s1[i-1] == s2[j-1]) include = prevdp[j-1]+1;
            exclude = max(currdp[j-1] , prevdp[j]);
            if (include > exclude){
                currdp[j] = include;
                trace[i][j] = trace[i-1][j-1] + s1[i-1];
            }
            else if (currdp[j-1] > prevdp[j]){
                currdp[j] = currdp[j-1];
                trace[i][j] = trace[i][j-1];
            }
            else if (prevdp[j] > currdp[j-1]){
                currdp[j] = prevdp[j];
                trace[i][j]  = trace[i-1][j];
            }
            else{
                currdp[j] = prevdp[j];
                trace[i][j] = max(trace[i-1][j] , trace[i][j-1]);
            }
        }
        prevdp = currdp;
    }
    cout << trace[s1.size()][s2.size()] << "\n";
    return 0;
}
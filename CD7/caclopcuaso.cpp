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
void solve(str n){
    str ans="";
    ll temp=0;
    for (auto i=n.rbegin() ; i!=n.rend() ; i++){
        ans+=*i;
        temp++;
        if (temp==3){
            ans+=".";
            temp=0;
        }
    }
    reverse(ans.begin() , ans.end());
    cout << ans;
}
int main(){
    freopen("lopcuaso.inp" , "r" , stdin);
    freopen("lopcuaso.out" , "w" , stdout);
    str n ; cin>>n;
    solve(n);
    return 0;
}
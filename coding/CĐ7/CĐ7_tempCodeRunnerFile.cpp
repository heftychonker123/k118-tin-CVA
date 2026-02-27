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

void solve(str n){
    ll length=n.size();
    str ans="";
    char t=n[0];
    str temp = ""+t;
    for (int i=1; i<length ; i++){
        if(n[i-1]!=n[i]){
            temp+=n[i];
        }
        else{
            if (temp.size()>ans.size()){
                ans=temp;
            }
            else if (temp.size()==ans.size()){
                if (temp>ans) ans=temp;
            }
            temp=""+n[i];
        }
    }
    if (temp.size()>0){
        if (temp.size()>ans.size()){
                ans=temp;
            }
        else if (temp.size()==ans.size()){
            if (temp>ans) ans=temp;
        }
    }
    cout << ans << endl;
}
int main(){
    //freopen("kstring.inp" , "r" , stdin);
    //freopen("kstring.out" , "w" , stdout);
    str n ; cin >> n ; solve(n);
    return 0;
}
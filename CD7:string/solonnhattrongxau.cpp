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
vector<str> sep_num(str n){
    str temp="";
    vector<str> ans={};
    for (const char &i : n){
        if (isdigit(i)) temp+=i;
        else{
            if (temp.empty()) continue;
            else{
                while (temp.size() > 1 && temp[0] == '0') temp.erase(0, 1);
                ans.pb(temp);
                temp="";
            }
        }
    }
    if (not temp.empty()){
        ans.pb(temp);
        temp="";
    }
    return ans;
}
char compare_num(str a , str b){
    char state='=';
    if (a.length()>b.length()) state='>';
    else if (a.length() < b.length()) state='<';
    else{
        ll c=a.compare(b);
        if (c>0) state='>';
        if (c<0) state='<';
    }
    return state;
}
void solve(str n){
    vector<str> num = sep_num(n);
    str max="0";
    for (const str &i : num){
        char state=compare_num(i,max);
        if (state=='>' || state=='=') max=i;
    }
    cout << max;
}
int main(){
    str n; cin >> n; solve(n);
    return 0;
}
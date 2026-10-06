#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXL = 2e5 + 1;
string s , t;

// kmp[i] = k lớn nhất thỏa mãn t[1..k] == t[i - k + 1...i]
int kmp[MAXL + 1];
void preCalc(){
    t = "&" + t;
    int k = 0;
    kmp[1] = 0;
    for (int i = 2 ; i<t.size() ; i++){
        while (k > 0 && t[k+1] != t[i]) k = kmp[k];
        kmp[i] = (t[k+1] == t[i]? ++k : 0);
    }
}

// match[i] = k max sao cho S[i-k+1...i] = T[1...k]
int match[MAXL + 1];
void solve(){
    preCalc();
    s = "$" + s;
    int k = 0;
    
    for (int i = 1 ; i<s.size() ; i++){
        while (k > 0 && s[i] != t[k+1]) k = kmp[k];
        match[i] = (s[i] == t[k+1]? ++k : 0);
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t >> s;
    solve();
    vector<int> matchingPos;
    for (int i = 1 ; i<s.size() ; i++) if (match[i] == t.size() - 1) matchingPos.push_back(i - t.size() + 2);
    cout << matchingPos.size() << '\n'; for (int &i : matchingPos) cout << i << ' ';
}
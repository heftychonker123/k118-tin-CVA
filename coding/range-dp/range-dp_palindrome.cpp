#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define str string
const ll MAXN = 1e3;
bool dp[MAXN][MAXN];

ll findPalindrome(str s){
    ll n = s.size();
    ll res = 0;
    for (int i = n-1 ; i>=0 ; i--){
        dp[i][i] = true; res++;
        if (i < n-1 && s[i] == s[i+1]){
            dp[i][i+1] = true;
            res++;
        }
        for (int j = i+2 ; j<n ; j++){
            if (s[j] == s[i]){
                if (dp[i+1][j-1]){
                    dp[i][j] = true;
                    res++;
                }
            }
        }
    }
    return res;
}

int main(){
    str s ; cin >> s;
    cout << findPalindrome(s);
}

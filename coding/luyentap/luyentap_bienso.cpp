#include <bits/stdc++.h>
using namespace std;
#define filename "bienso"
#define ll       long long
#define str      string
str s; 
ll k;

str convert(ll n){
    ll p[10] = {10 , 10 , 26 , 10 , 10 , 10 , 10 , 10 , 10 , 10};
    str res = "";
    for (int i=9 ; i>=0 ; i--){
        ll coef = n%p[i];
        if (i==2) res += 'A' + coef;
        else res += '0'+coef;
        n/=p[i];
    }
    reverse(res.begin() , res.end());
    return res;
}

str solve(){
    str kToSign = convert(k);
    ll carry = 0;
    str res = "";
    for (int i=9 ; i>=0 ; i--){
        ll currSum = carry;
        carry = 0;
        if (i==2){
            currSum += kToSign[i] - 'A';
            currSum += s[i] - 'A';
            res += 'A' + (currSum%26);
            if (currSum >= 26) carry ++;
        }
        else{
            currSum += kToSign[i] - '0';
            currSum += s[i] - '0';
            res += '0' + (currSum % 10);
            if (currSum >= 10) carry++;
        }
    }
    reverse(res.begin() , res.end());
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    getline(cin , s);
    cin >> k;
    cout << solve();
    return 0;
}
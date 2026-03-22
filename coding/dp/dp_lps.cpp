#include <bits/stdc++.h>
using namespace std;
#define filename "xauchung"
#define ll long long
#define str string
#define vect vector

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
    str s1,s2 ; cin >> s1;
    for (int i=s1.size()-1 ; i>=0 ; i--) s2 += s1[i];
    vect<ll> prevdp(s2.size()+1 , 0);
    vect<vect<str>> trace(s1.size() + 1 , vect<str>(s2.size()+1 , ""));
    // Ta xét lần lượt các ký tự của s1 và s2
    for (int i=1 ; i<=s1.size() ; i++){
        vect<ll> currdp(s2.size()+1,0);
        for (int j=1 ; j<=s2.size() ; j++){
            ll include = LLONG_MIN , exclude = LLONG_MIN;
            // Nếu phần tử này tồn tại ở cả xâu s1 và s2 thì
            // ta sẽ cho vào subsequence chung của s1 và s2 trước phần tử này
            if (s1[i-1] == s2[j-1]) include = prevdp[j-1]+1;
            // Nếu không thì ta có 2 lựa chọn: lấy subsequence hiện thời
            // của s1 hoặc lấy của s2
            exclude = max(currdp[j-1] , prevdp[j]);
            if (include > exclude){
                currdp[j] = include;
                trace[i][j] = trace[i-1][j-1] + s1[i-1];
            }
            else if (currdp[j-1] > prevdp[j]){
                currdp[j] = currdp[j-1];
                trace[i][j] = trace[i][j-1];
            }
            else{
                currdp[j] = prevdp[j];
                trace[i][j]  = trace[i-1][j];
            }
        }
        prevdp = currdp;
    }
    cout << trace[s1.size()][s2.size()];
    return 0;
}

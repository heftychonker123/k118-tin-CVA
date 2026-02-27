#include <bits/stdc++.h>
using namespace std;
#define filename "chusocuoicung1"
#define ll long long
#define str string

void solve(const str &n){
    int lastDigit = n.back() - '0';
    if (lastDigit % 2 == 1) {
        cout << 9;
    } else {
        cout << 1;
    }
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    str n;
    getline(cin, n);
    solve(n);
    return 0;
}

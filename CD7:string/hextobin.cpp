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


string hexCharToBinary(char hex) {
    switch (toupper(hex)) {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
        default: return "Invalid";
    }
}

void solve(str n) {
    str ans = "";
    for (stri i = n.begin(); i != n.end(); i++) {
        ans += hexCharToBinary(*i);
    }
    ll i = 0;
    while (i < ans.size() && ans[i] == '0') i++;
    for (int l = i; l < ans.size(); l++) {
        cout << ans[l];
    }
    cout << endl;
}

int main(){
    freopen("msnp.inp" , "r" , stdin);
    freopen("msnp.out" , "w" , stdout);
    ios::sync_with_stdio(false); // Tăng tốc độ nhập xuất
    cin.tie(nullptr);
    str n; cin >> n;
    solve(n);
    return 0;
}
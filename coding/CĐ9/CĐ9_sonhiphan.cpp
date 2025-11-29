#include <bits/stdc++.h>
using namespace std;
#define filename "sonhiphan"
#define ll long long
#define str string

void solve(const str &n , ll k){
    str temp;
    if (n.size() < k){
        temp = n;
    } else {
        temp = n.substr(n.size() - k, k);
    }

    // Xóa các số 0 thừa ở đầu
    while (temp.size() > 1 && temp.front() == '0') {
        temp.erase(temp.begin());
    }

    cout << temp << "\n";
}

int main(){
    //freopen(filename".inp" , "r" , stdin);
    //freopen(filename".out" , "w" , stdout);
    str n; ll k; cin >> n >> k;
    solve(n, k);
    return 0;
}

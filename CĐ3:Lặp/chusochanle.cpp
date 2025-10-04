#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n; cin >> n;
    string t= to_string(abs(n));
    int l=0, c=0;
    for (const char & i:t){
        int v= i -'0';
        if (v%2==0) c+=1;
        else l+=1;
    }
    cout << c << " " << l;
}
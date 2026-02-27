#include <bits/stdc++.h>
using namespace std;

int main(){
    string n; cin >> n;
    while (n.size()>1){
        int sum=0;
        for (int i=0; i<n.size() ; i++){
            int t= n[i]-'0';
            sum+=t;
        }
        n=to_string(sum);
    }
    cout << n << endl;
}

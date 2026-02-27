#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d; cin >> a >> b >> c >> d;
    vector<int> v ={a,b,c,d};
    sort(v.begin(),v.end());
    cout << v[1]<< endl;
    return 0;
}
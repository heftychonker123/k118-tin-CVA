#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c; cin >> a >> b >> c;
    int delta = b*b - 4*a*c;
    if (a==0){
        if (b==0){
            if (c==0) cout << "VO SO NGHIEM";
            else cout << "VO NGHIEM";
        }
        else cout << setprecision(3) << fixed << -  c/b;
        return 0;
    }
    else{
        if (delta<0){
            cout << "VO NGHIEM";
        }
        else if (delta==0) cout << setprecision(3) << fixed << - 1.000 * b / (2*a) <<endl;
        else cout << setprecision(3) << fixed << -1.000 * (b+sqrt(delta))/ (2*a) <<" " << -1.000 * (b-sqrt(delta))/ (2*a) <<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    long double a,b,c; cin >> a >> b >> c;
    long double delta = b*b - 4*a*c;
    cout << setprecision(2)<< fixed;
    if (a==0){
        if (b==0){
            if (c==0) cout << "VO SO NGHIEM";
            else cout << "VO NGHIEM";
        }
        else if (c==0) cout <<"0.00";
        else cout <<- c/b;
        return 0;
    }
    else{
        if (delta<0){
            cout << "VO NGHIEM";
        }
        else if (delta==0){
            if (b==0) cout << "0.00";
            else cout <<  -b / (2*a) <<endl;
        } 
        else cout << - (b+sqrt(delta))/ (2*a) <<" " << -(b-sqrt(delta))/ (2*a) <<endl;
    }
    return 0;
}
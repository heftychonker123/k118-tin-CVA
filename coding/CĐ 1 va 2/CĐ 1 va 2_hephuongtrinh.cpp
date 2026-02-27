#include <bits/stdc++.h>
using namespace std;

int main(){
    int a1,b1,c1; cin>> a1 >> b1 >> c1;
    int a2,b2,c2; cin >> a2 >> b2 >> c2;
    cout << setprecision(3)<< fixed;
    if (a1*b2==a2*b1){
        if ((c1*b2==c2*b1)||(c2*a1==c1*a2)) cout << "VO SO NGHIEM";
        else cout << "VO NGHIEM";
    }
    else{
        double x=(double)(c1*b2-c2*b1)/(a1*b2-a2*b1);
        double y=(double)(c1*a2-c2*a1)/(a2*b1-a1*b2);
        cout << x <<" " << y;
    }
}
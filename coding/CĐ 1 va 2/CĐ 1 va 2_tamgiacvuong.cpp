#include <bits/stdc++.h>
using namespace std;

double dis(int x1, int y1, int x2, int y2){
    int delta_x=x1-x2;
    int delta_y=y1-y2;
    return (delta_x*delta_x+delta_y*delta_y);
}

int main(){
    freopen("tamgiacv.inp","r",stdin);
    freopen("tamgiacv.out","w",stdout);
    int a1,a2; cin >> a1 >> a2;
    int b1,b2; cin >> b1 >> b2;
    int c1,c2; cin >> c1 >> c2;
    double dis_AB= dis(a1,a2,b1,b2);
    double dis_BC= dis(b1,b2,c1,c2);
    double dis_AC= dis(a1,a2,c1,c2);
    if (dis_AB+dis_BC!=dis_AC) cout << "0";
    else{
        int d_x=(a1+c1)-b1;
        int d_y=(a2+c2)-b2;
        cout << d_x << " " << d_y << endl;
    }
}
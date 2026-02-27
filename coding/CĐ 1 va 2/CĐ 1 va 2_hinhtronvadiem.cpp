#include <bits/stdc++.h>
using namespace std;

int dis(int x1, int y1, int x2, int y2){
    int delta_x=x1-x2;
    int delta_y=y1-y2;
    return (delta_x*delta_x+delta_y*delta_y);
}

int main(){
    cout << endl;
    int x,y,R; cin >> x >> y >> R;
    int xn,yn; cin >> xn >> yn;
    int rad_dis=dis(x,y,xn,yn);
    if (rad_dis>R*R){
        cout << "3";
    }
    else if (rad_dis==R*R){
        cout << "2";
    }
    else cout << "1";
}
#include <bits/stdc++.h>
using namespace std;
#define filename "ghcn"
#define ll long long

void IO(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (fopen(filename".inp" , "r"))
    {
        freopen(filename".inp" , "r" , stdin);
        freopen(filename".out" , "w" , stdout);
    }
}

int main(){
    IO();
    ll ax,ay,bx,by,cx,cy,dx,dy; 
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    pair<ll,ll> rectStH = {min(ax,bx) , max(ax,bx)};
    pair<ll,ll> rectNdH = {min(cx,dx) , max(cx,dx)};
    pair<ll,ll> rectStV = {min(ay,by) , max(ay,by)};
    pair<ll,ll> rectNdV = {min(cy,dy) , max(cy,dy)};

    ll overlapW = min(rectStH.second , rectNdH.second) - max(rectStH.first , rectNdH.first);
    ll overlapH = min(rectStV.second , rectNdV.second) - max(rectStV.first , rectNdV.first);

    if (overlapW > 0 && overlapH > 0)
        cout << overlapW * overlapH;
    else
        cout << 0;

    return 0;
}

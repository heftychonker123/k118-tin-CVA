#include <bits/stdc++.h>
using namespace std;
#define filename "segtree"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

//0-indexed sum-segment tree implementation
class SumSegmentTree{
    ll size;
    vect<ll> v;
    vect<ll> sT;
    vect<ll> lazy;
    private:
        // Propegates the "lazy" value
        void prop(ll idx, ll l, ll r) {
            if (lazy[idx] == 0) return;
            sT[idx] += (r - l + 1) * lazy[idx]; // apply to segment
            if (l != r) { // push to children
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0; // clear parent
        }
        // Performs range query using lazy propegation
        void updateRange_unwrapped(ll l, ll r, ll val, ll cl, ll cr, ll idx) {
            prop(idx, cl, cr);
            if (r < cl || l > cr) return; // no overlap
            if (l <= cl && cr <= r) {
                lazy[idx] += val;
                prop(idx, cl, cr);
                return;
            }
            ll cm = (cl + cr) / 2;
            updateRange_unwrapped(l, r, val, cl, cm, idx*2+1);
            updateRange_unwrapped(l, r, val, cm+1, cr, idx*2+2);
            sT[idx] = sT[idx*2+1] + sT[idx*2+2]; // recompute
        }

        ll build_unwrapped(ll l , ll r , ll idx = 0){
            if (l==r) return sT[idx] = v[l];
            ll m = (l+r)/2;
            ll left = build_unwrapped(l , m , 2*idx+1);
            ll right = build_unwrapped(m+1 , r , 2*idx+2);
            return sT[idx] = left+right;
        }
        ll queries_unwrapped(ll l, ll r, ll idx, ll cl, ll cr) {
            // no overlap
            prop(idx , l , r);
            if (r < cl || l > cr) return 0;
            // total overlap
            if (l <= cl && cr >= r) return sT[idx];
            // partial overlap
            ll cm = (cl + cr) / 2;
            ll leftSum  = queries_unwrapped(l, r, idx*2+1, cl, cm);
            ll rightSum = queries_unwrapped(l, r, idx*2+2, cm+1, cr);
            return leftSum + rightSum;
        }
    // Function for building , range queries and update
    public:
        // Another wrappers?
        void updateRange(ll l , ll r , ll val){
            updateRange_unwrapped(l , r , val , 0 , size-1 , 0);
        }
        void updatePoint(ll pos , ll val){
            ll l = 1 , r = size , idx = 0;
            while (l < r){
                ll mid = (l+r)/2;
                sT[idx] += val;
                if (pos > mid){
                    l = mid+1;
                    idx = 2*idx + 1;
                }
                else{
                    r = mid;
                    idx = 2*idx + 2;
                }
            }
        }
        // Wrapper for queries
        ll query(ll l , ll r){
            queries_unwrapped(l , r , 0 , 0 , size-1);
        }
        // Initialization
        SumSegmentTree(vect<ll> a){
            size = a.size();
            v = a;
            sT.resize(size*4);
            build_unwrapped(0 , size-1);
        }
};

int main(){
    // Example problem: Range Queries Point Update
    ll n,q ; cin >> n >> q;
    vect<ll> v(n) ; FOR(i , 0 , n) cin >> v[i];
    SumSegmentTree st(v);
    while (q--){
        ll queries ; cin >> queries;
        if (queries == 1){
            ll pos , x ; cin >> pos >> x;
            st.updatePoint(pos-1 , x);
        }
        if (queries == 2){
            ll l,r ; cin >> l >> r;
            cout << st.query(l-1 , r-1) << "\n";
        }
    }
    return 0;
}

/* John 3:16
                    .-=====-.
                    | .""". |
                    | |   | |
                    | |   | |
                    | '---' |
                    |       |
                    |       |
 .-================-'       '-================-.
j|  _                                          |
g|.'o\                                    __   |
s| '-.'.                                .'o.`  |
 '-==='.'.=========-.       .-========.'.-'===-'
        '.`'._    .===,     |     _.-' /
          '._ '-./  ,//\   _| _.-'  _.'
             '-.| ,//'  \-'  `   .-'
                `//'_`--;    ;.-'
                  `\._ ;|    |
                     \`-'  . |
                     |_.-'-._|
                     \  _'_  /
                     |; -:- | 
                     || -.- \ 
                     |;     .\
                     / `'\'`\-;
                    ;`   '. `_/
                    |,`-._;  .;
                    `;\  `.-'-;
                     | \   \  |
                     |  `\  \ |
                     |   )  | |
                     |  /  /` /
                     | |  /|  |
                     | | / | /
                     | / |/ /|
                     | \ / / |
                     |  /o | |
                     |  |_/  |
                     |       |
                     |       |
                     |       |
                     |       |
                     |       |
                     |       |
                     |       |
                     '-=====-'
*/
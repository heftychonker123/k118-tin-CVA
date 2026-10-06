#include <bits/stdc++.h>
using namespace std;
#define ll long long 

struct Node{
    int sum;
};

Node merge(Node a , Node b){
    return {a.sum + b.sum};
}

struct SegmentTree{
    vector<Node> st;
    void update(int pos , int x , int cl , int cr , int ci){
        if (cl == cr){
            st[ci].sum+=x;
            return;
        }

        int cm = (cl + cr)/2;
        if (pos <= cm) update(pos , x , cl , cm , ci * 2);
        else update(pos , x , cm + 1 , cr , ci * 2 + 1);

        st[ci] = merge(st[ci * 2] , st[ci * 2 + 1]);
    }

    Node query(int l , int r , int cl , int cr , int ci){
        if (l > cr || r < cl) return {0};
        if (l <= cl && cr <= r) return st[ci];

        int cm = (cl + cr)/2;
        return merge(query(l , r , cl , cm , ci * 2) , query(l , r , cm + 1 , cr , ci * 2 + 1));
    }
};


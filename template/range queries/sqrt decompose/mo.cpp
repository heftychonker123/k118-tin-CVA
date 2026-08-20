#include <bits/stdc++.h>
using namespace std;

int res = 0;
const int MAXN = 2e5 + 5;
int a[MAXN];
void remove(int idx){
    res -= a[idx];
};
void add(int idx){
    res += a[idx];
};
int get_ans(){
    return res;
};

const int BLOCK_SIZE = 367;

struct Query{
    int l,r,idx;
    bool operator< (const Query a){
        return make_pair(l / BLOCK_SIZE , r) <
               make_pair(a.l/BLOCK_SIZE , a.r);
    }

    Query(int a , int b , int c): l(a) , r(b) , idx(c){};
};

vector<int> mo(vector<Query> q){
    vector<int> answer(q.size());
    sort(q.begin() , q.end());

    int curr_l = 0 , curr_r = -1;
    for (auto i : q){
        while (curr_l > i.l){
            curr_l--;
            add(curr_l);
        }
        while (curr_r < i.r){
            curr_r++;
            add(curr_r);
        }

        while (curr_l < i.l){
            remove(curr_l);
            curr_l++;
        }

        while (curr_r > i.r){
            remove(curr_r);
            curr_r--;
        }
        
        answer[i.idx] = get_ans();
    }
    return answer;
}

signed main(){
    int n,q ; cin >> n >> q;
    for (int i = 0 ; i<n ; i++) cin >> a[i];

    vector<Query> queries;
    for (int i = 0 ; i<q ; i++){
        int l,r ; cin >> l >> r;
        l-- ; r--;
        queries.push_back(Query(l,r,i));
    }

    vector<int> ans = mo(queries);
    for (int i : ans) cout << i << " ";
}
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

signed main(){
    ordered_set dingus;
    for (int i = 1 ; i<100 ; i++){
        dingus.insert(i);
    }

    cout << dingus.size() << '\n';
}
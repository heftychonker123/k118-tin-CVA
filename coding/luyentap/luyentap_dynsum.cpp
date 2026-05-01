#include <bits/stdc++.h>
using namespace std;
#define filename "dynsum"
#define ll                  long long
#define llmin               LLONG_MIN
#define llmax               LLONG_MAX
#define pb                  push_back
#define vect                vector
#define FOR(i , m , n)      for (int i=m ; i<n ; i++)
#define FOR_r(i , m , n)    for (int i=m ; i>n ; i--)

ll n ; vect<ll> a;

struct Node{
    Node *left = nullptr , *right = nullptr;
    ll l , r;
    ll sum = 0;
    Node(ll lb , ll rb){
        l = lb ; r = rb;
    }

    void extend(){
        if (l == r) return;
        ll m = (l+r)/2;
        left = new Node(l , m);
        right = new Node(m+1 , r);
    }

    void insert(ll pos , ll val){
        sum += val; 
        r++; // Khi ta cho thêm một phần tử ngay trước pos, ta phải di chuyển r
             // 1 lần
        extend();
        ll m = (l+r)/2;
        if (m >= pos) left -> insert(pos , val);
        else right -> insert(pos , val);
    }

    void remove(ll pos){
        sum -= a[pos] ; r--;
        extend();
        ll m = (l+r)/2;
        if (m >= pos) left -> remove(pos);
        else right -> remove(pos);
    }

    ll range(ll cl , ll cr){
        if (cl > r || cr < l) return 0;
        if (cl <= l && cr <= r) return sum;
        else{
            extend();
            ll left_side = left -> range(cl , cr);
            ll right_side = right -> range(cl,cr);
            return left_side + right_side;
        }
    }
};

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
    cin >> n;
    ll q ; cin >> q;
    a.resize(n); FOR(i , 0 , n) cin >> a[i];
    Node st(0 , 0);
    ll ptr = 0;
    FOR(i , 0 , n){
        st.insert(ptr , a[i]);
        ptr++;
    };
    while (q--){
        char query ; cin >> query;
        if (query == 'A'){
            ll x ; cin >> x;
            st.insert(ptr , x);
            ptr++; n++;
        }
        if (query == 'D'){
            if (ptr >= 1) st.remove(ptr);
            ptr--;
        }
        if (query == 'L'){
            if (ptr >=0) ptr--;
        }
        if (query == 'R'){
            if (ptr <= st.r - st.l) ptr++;
        }
        if (query == 'Q'){
            ll x,y ; cin >> x >> y;
            cout << st.range(x-1 , y-1);
        }
    }
    return 0;
}


/* John 3:16
                           |~~~~~~~|
                           |       |
                         |~~~~~~~~~~~| 
                         |  I N R I  |
                         |___________|
                           |       |                             
|~.\\\_\~~~~~~~~~~~~~~xx~~~         ~~~~~~~~~~~~~~~~~~~~~/_//;~|
|  \  o \_         ,XXXXX),                         _..-~ o /  |
|    ~~\  ~-.     XXXXX`)))),                 _.--~~   .-~~~   |
 ~~~~~~~`\   ~\~~~XXX' _/ ';))     |~~~~~~..-~     _.-~ ~~~~~~~ 
          `\   ~~--`_\~\, ;;;\)__.---.~~~      _.-~
            ~-.       `:;;/;; \          _..-~~
               ~-._      `''        /-~-~ 
                   `\              /  /
                     |         ,   | |
                      |  '        /  |
                       \/;          |
                        ;;          |
                        `;   .       |
                        |~~~-----.....|
                       | \             \
                      | /\~~--...__    |
                      (|  `\       __-\|
                      ||    \_   /~    |
                      |)     \~-'      |
                       |      | \      '
                       |      |  \    :
                        \     |  |    |
                         |    )  (    ) 
                          \  /;  /\  |
                          |    |/   |
                          |    |   |
                           \  .'  ||
                           |  |  | |
                           (  | |  |
                           |   \ \ |
                           || o `.)|
                           |`\\\\) |
                           |       |
                           |       |
                           |       |
*/
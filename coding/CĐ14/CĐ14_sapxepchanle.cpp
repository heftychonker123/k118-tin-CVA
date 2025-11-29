#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string
#define vect vector
ll sum(str n){
    ll res=0;
    for (const char &i : n){
        res += i-'0';
    }
    return res;
}
vect<str> merge(vect<str> a, vect<str> b) {
    ll pa = 0, pb = 0;
    vect<str> c;
    while (pa < a.size() && pb < b.size()) {
        if (sum(a[pa]) < sum(b[pb])) {
            c.push_back(a[pa]);
            pa++;
        } else if (sum(a[pa]) > sum(b[pb])){
            c.push_back(b[pb]);
            pb++;
        }
        else{
            ll tempa = stoll(a[pa]);
            ll tempb = stoll(b[pb]);
            if (tempa==tempb){
                c.push_back(a[pa]);
                pa++;
            }
            else if (tempa<tempb){
                c.push_back(a[pa]);
                pa++;
            }
            else{
                c.push_back(b[pb]);
                pb++;
            }
        }
    }
    while (pa < a.size()) {
        c.push_back(a[pa]);
        pa++;
    }
    while (pb < b.size()) {
        c.push_back(b[pb]);
        pb++;
    }
    return c;
}

vect<str> merge_sort(vect<str> c) {
    if (c.size() <= 1) return c;
    ll mid = c.size() / 2;
    vect<str> left(c.begin(), c.begin() + mid);
    vect<str> right(c.begin() + mid, c.end());
    vect<str> sorted_left = merge_sort(left);
    vect<str> sorted_right = merge_sort(right);
    return merge(sorted_left, sorted_right);
}

int main() {
    ll n; 
    cin >> n;
    cin.ignore();

    vect<str> v;
    for (int i = 0; i < n; i++) {
        str s; cin >> s;
        v.push_back(s);
    }

    v = merge_sort(v);

    for (const str &i : v) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}

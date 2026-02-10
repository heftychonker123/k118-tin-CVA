#include <bits/stdc++.h>
using namespace std;
#define filename "mergesort"
#define ll long long
#define ld long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector
#define sstream stringstream
#define umap unordered_map


vect<ll> merge(vect<ll> a, vect<ll> b) {
    ll pa = 0, pb = 0;
    vect<ll> c;
    while (pa < a.size() && pb < b.size()) {
        if (a[pa] <= b[pb]) {   // ascending order
            c.push_back(a[pa]);
            pa++;
        } else {
            c.push_back(b[pb]);
            pb++;
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

vect<ll> merge_sort(vect<ll> c) {
    if (c.size() <= 1) return c;
    ll mid = c.size() / 2;
    vect<ll> left(c.begin(), c.begin() + mid);
    vect<ll> right(c.begin() + mid, c.end());
    vect<ll> sorted_left = merge_sort(left);
    vect<ll> sorted_right = merge_sort(right);
    return merge(sorted_left, sorted_right);
}

int main() {
    vect<ll> arr = {5, 2, 9, 1, 5, 6};
    vect<ll> sorted = merge_sort(arr);
    for (ll x : sorted) cout << x << " ";
    cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

// Find first occurrence of x
ll findFirst(const vect<ll>& v, ll x) {
    ll left = 0, right = v.size() - 1, res = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (v[mid] == x) {
            res = mid;
            right = mid - 1; // keep searching left
        } else if (v[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

// Find last occurrence of x
ll findLast(const vect<ll>& v, ll x) {
    ll left = 0, right = v.size() - 1, res = -1;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (v[mid] == x) {
            res = mid;
            left = mid + 1;
        } else if (v[mid] > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

// Lower bound: first index >= x
ll lowerBound(const vect<ll>& v, ll x) {
    ll left = 0, right = v.size();
    while (left < right) {
        ll mid = (left + right) / 2;
        if (v[mid] < x) left = mid + 1;
        else right = mid;
    }
    return left; // may equal v.size()
}

// Upper bound: first index > x
ll upperBound(const vect<ll>& v, ll x) {
    ll left = 0, right = v.size();
    while (left < right) {
        ll mid = (left + right) / 2;
        if (v[mid] <= x) left = mid + 1;
        else right = mid;
    }
    return left; // may equal v.size()
}

int main() {
    ll n, x; cin >> n >> x;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    ll first = findFirst(v, x);
    ll second = findLast(v, x);
    ll third = lowerBound(v, x);
    ll fourth = upperBound(v, x);
    ll fifth = (first == -1 ? 0 : second - first + 1);

    cout << first << "\n";
    cout << second << "\n";
    cout << third << "\n";
    cout << fourth << "\n";
    cout << fifth << "\n";
    return 0;
}

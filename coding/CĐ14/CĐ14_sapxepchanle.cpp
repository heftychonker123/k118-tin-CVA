#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vect vector

int main() {
    int n; 
    cin >> n;
    vect<ll> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    ll mid;
    if (n%2==0){
        mid = n/2;
    }
    else{
        mid = n/2 + 1;
    }
    vect<ll> left(v.begin(), v.begin() + mid);   // first half
    vect<ll> right(v.begin() + mid, v.end());    // second half
    ll lp = 0, rp = 0;
    for (int i=0 ; i<n ; i++){
        if (i%2==0){
            cout << left[lp];
            lp++;
        }
        else{
            cout << right[rp];
            rp++;
        }
        cout << " ";
    }
    cout << "\n";
    return 0;
}

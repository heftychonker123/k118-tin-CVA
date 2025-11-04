#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define vect vector

// Function to compute and print row sums without trailing space
void row_sum(vect<vect<ll>> v, ll cols , ll rows){
    for (size_t r = 0; r < v.size(); r++){
        ll sum = 0;
        for (vect<ll>::iterator it = v[r].begin(); it != v[r].end(); ++it){
            sum += *it;
        }
        cout << sum;
        if (r != v.size() - 1) cout << " ";
    }
    cout << endl;
}

// Function to compute and print column sums without trailing space
void col_sum(vect<vect<ll>> v, ll cols , ll rows){
    for (int i = 0; i < cols; i++){
        ll sum = 0;
        for (const vect<ll>& temp : v){
            sum += temp[i];
        }
        cout << sum;
        if (i != cols - 1) cout << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vect<vect<ll>> v(n);
    for (int i = 0; i < n; i++){
        vect<ll> temp(m);
        for (int j = 0; j < m; j++) cin >> temp[j];
        v[i] = temp;
    }

    row_sum(v, m, n);
    col_sum(v, m, n);

    return 0;
}

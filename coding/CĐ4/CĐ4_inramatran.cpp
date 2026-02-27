#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define vect vector

// Function to print columns top to bottom
void print1(vect<vect<ll>> v , ll rows , ll cols){
    for (int i = 0; i < cols; i++){
        for (const vect<ll>& temp : v){
            cout << temp[i] << " ";
        }
        cout << endl;
    }
}

// Function to print matrix in reverse row and column order
void print2(vect<vect<ll>> v , ll rows , ll cols){
    for (int i = rows - 1; i >= 0; i--){
        for (int l = cols - 1; l >= 0; l--){
            cout << v[i][l] << " ";
        }
        cout << endl;
    }
}

// Function to print columns bottom to top
void print3(vect<vect<ll>> v , ll rows , ll cols){
    for (int i = cols - 1; i >= 0; i--){
        for (const vect<ll>& temp : v){
            cout << temp[i] << " ";
        }
        cout << endl;
    }
}

// Function to print each row in reverse
void print4(vect<vect<ll>> v , ll rows , ll cols){
    for (int i = 0; i < rows; i++){
        for (int l = cols - 1; l >= 0; l--){
            cout << v[i][l] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    m = n;

    vect<vect<ll>> v(n);
    for (int i = 0; i < n; i++){
        vect<ll> temp(m);
        for (int j = 0; j < m; j++) cin >> temp[j];
        v[i] = temp;
    }

    cout << "Mau 1:" << endl;
    print1(v, n, m);
    cout << "Mau 2:" << endl;
    print2(v, n, m);
    cout << "Mau 3:" << endl;
    print3(v, n, m);
    cout << "Mau 4:" << endl;
    print4(v, n, m);

    return 0;
}

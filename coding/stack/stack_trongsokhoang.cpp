#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    vector<int> leftGreater(n), rightGreater(n), leftSmaller(n), rightSmaller(n);

    
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<=a[i]) st.pop();
        leftGreater[i] = st.empty()? i+1 : i-st.top();
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()]<a[i]) st.pop();
        rightGreater[i] = st.empty()? n-i : st.top()-i;
        st.push(i);
    }

    
    while(!st.empty()) st.pop();
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]>=a[i]) st.pop();
        leftSmaller[i] = st.empty()? i+1 : i-st.top();
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()]>a[i]) st.pop();
        rightSmaller[i] = st.empty()? n-i : st.top()-i;
        st.push(i);
    }

    ll ans=0;
    for(int i=0;i<n;i++){
        ll cntMax = 1LL*leftGreater[i]*rightGreater[i];
        ll cntMin = 1LL*leftSmaller[i]*rightSmaller[i];
        ans += a[i]*(cntMax - cntMin);
    }
    cout << ans;
}

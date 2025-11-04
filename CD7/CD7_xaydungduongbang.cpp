#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db long double
#define str string
#define llmin LLONG_MIN
#define llmax LLONG_MAX
#define pb push_back
#define strri string::reverse_iterator
#define stri string::iterator
#define vect vector

vect<ll> prefix_sum(vect<ll> v , ll len){
    vect<ll> ans(len);
    ll temp=0;
    for (int i=0 ; i<len ; i++){
        temp+=v[i];
        ans[i]=temp;
    }
    return ans;
}
void solve(vect<vect<ll>> v , ll rows , ll cols){
    
}
int main(){
    ios::sync_with_stdio(false); // Tăng tốc độ nhập xuất
    cin.tie(nullptr);
    return 0;
}
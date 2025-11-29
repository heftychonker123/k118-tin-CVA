#include <bits/stdc++.h>
using namespace std;
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
//Kadane's algorithm is a dynamic programming algorithm
//designed to find the largest continious subarray sum of a array

//TODO: Kadane's algorithm that print the start and 
//end of the maximally sum-large continiuos subarray


//Taking the array and its length
void Kadane(vect<ll> v , ll length){
    vect<ll> ans(length,v[0]);
    vect<ll> markup(length,1);
    //For every element of the array
    for (int i=1 ; i<length ; i++){
        ll t=v[i];
        //If that element is positive and the subarray sum is positive, 
        //it is always benificial to add it to the subarray sum
        if (t>=0){
            if (ans[i-1]>=0){
                ans[i]=ans[i-1] + t;
            }
            else{
                ans[i] = t;
                markup[i]=markup[i-1]+1;
            }
        }
        //Else
        //Select the best option from 2 options: add or create a new subarray;
        else{
            // create a new subarray
            if (t > ans[i-1] + t){
                ans[i]=t;
                markup[i]=markup[i-1]+1;
            }
            // add to the old subarray
            else{
                ans[i] = ans[i-1]+t;
                markup[i]=markup[i-1];
            }
        }
    }
    /* ancient debugging code
    for (const ll &i : ans) cout << i << " ";
    cout << endl;
    for (const ll &i : markup) cout << i << " ";
    cout << endl;
    */

    
    ll ans_pos=0; 
    // Stores the position of the largest subarray sum()
    //(aka the rightmost position of the subarray)

    // Through every element of the array
    for (int i=0 ; i<length ; i++){
        if (ans[i]>ans[ans_pos]) ans_pos=i;
    }
    ll left=0;
    // Stores the position of the leftmost position of the subarray
    for (int i=0 ; i<length ; i++){
        if (markup[i] == markup[ans_pos]){
            left=i;
            break;
        }
    }
    cout << left+1 << " " << ans_pos+1 << "\n";
    cout << *max_element(ans.begin() , ans.end()) << "\n";
}
void solve(vect<vect<ll>> v , ll rows , ll cols){
    for (int left=0 ; left < cols ; left++){
        for (int right=left+1 ; right< cols ; right++){}
    }
}
int main(){
    //freopen("kstring.inp" , "r" , stdin);
    //freopen("kstring.out" , "w" , stdout);
    int n; cin >> n;
    vect<ll> v(n);
    for (int i=0 ; i<n ; i++){
        cin >> v[i];
    }
    Kadane(v , n);
    return 0;
}
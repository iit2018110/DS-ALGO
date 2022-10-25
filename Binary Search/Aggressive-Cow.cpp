#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vll vector<ll>
#define F(i,n) for(int i = 0; i < n; ++i)

bool check(ll dist, vll &arr, ll c) {
    ll ls = 0;
    c--;
    for(int i = 1; i < arr.size(); ++i) {
        if(arr[i]-arr[ls] >= dist) {
            c--;
            ls = i;
            if(c == 0) return true;
        }
    }
    
    return false;
}

int main() {
    int t; cin>>t;
    while(t--) {
        ll n,c; cin>>n>>c;
        vll arr(n);  F(i,n) cin>>arr[i];
        sort(arr.begin(),arr.end());
        
        ll lo = 0, hi = arr[n-1]-arr[0], res = -1;
        while(lo <= hi) {
            ll mid = lo + (hi - lo)/2;
            if(check(mid,arr,c)) {
                res = max(res,mid);
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        
        cout<<res<<endl;
    }
    
    
    return 0;
}
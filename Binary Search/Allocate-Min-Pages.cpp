#define ll long long int

bool check(int cap, vector<int> &arr, int k) {
    int c = 0;
    for(int i = 0; i < arr.size(); ++i) {
        c += arr[i];
        if(c > cap) {
            k--;
            if(k == 0) return false; 
            c = arr[i];
        }
    }

    return true;
}

int Solution::books(vector<int> &arr, int k) {
    if(k > arr.size()) return -1;

    ll lo = *max_element(arr.begin(),arr.end());

    ll hi = 0;
    for(int i = 0; i < arr.size(); ++i) hi += arr[i];

    ll res = INT_MAX;
    while(lo <= hi) {
        ll mid = lo + (hi - lo)/2;
        if(check(mid,arr,k)) {
            res = min(res,mid);
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    return res;
}
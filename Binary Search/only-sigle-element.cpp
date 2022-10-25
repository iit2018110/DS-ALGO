int singleNonDuplicate(vector<int>& arr) {
    int n = arr.size();
    if(n == 1) return arr[0];
    
    int lo = 0, hi = n-1;
    int res = -1;
    while(lo <= hi) {
        int mid = lo + (hi-lo)/2;
        if(mid%2) { //idx is odd
            if(arr[mid]==arr[mid-1]) lo = mid+1;
            else {
                res = arr[mid];
                hi = mid-1;
            }
        } else {  //idx is even
            if(arr[mid]==arr[mid+1]) lo = mid+1;
            else {
                res = arr[mid];
                hi = mid-1;
            }
        }
    }
    
    return res;
}
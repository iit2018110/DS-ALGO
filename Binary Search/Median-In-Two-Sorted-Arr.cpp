double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    if(n2 < n1) return findMedianSortedArrays(arr2,arr1);
    
    int lo = 0, hi = n1; // number of element selected from 1st array
    
    while(lo <= hi) {
        int c1 = lo + (hi - lo)/2; // cut1
        int c2 = (n1 + n2 + 1)/2 - c1; //cut2
        
        int left1 = c1 == 0? INT_MIN : arr1[c1-1];
        int left2 = c2 == 0? INT_MIN : arr2[c2-1];
        
        int right1 = c1 == n1? INT_MAX : arr1[c1];
        int right2 = c2 == n2? INT_MAX : arr2[c2];
        
        if(left1 <= right2 and left2 <= right1) {
            if((n1+n2)%2 == 0) return (float)(max(left1,left2) + min(right1,right2))/2.0;
            else return max(left1,left2);
        }
        else if(left1 > right2)
            hi = c1 - 1;
        else 
            lo = c1+1;
            
    }
    return 0.0;
}
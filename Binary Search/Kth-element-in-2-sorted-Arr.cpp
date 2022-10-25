int findKthSortedArrays(vector<int>& nums1, vector<int>& nums2, int K) {
    int n = nums1.size(), m = nums2.size();

    if(n<m){
        return findKthSortedArrays(nums2, nums1, K);
    }

    int lt = max(0,K-m), rt = min(K,n);

    while(lt<=rt){
        int partX = (lt+rt)/2;
        int y = K - partX;
    
        int maxLeftX = (partX-1>=0 ? nums1[partX-1] : INT_MIN);
        int minRightX = (partX<n ? nums1[partX] : INT_MAX);

        int maxLeftY = (y-1>=0 ? nums2[y-1] : INT_MIN); 
        int minRightY = (y<m ? nums2[y] : INT_MAX);

        if(maxLeftX<=minRightY && maxLeftY<=minRightX){
            return max(maxLeftX, maxLeftY);
        }else if(maxLeftX>minRightY){
            rt = partX-1;
        }else{
            lt = partX+1;
        }

    }

    return -1;
}
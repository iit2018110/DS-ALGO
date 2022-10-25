void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i=m-1,j=n-1,k=m+n-1;
    while(i>=0&&j>=0)
    {
        if(nums1[i]>nums2[j])
        {
            nums1[k]=nums1[i];
            i--;
            k--;
        }
        else
        {
            nums1[k]=nums2[j];
            j--;
            k--;
        }
    }
    while(i>=0)
        nums1[k--]=nums1[i--];
    while(j>=0)
        nums1[k--]=nums2[j--];
}


void merge(long long arr1[], long long arr2[], int n, int m) 
{ 
    int i=n-1,j=0;
    
    while(i>=0 && j<m)
    {
        if(arr1[i]>arr2[j])
            swap(arr1[i--],arr2[j++]);
        else 
            break;
    }
    
    sort(arr1,arr1+n);
    sort(arr2,arr2+m); 
} 
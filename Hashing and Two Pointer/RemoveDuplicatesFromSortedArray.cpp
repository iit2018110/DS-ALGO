int removeDuplicates(vector<int>& nums) {        
    int n = nums.size();
    if(n==0 or n == 1) return n;
    int l = 0, r = 1;
    while(r < n) {
        if(nums[r] == nums[l]) r++;
        else nums[++l] = nums[r], r++;
    }
    
    return l+1;
}
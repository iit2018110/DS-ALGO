void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int idx = n-2;
    while(idx >= 0 and nums[idx] >= nums[idx+1]) {
        idx--;
    }
    
    if(idx >= 0) {
        int i = n-1;
        while(i >= 0 and nums[i] <= nums[idx]) {
            i--;
        }
        swap(nums[i],nums[idx]);
    }
    
    reverse(nums.begin()+idx+1,nums.end());
}
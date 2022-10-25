int findMaxConsecutiveOnes(vector<int>& nums) {
    int curr_count = 0,max_count=0;
    
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] == 1) curr_count++;
        else curr_count = 0;
        
        max_count = max(max_count,curr_count);
    }
    
    return max_count;
}
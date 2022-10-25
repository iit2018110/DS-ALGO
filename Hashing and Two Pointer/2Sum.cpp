class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans; 
        unordered_map<int, int> ump; 

        for(int i = 0;i<nums.size();i++) {
            if(mpp.find(target - nums[i]) != mpp.end()) 
                return {ump[target - nums[i]], i};

            mpp[nums[i]] = i; 
        }
        
        return ans; 
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> ump;
        
        int n = arr.size();
        for(int i = 0; i < n; ++i) {
            if(ump.find(target - arr[i]) != ump.end())
                return {ump[target - arr[i]],i};
            
            ump[arr[i]] = i;
        }
        
        return {};
    }
};
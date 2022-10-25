int maxLen(vector<int>&arr, int n)
{   
    unordered_map<int,int> ump;
    ump[0] = -1;

    int sum = 0, res = 0;
    
    for(int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        
        if(ump.find(sum) != ump.end()) {  //present in map
            res = max(res,i-ump[sum]);
        }
        else ump[sum] = i;
    }
    
    return res;
}
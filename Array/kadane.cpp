int maxSubArray(vector<int>& arr) {
    int n = arr.size();
    int curr_max = arr[0], overall_max = arr[0];
    
    for(int i = 1; i < n; ++i) {
        
        if(arr[i] > curr_max + arr[i]) {
            curr_max = arr[i];
        } 
        
        else {
            curr_max += arr[i];
        }
        
        if(curr_max > overall_max)
            overall_max = curr_max;
    }
    
    return overall_max;
}
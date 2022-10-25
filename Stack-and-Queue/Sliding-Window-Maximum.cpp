vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    vector<int> res;
    deque<int> dq;  //will store only index
    
    for(int i = 0; i < arr.size(); ++i) {
        if(!dq.empty() and dq.front() == i-k)
            dq.pop_front();
        
        while(!dq.empty() and arr[dq.back()] < arr[i])
            dq.pop_back();
        
        dq.push_back(i);
        
        if(i >= k-1) res.push_back(arr[dq.front()]);
    }
    
    return res;
}
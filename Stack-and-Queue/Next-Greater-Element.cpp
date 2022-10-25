vector<int> Solution::nextGreater(vector<int> &arr) {
    vector<int> nge(arr.size());
    stack<int> stk;
    for(int i = arr.size()-1; i >= 0; --i) {
        while(!stk.empty() and stk.top() <= arr[i])
            stk.pop();
            
        if(stk.empty()) nge[i] = -1;
        else nge[i] = stk.top();
        
        stk.push(arr[i]);
    }
    
    return nge;
}
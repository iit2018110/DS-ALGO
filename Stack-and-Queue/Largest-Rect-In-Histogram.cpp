class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int rli[n],lli[n];
        
        stack<int> stk,stk1;
        
        for(int i = n-1; i >= 0; --i) {
            while(!stk.empty() and heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            
            if(stk.empty()) rli[i] = n;
            else rli[i] = stk.top();
            
            stk.push(i);
        }
        
        for(int i = 0; i < n; ++i) {
            while(!stk1.empty() and heights[stk1.top()] >= heights[i]) {
                stk1.pop();
            }
            
            if(stk1.empty()) lli[i] = -1;
            else lli[i] = stk1.top();
            
            stk1.push(i);
        }
        
        int largestArea = 0;
        
        for(int i = 0; i < n; ++i) {
            largestArea = max(largestArea, heights[i]*(rli[i]-lli[i]-1));
        }
        
        return largestArea;
    }
};
int maxProfit(vector<int>& prices) {
    int minCost=INT_MAX/10;
    int maxProfit = INT_MIN/10;
    for(int i = 0; i < prices.size(); ++i) {
        if(prices[i]-minCost > maxProfit) maxProfit = prices[i]-minCost;
        
        minCost = min(minCost,prices[i]);
    }
    
    return max(0,maxProfit);
}
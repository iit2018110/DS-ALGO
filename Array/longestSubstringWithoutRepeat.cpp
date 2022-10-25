int lengthOfLongestSubstring(string str) {
    int n = str.size();
    unordered_map<char,int> ump;

    int res = 0, start = 0;
    
    for(int i = 0; i < n; ++i) {
        if(ump.find(str[i]) != ump.end()) {
            if(ump[str[i]] >= start) {
                start = ump[str[i]]+1;
            }
        }
        ump[str[i]] = i;
        res = max(res,i-start+1);
    }
    
    return res;
}

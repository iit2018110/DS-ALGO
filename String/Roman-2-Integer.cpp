int romanToInt(string str) {
    map<char,int> mp; 
    mp.insert({'I',1}), mp.insert({'V',5}), mp.insert({'X',10});
    mp.insert({'L',50}), mp.insert({'C',100}), mp.insert({'D',500}), mp.insert({'M',1000}); 
    
    int res = 0;
    for(int i = 0; i < str.size(); ++i) {
        res += mp[str[i]];
        if(i > 0 and mp[str[i]] > mp[str[i-1]]) 
            res -= 2 * mp[str[i-1]];
    }
    
    return res;
}
bool isAnagram(string s, string t) {
    map<char,int> mp;
    for(char ch : s) mp[ch]++;
    for(char ch : t) mp[ch]--;
    
    for(auto it : mp)
        if(it.second != 0) return false;
    
    return true;
}
string longestPalindrome(string s) {
    if(s.size() <= 1) return s;
    si = 0,maxL = 1;
    for(int i = 0; i < s.size(); ++i) {
        expand(s,i,i);
        expand(s,i,i+1);
    }
    return s.substr(si,maxL);
}

void expand(string &s, int l, int r) {
    while(l>=0 and r<s.size() and s[l]==s[r])
        l--,r++;
    
    if(r-l-1 > maxL) {
        maxL = r-l-1;
        si = l+1;
    }
}
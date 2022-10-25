void computeLPS(string str, vector<int> & lps, int n) {
    for(int i = 1; i < n; ++i) {
        int j = lps[i-1];
        while(j > 0 and str[i] != str[j]) 
            j = lps[j-1];
        
        if(str[i] == str[j]) {
            j++;
            lps[i] = j;
        }
    }

}

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(haystack == "") return -1;
        
        int n = haystack.size();
        int m = needle.size();
        if(m > n) return -1;
        vector<int> lps(n);
        computeLPS(needle,lps,m);
        
        int i = 0, j = 0;
        while(i < n) {
            if(haystack[i] == needle[j]) {
                i++, j++;
            }
            
            if(j == m) return i-m;
            else if(i < n and haystack[i] != needle[j]){
                if(j != 0) j = lps[j-1];
                else i += 1;
            }
        }
        
        return -1;
    }
};
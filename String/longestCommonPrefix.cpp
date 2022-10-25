class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        if(n==0) return "";

        string res = "";
        for(int i = 0; i < 200; ++i) {
            int sz1 = strs[0].size();
            if(i > (sz1-1)) return res;

            char ch = strs[0][i];

            for(int j = 0; j < n; ++j) {
                int sz2 = strs[j].size();
                if(sz2-1<i) return res;

                if(strs[j][i] != ch) return res;

            }
            
            res.push_back(ch);
        }

        return res;
    }
};
class Solution {
public:
    bool isValid(string str) {
        map<char,char> mp;
        mp[')'] = '(', mp['}'] = '{', mp[']'] = '[';
        
        stack<char> stk;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == '(' or str[i] == '{' or str[i] == '[') stk.push(str[i]);
            else {
                if(stk.empty()) return false;
                if(stk.top() != mp[str[i]]) return false;
                stk.pop();
            }
        }
        
        return stk.empty();
    }
};
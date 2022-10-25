int myAtoi(string s) {
    int sign = 1, base = 0, n = s.size();
    
    //trim all initial whitespaces
    int i = 0;
    while(i <  n and s[i]==' ') i++;
    
    //check for sign
    if(s[i]=='-' or s[i]=='+') {
        if(s[i]=='-') sign = -1;
        i++;
    }
        
    while(i < n and s[i]>='0' and s[i]<='9') {
        // handle overflow
        if(base > INT_MAX/10 or (base == INT_MAX/10 and s[i]>'7')) {
            if(sign==1) return INT_MAX;
            else return INT_MIN;
        }

        base = base*10 + (s[i]-'0');
        
        i++;
    }
    
    
    return sign*base;
}
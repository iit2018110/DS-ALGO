#define ll long long int

class Solution {
public:
    int mySqrt(int x) {
        ll l = 0, r = x;
        ll res = -1;
        while(l <= r) {
            ll m = l + (r-l)/2;
            if(m * m == x) 
                return m;
            else if(m*m > x) 
                r = m-1;
             else {
                res = max(res,m);
                l = m+1;
            }
        }
        
        return res;
    }
};
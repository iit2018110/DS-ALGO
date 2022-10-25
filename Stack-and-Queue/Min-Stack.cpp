#define ll long long int

class MinStack {
private:
    stack<ll> stk;
    ll minv;
public:
    /** initialize your data structure here. */
    MinStack() {
        minv = INT_MAX/10;
    }
    
    void push(ll value) {
        ll val = value;
        if(stk.empty()) {
            stk.push(val);
            minv = val;
        } else {
            if(val > minv) stk.push(val);
            else { 
                stk.push((2ll*val - minv));
                minv = val;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        ll ele = stk.top();
        if(ele < minv) {
            minv = 2*minv - ele;
        }
        stk.pop();
    }
    
    ll top() {
        if(stk.empty()) return -1;
        ll ele = stk.top();
        if(ele < minv) {
            return minv;
        }
        return stk.top();
    }
    
    ll getMin() {
        if(stk.empty()) return -1;
        return minv;
    }
};
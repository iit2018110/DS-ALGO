class MyQueue {
    stack<int> stk1,stk2;
public:
    /** Initialize your data structure here. */
    MyQueue() {  
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while(!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk1.push(x);
        while(!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int temp = stk1.top();
        stk1.pop();
        return temp;
    }
    
    /** Get the front element. */
    int peek() {
        return stk1.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty();
    }
};
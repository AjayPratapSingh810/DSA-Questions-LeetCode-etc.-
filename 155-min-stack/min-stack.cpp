class MinStack {
public:
    stack<int> st;
    stack<int> minStack;
    int min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int val) {
        if(min >= val){
            min = val;
        }
        st.push(val);
        minStack.push(min);
    }
    
    void pop() {
        st.pop();
        minStack.pop();
        if(minStack.empty()){
             min = INT_MAX;
        }else{
            min = minStack.top();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
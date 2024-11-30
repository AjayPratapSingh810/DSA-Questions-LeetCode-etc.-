class MinStack {
public:
    stack<pair<int,int> > st;
    stack<int> minimum;
    int mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        mini = min(val,mini);
        minimum.push(mini);
        pair<int,int> p = make_pair(val,mini);
        st.push(p);
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        pair<int,int> p = st.top();
        minimum.pop();
        if(minimum.empty()){
            mini = INT_MAX;
        }else{
            mini = minimum.top();
        }
        st.pop(); 
    }
    
    int top() {
        pair<int,int> p = st.top();
        return p.first;
    }
    
    int getMin() {
        return minimum.top();
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
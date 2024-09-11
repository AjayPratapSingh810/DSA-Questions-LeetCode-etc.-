class FreqStack {
public:
    priority_queue<vector<int> > pq;
    unordered_map<int,int> mp;
    int size = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        vector<int> v = {mp[val],size,val};
        pq.push(v);
        size++;
    }
    
    int pop() {
        
            vector<int> front = pq.top();
            pq.pop();
            mp[front[2]]--;
            return front[2];
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
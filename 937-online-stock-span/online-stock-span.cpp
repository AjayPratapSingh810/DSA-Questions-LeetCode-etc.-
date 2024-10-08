class StockSpanner {
public:
    stack<pair<int,int> > st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int stack = 1;
        while(!st.empty() && st.top().first <= price){
            stack = stack+st.top().second;
            st.pop();
        }
        st.push(make_pair(price,stack));
        return stack;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
class StockSpanner {
public:
    vector<int> arr;
    int index;
    StockSpanner() {
        index = -1;
    }
    
    int next(int price) {
        index++;
        arr.push_back(price);
        int ans = 0;
        for(int i = index;i>=0;i--){
            if(arr[i] <= price){
                ans++;
            }else{
                break;
            }
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
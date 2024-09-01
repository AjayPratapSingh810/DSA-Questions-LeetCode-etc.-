class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int size = nums.size();
        if(size < 3){
            return false;
        }
        vector<int> mini(size,INT_MAX);
        mini[0] = nums[0];
        for(int i = 1;i<size;i++){
            mini[i] = min(mini[i-1],nums[i]);
        }
        stack<int> st;
        for(int i = size-1;i>=0;i--){
            while(st.size() && nums[st.top()] < nums[i]){
                auto x = st.top();
                if(nums[x] > mini[i]){
                    return true;
                }
                st.pop();
            }
            st.push(i);
        }
        return false;
    }
};
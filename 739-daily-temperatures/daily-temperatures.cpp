class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size,-1);
        stack<pair<int,int>> st;
        for(int i = size-1;i>=0;i--){

            while(!st.empty() && st.top().first <= temperatures[i]){
                st.pop();
            }

            if(st.empty()){
                ans[i] = 0;
            }else{
                ans[i] = st.top().second - i;
            }
            st.push(make_pair(temperatures[i],i));
        }
        return ans;
    }
};
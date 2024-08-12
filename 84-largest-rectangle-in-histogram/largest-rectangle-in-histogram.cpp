class Solution {
public:
    void solveNse(vector<int> heights,vector<int> &ans){
        int n = heights.size();
        stack<int> st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
    }
    void solvePse(vector<int> heights,vector<int> &ans){
        int n = heights.size();
        stack<int> st;
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> pse(size,-1);
        vector<int> nse(size,size);
        solveNse(heights,nse);
        solvePse(heights,pse);
        int ans = INT_MIN;
        for(int i = 0;i<size;i++){
            int value = (nse[i]-pse[i]-1)*heights[i];

            if(value > ans){
                ans = value;
            }
        }
        return ans;
    }
};
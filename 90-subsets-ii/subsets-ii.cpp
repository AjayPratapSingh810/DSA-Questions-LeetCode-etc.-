class Solution {
public:
    void solve(int x,int size,vector<int> st,set<vector<int>> &ans,vector<int> nums){
        if(x>=size){
            sort(st.begin(),st.end());
            ans.insert(st);
            return;
        }
        st.push_back(nums[x]);
        solve(x+1,size,st,ans,nums);
        st.pop_back();
        solve(x+1,size,st,ans,nums);
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int> > ans;
        vector<int> st;
        solve(0,nums.size(),st,ans,nums);
        vector<vector<int> > answer;
        for(auto i:ans){
            answer.push_back(i);
        }
        return answer;
    }
};
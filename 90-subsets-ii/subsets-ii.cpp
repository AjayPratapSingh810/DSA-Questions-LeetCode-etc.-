class Solution {
public:
    void solve(int x,set<vector<int> > &st,vector<int> &nums,vector<int> arr){
        sort(arr.begin(),arr.end());
        st.insert(arr);
        
        for(int i = x;i<nums.size();i++){
            arr.push_back(nums[i]);
            solve(i+1,st,nums,arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int> > st;
        vector<int> arr;
        solve(0,st,nums,arr);
        vector<vector<int> > ans;
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};
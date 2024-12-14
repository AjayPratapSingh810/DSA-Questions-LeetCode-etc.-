class Solution {
public:
    void solve(int x,vector<int> &nums,set<vector<int> > &ans,vector<int> &arr){
        if(x == nums.size()){
            ans.insert(arr);
            return;
        }
        arr.push_back(nums[x]);
        solve(x+1,nums,ans,arr);
        arr.pop_back();
        solve(x+1,nums,ans,arr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> arr;
        for(int i = 0;i<nums.size();i++){
            solve(i,nums,ans,arr);
        }
        vector<vector<int> > a;
        for(auto i : ans){
            a.push_back(i);
        }
        return a;
    }
};
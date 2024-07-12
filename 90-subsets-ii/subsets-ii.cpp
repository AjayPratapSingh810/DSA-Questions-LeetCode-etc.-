class Solution {
public:
    void solve(vector<int> &nums,vector<int> &arr,vector<vector<int> > &ans,int index){
        if(index >= nums.size()){
            return;
        }
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i] == nums[i-1]){
                continue;
            }
            arr.push_back(nums[i]);
            ans.push_back(arr);
            solve(nums,arr,ans,i+1);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(nums.begin(),nums.end());
        ans.push_back(arr);
        solve(nums,arr,ans,0);
        return ans;
    }
};
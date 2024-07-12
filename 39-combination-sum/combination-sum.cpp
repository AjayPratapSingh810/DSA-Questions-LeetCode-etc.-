class Solution {
public:
    void solve(vector<vector<int>> &ans,vector<int> arr,vector<int>& candidates,int target,int index,int sum){
        if(sum > target){
            return;
        }
        else if(sum == target){
            ans.push_back(arr);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            arr.push_back(candidates[i]);
            sum = sum + candidates[i];
            solve(ans,arr,candidates,target,i,sum);
            sum = sum-candidates[i];
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        int index = 0;
        sort(candidates.begin(),candidates.end());
        solve(ans,arr,candidates,target,index,0);
        return ans;
    }
};
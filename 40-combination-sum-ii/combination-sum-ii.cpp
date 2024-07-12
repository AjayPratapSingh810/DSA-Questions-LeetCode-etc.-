class Solution {
public:
    void solve(vector<int>& candidates,int target,vector<vector<int>> &ans,vector<int> arr,int sum,int index){
        if(sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(arr);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            arr.push_back(candidates[i]);
            sum = sum+candidates[i];
            solve(candidates,target,ans,arr,sum,i+1);
            arr.pop_back();
            sum = sum-candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        int sum = 0;
        int index = 0;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,ans,arr,sum,index);
        return ans;
    }
};
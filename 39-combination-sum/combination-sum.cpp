class Solution {
public:
    void solve(vector<int>& candidates,int target,vector<vector<int> > &ans,int sum,int index,vector<int> arr){
        if(sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(arr);
            return;
        }
        for(int i = index;i<candidates.size();i++){
            arr.push_back(candidates[i]);
            sum += candidates[i];
            solve(candidates,target,ans,sum,i,arr);
            sum -= candidates[i];
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> arr;
        solve(candidates,target,ans,0,0,arr); 
        return ans;
    }
};
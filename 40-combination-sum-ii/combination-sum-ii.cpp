class Solution {
public:
    void solve(int index,vector<vector<int> > &ans,vector<int> &arr,vector<int>& candidates,int target,int sum){
        if(sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(arr);
            return;
        }
        for(int i = index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1])
                continue;
            sum = sum + candidates[i];
            arr.push_back(candidates[i]);
            solve(i+1,ans,arr,candidates,target,sum);
            arr.pop_back();
            sum = sum-candidates[i];
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int> > ans;
        vector<int> arr;
        solve(0,ans,arr,candidates,target,0);
        return ans;
    }
};
class Solution {
public:
    void solve(int x, vector<int>& candidates, int target, int sum,
               vector<int>& arr, vector<vector<int>>& ans) {
        if(sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(arr);
            return;
        }

        for (int i = x; i < candidates.size(); i++) {
             if(i > x && candidates[i] == candidates[i-1]){
                continue;
            }
            sum += candidates[i];
            arr.push_back(candidates[i]);
            solve(i + 1, candidates, target, sum, arr, ans);
            sum -= candidates[i];
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, 0, arr, ans);
        return ans;
    }
};
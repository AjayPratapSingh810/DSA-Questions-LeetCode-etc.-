class Solution {
public:
    void solve(int x,vector<int> &arr,int &sum,int target,vector<int> &candidates,set<vector<int> > &ans){
        if(x >= candidates.size() || sum >= target){
            if(sum == target){
                ans.insert(arr);
                return;
            }
            return;
        }

        for(int i = x;i<candidates.size();i++){
            sum = sum + candidates[i];
            arr.push_back(candidates[i]);
            solve(i,arr,sum,target,candidates,ans);
            sum = sum - candidates[i];
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int> > a;
        
        for(int i=0;i<candidates.size();i++){
            vector<int> arr;
            int sum = 0;
            solve(i,arr,sum,target,candidates,a);
        }
        vector<vector<int> > ans;
        for(auto i : a){
            ans.push_back(i);
        }
        return ans;
    }
};
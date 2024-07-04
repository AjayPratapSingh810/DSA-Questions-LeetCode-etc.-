class Solution {
public:
    void solve(int ind,vector<int> arr,vector<vector<int> > &ans,int n,int k){
        if(arr.size() == k){
            ans.push_back(arr);
            return;
        }
        for(int i = ind;i<=n;i++){
            arr.push_back(i);
            solve(i+1,arr,ans,n,k);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        vector<vector<int>> ans;
        solve(1,arr,ans,n,k);
        return ans;
    }
};
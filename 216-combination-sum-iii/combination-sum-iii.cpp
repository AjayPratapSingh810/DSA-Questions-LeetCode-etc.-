class Solution {
public:
    void solve(int x,int sum,vector<int> &arr,vector<int> &track,vector<vector<int> > &ans,int k,int n){
        if(sum == n && arr.size() == k){
            ans.push_back(arr);
            return;
        }
        if(x >= 9 || arr.size() > k){
            return;
        }
        arr.push_back(track[x]);
        sum += track[x];
        solve(x+1,sum,arr,track,ans,k,n);
        arr.pop_back();
        sum -= track[x];
        solve(x+1,sum,arr,track,ans,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> track(9);
        for(int i=0;i<9;i++){
            track[i] = i+1;
        }
        vector<vector<int> > ans;
        vector<int> arr;
        solve(0,0,arr,track,ans,k,n);
        return ans;
    }
};
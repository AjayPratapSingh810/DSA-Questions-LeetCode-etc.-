class Solution {
public:
    void merge(vector<int> &nums,long long s,long long mid,long long e,int &ans){
        long long x  = s;
        long long y = mid+1;
        long long size1 = mid-s+1;
        long long size2 = e-mid;
        for(int i=s; i<=mid; i++){
            while(y<=e && nums[i] > 2*(long long)nums[y]){
                y++;
            }
            ans += y-(mid+1);
        }
        y = mid+1;
        vector<int> L(size1), R(size2);
        for(int i = 0;i<size1;i++){
            L[i] = nums[x++];
        }
        for(int i = 0;i<size2;i++){
            R[i] = nums[y++];
        }
        int k = s;
        x = 0;
        y = 0;
        while(x<size1 && y<size2){
            if(L[x] > R[y]){
                nums[k] = R[y];
                k++;
                y++;
            }else{
                nums[k] = L[x];
                x++;
                k++;
            }
        }
         while(x<size1){
                nums[k] = L[x];
                k++;
                x++;
        }
        while(y<size2){
                nums[k] = R[y];
                k++;
                y++;
        }

    }
    void solve(vector<int> &nums,long long s,long long e,int &ans){
        if(s >= e){
            return;
        }
        int mid = s+(e-s)/2;
        solve(nums,s,mid,ans);
        solve(nums,mid+1,e,ans);
        merge(nums,s,mid,e,ans);
    }
    int reversePairs(vector<int>& nums) {
        int ans = 0;
        solve(nums,0,nums.size()-1,ans);
        return ans;
    }
};
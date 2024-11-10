class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int mini = nums[0];
        int maxi = nums[k-1];
        int ans = maxi - mini;
        for(int i = k;i<nums.size();i++){
            int maxi = nums[i];
            int mini = nums[i-k+1];
            if(maxi - mini < ans){
                ans = maxi-mini;
            }
        }
        return ans;
    }
};
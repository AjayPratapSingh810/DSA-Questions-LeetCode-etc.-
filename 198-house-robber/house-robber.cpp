class Solution {
public:
    int solve(vector<int> &nums){
        int size = nums.size();
        vector<int> dp(size,-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2;i<nums.size();i++){
            if(dp[i-1] > dp[i-2]+nums[i]){
                dp[i] = dp[i-1];
            }else{
                dp[i] = dp[i-2]+nums[i];
            }
        }
        return dp[size-1];
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }
        return solve(nums);
    }
};
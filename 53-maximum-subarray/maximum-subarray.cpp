class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int ans = sum;
        for(int i = 1;i<nums.size();i++){
            if(sum + nums[i] > nums[i]){
                sum = sum+nums[i];
            }else{
                sum = nums[i];
            }
            if(sum > ans){
                ans = sum;
            }
        }
        return ans;
    }
};
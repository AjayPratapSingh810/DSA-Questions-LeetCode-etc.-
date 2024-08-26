class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i = 0;
        int j= 0;
        int sum = nums[0];
        int size = nums.size();
        while(j < size){
            if(sum == target){
                if(ans > j-i+1){
                    ans = j-i+1;
                }
                j++;
                sum = sum+nums[j];
            }else if(sum < target){
                if(j < size - 1){
                    j++;
                }else{
                    break;
                }
                sum = sum + nums[j];
            }else{
                if(ans > j-i+1){
                    ans = j-i+1;
                }
                sum = sum - nums[i];
                i++;
            }
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }
};
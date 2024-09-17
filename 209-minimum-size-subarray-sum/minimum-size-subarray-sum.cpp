class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int x = 0;
        int y = 0;
        int sum = nums[0];
        int ans = INT_MAX;
        while(y<nums.size()){
            if(sum == target){
                if(y-x+1 < ans){
                    ans = y-x+1;
                }
                sum = sum+nums[++y];
            }
            else if(sum > target){
                if(ans > y-x+1){
                    ans = y-x+1;
                }
                sum = sum - nums[x];
                x++;
            }else if(sum < target){
                if(y+1 < nums.size()){
                    sum = sum+nums[++y];
                }else{
                    break;
                }
            }
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }
};
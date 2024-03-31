class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int e = nums.size()-1;
        int sum = 0;
        for(int i= e;i>0;i--){
            sum = sum+nums[i];
        }
        int sum2 = 0;
        if(sum == sum2){
            return 0;
        }
        sum2 = sum2+nums[0];
        for(int i =1;i<nums.size();i++){
            sum = sum-nums[i];
            if(sum == sum2){
                return i;
            }
            sum2 = sum2+nums[i];
        }
        return -1;
    }
};
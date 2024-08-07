class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        double ans = 0;
        double sum = 0;
        for(i;i<k;i++){
            sum = sum + nums[i];
        }
        ans = sum/k;
        int s = 0;
        for(i;i<nums.size();i++){
            sum = sum +nums[i] - nums[s++];
            if(sum / k > ans){
                ans = sum/k;
            }
        }
        return ans;
    }
};
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;

        for(int i = 0;i<nums.size();i++){
            int min = INT_MAX;
            int max = INT_MIN;
            for(int j = i;j<nums.size();j++){
                if(nums[j] < min){
                    min = nums[j];
                }
                if(nums[j] > max){
                    max = nums[j];
                }
                ans += max-min;
            }
        }
        return ans;
    }
};
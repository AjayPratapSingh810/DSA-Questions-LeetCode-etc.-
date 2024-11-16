class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            long long product = nums[i];
            if(product < k){
                ans++;
            }else{
                continue;
            }
            for(int j=i+1;j<nums.size();j++){
                product = product*nums[j];
                if(product < k){
                    ans++;
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};
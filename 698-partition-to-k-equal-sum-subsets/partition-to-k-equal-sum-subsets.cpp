class Solution {
public:
    bool backtrack(vector<int> &nums,vector<int> &buckets,int target,int index){
        if(index == nums.size()){
            for(int i = 0;i<buckets.size();i++){
                if(buckets[i] != target){
                    return false;
                }
            }
            return true;
        }

        for(int i=0;i<buckets.size();i++){
            if(buckets[i] + nums[index] > target){
                continue;
            }
            buckets[i] += nums[index];
            if(backtrack(nums,buckets,target,index+1)){
                return true;
            }
            buckets[i] -= nums[index];
            if(buckets[i] == 0) break;
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        if(total_sum % k != 0) {
            return false;
        }

        int targetSum = total_sum / k;
        sort(nums.begin(),nums.end());
        vector<int> buckets(k,0);
        return backtrack(nums,buckets,targetSum,0);
    }
};
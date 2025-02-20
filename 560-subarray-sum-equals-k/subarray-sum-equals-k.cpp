class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum = 0;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
            sum = sum+nums[i];
            int required = sum - k;
            if(mp.find(required) != mp.end()){
                ans += mp[required];
            }
            mp[sum]++;
        }
        return ans;
    }
};
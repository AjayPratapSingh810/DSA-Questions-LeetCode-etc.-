class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        for(int i = 0;i<nums.size();i++){
            sum += nums[i];
            int rem = sum % k;
            if(mp.find(rem) != mp.end() && i - mp[rem] > 1){
                return true;
            }else{
                if(mp.find(rem) == mp.end()){
                    mp[rem] = i;
                }
            }
        }
        return false;
    }
};
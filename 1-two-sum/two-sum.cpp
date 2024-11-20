class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>mp;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int t = target - nums[i];
            if(mp[t] > 0 && mp[t] != i){
                ans.push_back(mp[t]);
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
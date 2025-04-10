class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i= 0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> ans;
        int want = nums.size()/3;
        for(auto i : mp){
            if(i.second > want){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
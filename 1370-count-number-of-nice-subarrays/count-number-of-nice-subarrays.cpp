class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        int size = nums.size();
        vector<int> countOdds(size);
        mp[0]++;
        for(int i=0;i<size;i++){
            if(nums[i] % 2 == 1){
                count++;
            }
            countOdds.push_back(count);
            mp[count]++;
        }
        int ans = 0;
        for (auto it : mp) {
            if (it.first >= k) {
                ans += it.second * mp[it.first - k];
            }
        }
        return ans;
    }
};
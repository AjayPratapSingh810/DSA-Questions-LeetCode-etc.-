class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        set<vector<int>> set; 
        sort(nums.begin(),nums.end());
        for(int i = 0;i<nums.size()-2;i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){
                if(nums[i] + nums[j] + nums[k] == 0){
                   set.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }else if(nums[i]+nums[j]+nums[k] > 0){
                    k--;
                }else{
                    j++;
                }
            }
        }
        for(auto it : set){
            ans.push_back(it);
        }
        return ans;
    }
};
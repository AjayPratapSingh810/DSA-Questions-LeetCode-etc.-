class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(),nums.end());
        set<vector<int>> set; 
        for(int i = 0;i<nums.size()-2;i++){
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            int s = i+1;
            int e = nums.size()-1;
            while(s<e){
                int sum = nums[i];
                int a = nums[s];
                int b = nums[e];
                sum = sum +a + b;
                if(sum == 0){
                    set.insert({nums[i],nums[s],nums[e]});
                    s++;
                    e--;
                }else if(sum < 0){
                    s++;
                }else{
                    e--;
                }

            }
        }
        for(auto it : set){
            ans.push_back(it);
        }
        return ans;
    }
};
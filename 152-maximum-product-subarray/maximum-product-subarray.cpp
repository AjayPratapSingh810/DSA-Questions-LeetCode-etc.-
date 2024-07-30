class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double ans = LLONG_MIN;
        double production = 1;
        for (int i = 0; i < nums.size(); i++) {
            production = production* nums[i];
            ans = max(ans,production);
            if(production == 0){
                production = 1;
            }
        }
        production = 1;
        for (int i = nums.size()-1; i >=0 ; i--) {
            production = production* nums[i];
            ans = max(ans,production);
            if(production == 0){
                production = 1;
            }
        }
        return ans;
    }
};
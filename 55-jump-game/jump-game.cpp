class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int lastIndex = 0;
        while (i <= lastIndex) {
            if (i == nums.size() - 1) {
                return true;
            }
            else if (nums[i] == 0 && i == lastIndex) {
                return false;
            }
            else if(i+nums[i] > lastIndex){
                lastIndex = i + nums[i];
            }
                i++;
        }
        return true;
    }
};
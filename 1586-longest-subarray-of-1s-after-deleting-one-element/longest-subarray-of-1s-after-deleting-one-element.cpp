class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int a = 0;
        int count = 0;
        int ans = 0;
        int i = 0;
        while (i < nums.size()) {
            if (a == 1 && nums[i] == 0) {
                break;
            }
            else if (nums[i] == 0) {
                a++;
            } else {
                count++;
            }
            i++;
        }
        if (a == 0) {
            return count - 1;
        }
        if (count > ans) {
            ans = count;
        }

        while (i < nums.size()) {
            if (nums[i] == 0) {
                while (nums[i - count - 1] != 0) {
                    count--;
                }
                i++;
            } else {
                count++;
                i++;
                if (count > ans) {
                    ans = count;
                }
            }
        }
        return ans;
    }
};
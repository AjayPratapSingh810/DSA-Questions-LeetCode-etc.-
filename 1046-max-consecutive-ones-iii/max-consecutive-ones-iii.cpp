class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int zeros = 0;  // Count of zeros in the current window
        int ans = 0;    // Stores the length of the longest window

        while (j < nums.size()) {
            if (nums[j] == 0) {
                zeros++;
            }

            while (zeros > k) {
                if (nums[i] == 0) {
                    zeros--;
                }
                i++;  // Shrink the window
            }

            ans = max(ans, j - i + 1);  // Update the max length of the window
            j++;  // Expand the window
        }

        return ans;
    }
};

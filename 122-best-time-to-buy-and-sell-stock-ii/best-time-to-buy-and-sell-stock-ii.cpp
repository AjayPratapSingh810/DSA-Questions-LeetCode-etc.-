class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int max = INT_MIN;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min) {
                if (max != INT_MIN) {
                    ans = ans + max - min;
                }
                min = prices[i];
                max = INT_MIN;
            } else if (prices[i] > min && prices[i] > max) {
                max = prices[i];
            } else if (prices[i] < max) {
                ans = ans + max - min;
                min = prices[i];
                max = INT_MIN;
            }
        }
        if (max != INT_MIN) {
            ans = ans + max - min;
        }
        return ans;
    }
};
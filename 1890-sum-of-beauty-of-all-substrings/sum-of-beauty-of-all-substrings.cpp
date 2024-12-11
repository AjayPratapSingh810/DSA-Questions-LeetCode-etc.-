class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            string st = "";
            unordered_map<char, int> mp;
            for (int j = i; j < s.length(); j++) {
                mp[s[j]]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for (auto k : mp) {
                    if (k.second > maxi) {
                        maxi = k.second;
                    }
                    if (k.second < mini) {
                        mini = k.second;
                    }
                }
                ans += maxi-mini;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            unordered_map<char, bool> mp;
            int count = 0;
            for (int j = i; j < s.length(); j++) {
                if (mp[s[j]] == true) {
                    break;
                } else {
                    mp[s[j]] = true;
                    count++;
                    if (count > ans) {
                        ans = count;
                    }
                }
            }
        }
        return ans;
    }
};
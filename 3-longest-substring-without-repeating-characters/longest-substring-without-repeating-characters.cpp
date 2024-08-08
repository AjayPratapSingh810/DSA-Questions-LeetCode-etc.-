class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans = 0;
        int i = 0;
        int j = 0;
        while(j<s.length()){
            if(mp[s[j]] > 0){
                mp[s[i]]--;
                i++;
            }else{
                mp[s[j]]++;
                if(j-i+1 > ans){
                    ans = j-i+1;
                }
                j++;

            }
        }
        return ans;
    }
};
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        while(j < s.length()){
            mp[s[j]]++;
            int maxi = 0;
            for(auto k : mp){
                if(k.second > maxi){
                    maxi = k.second;
                }
            }
            while(j-i+1 -maxi > k){
                mp[s[i]]--;
                if(mp[s[i]] == 0){
                    mp.erase(s[i]);
                }
                for(auto k : mp){
                    if(k.second > maxi){
                        maxi = k.second;
                    }
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
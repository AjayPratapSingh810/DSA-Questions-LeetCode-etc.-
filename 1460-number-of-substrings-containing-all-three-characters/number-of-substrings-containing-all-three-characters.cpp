class Solution {
public:
    int numberOfSubstrings(string s) {
        int i =0;
        int j =-1;
        int size = s.length();
        unordered_map<char,int> mp;
        int ans = 0;
        while(j < size){
            while(j < size && !(mp['a'] > 0 && mp['b'] > 0 && mp['c']> 0)){
                j++;
                mp[s[j]]++;
            }
            if(mp['a'] > 0 && mp['b']> 0 && mp['c']>0){
                ans = ans + size - j;
                if(j == size){
                    ans++;
                }
            }
            mp[s[i]]--;
            i++;
        }
        return ans;
    }
};
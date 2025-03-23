class Solution {
public:
    int countBinarySubstrings(string s) {
        int i = 0;
        int n = s.length();
        unordered_map<char,int> mp;
        mp['0'] = 0;
        mp['1'] = 0;
        int ans = 0;
        while(i < n){
            if(s[i] == '0'){
                mp['0'] = 0;
                while(i<n && s[i] == '0'){
                    i++;
                    mp['0']++;
                }
            }else{
                mp['1'] = 0;
                while(s[i] == '1'){
                    i++;
                    mp['1']++;
                }
            }
            if(mp['0'] > 0 && mp['1'] > 0){
                ans += min(mp['0'],mp['1']);
            }
        }
        return ans;
    }
};
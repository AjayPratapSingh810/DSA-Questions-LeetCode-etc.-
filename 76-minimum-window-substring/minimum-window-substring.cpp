class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<t.length();i++){
            mp1[t[i]]++;
        }
        int required = mp1.size();
        int formed = 0;
        int i = 0;
        int j = 0;
        string ans = "";
        int minLen = INT_MAX;
        int startIdx = 0;
        while(i<s.length()){
            if(mp1.count(s[i])){
                mp2[s[i]]++;
                if(mp2[s[i]] == mp1[s[i]]){
                    formed++;
                }
            }
            while(formed == required){
                if(i - j + 1 < minLen) {  // Found smaller valid window
                    minLen = i - j + 1;
                    startIdx = j;
                }
                if(mp1.count(s[j])){
                    mp2[s[j]]--;
                    if(mp2[s[j]] < mp1[s[j]]){
                        formed--;
                    }
                }
                j++;
            }
            i++;
        }
        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
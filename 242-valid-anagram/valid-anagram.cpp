class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> track(26,0);
        for(int i = 0;i<s.length();i++){
            int a = s[i] - 'a';
            track[a]++;
        }
         vector<int> track2(26,0);
        for(int i = 0;i<t.length();i++){
            int a = t[i] - 'a';
            track2[a]++;
        }
        if(track == track2){
            return true;
        }
        return false;
    }
};
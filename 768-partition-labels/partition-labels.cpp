class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]] = i;
        }

        int i = 0;
        int lastIndex = mp[s[0]];
        vector<int> ans;
        while(i < s.length() && lastIndex < s.length()){
            int j = lastIndex-1;
            bool happn = true;
            while(j > i){
                if(mp[s[j]] > lastIndex){
                    lastIndex = mp[s[j]];
                    happn = false;
                }
                j--;
            }
            if(happn){
                ans.push_back(lastIndex-i+1);
                i = lastIndex+1;
                if(i < s.length()){
                    lastIndex = mp[s[i]];
                }
            }
        }
        return ans;
    }
};
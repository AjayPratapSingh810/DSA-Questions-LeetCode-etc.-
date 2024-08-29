class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int size = s.length();
        unordered_map<string,int> mp;
        for(int i = 0;i<=size-10;i++){
            string a = s.substr(i,10);
            mp[a]++;
        }
        vector<string> ans;
        for(auto i : mp){
            if(i.second > 1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length() < k){
            return false;
        }
        unordered_map<string,bool> mp;
        for(int i = 0;i<=s.length()-k;i++){
            string st = s.substr(i,k);
            mp[st] = true;
            
        }
        if(mp.size() >= pow(2,k)){
            return true;
        }
        return false;
    }
};
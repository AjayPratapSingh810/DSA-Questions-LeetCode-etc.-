class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp1;
        for(int i=0;i<magazine.length();i++){
            mp1[magazine[i]]++;
        }

        for(int i=0;i<ransomNote.size();i++){
            if(mp1[ransomNote[i]] == 0){
                return  false;
            }else{
                mp1[ransomNote[i]]--;
            }
        }
        return true;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.length()-1;
        int ans = 0;
        while(index>=0 && !((s[index] >= 'a' && s[index] <= 'z')||(s[index] >= 'A' && s[index] <= 'Z'))){
            index--;
        }
        while(index >= 0 && ((s[index] >= 'a' && s[index] <= 'z')||(s[index] >= 'A' && s[index] <= 'Z'))){
            ans ++;
            index--;
        }
        return ans;
    }
};
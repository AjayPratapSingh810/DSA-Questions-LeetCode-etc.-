class Solution {
public:
    bool checkPallindrome(string& s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0;i<s.length()-1;i++){
            int start = i;
            int end = s.length()-1;
            while(start<end){
                bool check = checkPallindrome(s,start,end);
                if(check){
                    if(ans.length() < end-start+1){
                        ans = s.substr(start, end-start+1);
                    }
                    break;
                }else{
                    end--;
                }
            }
        }
        if(ans.length() == 0){
            ans.push_back(s[0]);
        }
        return ans;
    }
};
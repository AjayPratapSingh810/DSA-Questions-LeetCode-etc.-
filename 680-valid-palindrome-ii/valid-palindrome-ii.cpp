class Solution {
public:
     bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        bool del = false;

        while(i <= j){
            if(s[i] != s[j]){
                if(!del){
                    if(s[i] == s[j-1]){
                        bool first = isPalindrome(s,i,j-1);
                        if(first){
                            return true;
                        }
                    }if(s[i+1] == s[j]){
                        bool second = isPalindrome(s,i+1,j);
                        if(second){
                            return true;
                        }
                    }
                        return false;
                    
                }else{
                    return false;
                }
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
};
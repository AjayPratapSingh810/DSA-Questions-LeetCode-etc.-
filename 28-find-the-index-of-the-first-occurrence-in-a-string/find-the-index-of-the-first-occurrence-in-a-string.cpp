class Solution {
public:
    int strStr(string haystack, string needle) {
        int s = 0;
        int size = needle.length()-1;
        while(s+size < haystack.size()){
            int i = s;
            string check = "";
            while(i <= s+size){
                check.push_back(haystack[i]);
                i++;
            }
            if(check == needle){
                return s;
            }
            s++;
        }
        return -1;
    }
};
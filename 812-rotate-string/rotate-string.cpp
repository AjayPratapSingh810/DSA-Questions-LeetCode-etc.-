class Solution {
public:
    bool rotateString(string s, string goal) {
        string a = s;
        for(int i =0;i<s.length();i++){
            int x =0;
            for(int k = i;k<s.length();k++){
                a[x++] = s[k];
            }
            for(int j = 0;j<i;j++){
                a[x++] = s[j];
            }
            if(a == goal){
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }
        string ans = "";
        int i = 0;
        while (i < s.length()) {
            ans.push_back(s[i]);
            i = i + (numRows - 1) * 2;
        }
        for (int j = 1; j < numRows - 1; j++) {
            i = j;
            while (i < s.length()) {
                int k = i;
                ans.push_back(s[k]);
                k = i + (numRows - 1) * 2 - 2 * (j);
                if(k < s.length()){
                    ans.push_back(s[k]);
                }
                i = i + (numRows - 1) * 2;
            }
        }
        i = numRows - 1;
        while (i < s.length()) {
            ans.push_back(s[i]);
            i = i + (numRows - 1) * 2;
        }
        return ans;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
        for(int i=1;i<strs.size();i++){
            int x = 0;
            int y = 0;
            while(x< ans.length() && y < strs[i].length()){
                if(ans[x] == strs[i][y]){
                    x++;
                    y++;
                }else{
                    break;
                }
            }
            ans = ans.substr(0,x);
        }
        return ans;
    }
};
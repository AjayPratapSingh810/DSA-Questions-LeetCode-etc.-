class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for(int i = 1;i<strs.size();i++){
            string checker = ans;
            ans = "";
            int a = 0;
            int b = checker.length()-1;
            while(a <= b){
                if(strs[i][a] == checker[a]){
                    ans.push_back(checker[a]);
                    a++;
                }else{
                    break;
                }
            }
        }
        return ans;
    }
};
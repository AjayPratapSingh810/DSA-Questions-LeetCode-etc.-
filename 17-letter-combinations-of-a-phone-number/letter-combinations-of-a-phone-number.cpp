class Solution {
public:
    void solve(int x,string digits,vector<string> &track,vector<string> &ans,string str){
        if(x >=  digits.size()){
            ans.push_back(str);
            return;
        }
        int d = digits[x] - '0';
        for(int i = 0;i<track[d].size();i++){
            str = str + track[d][i];
            solve(x+1,digits,track,ans,str);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0){
            return ans;
        }
        vector<string> track(10);
        track[0]="";
        track[1] = "";
        track[2] = "abc";
        track[3] = "def";
        track[4] = "ghi";
        track[5] = "jkl";
        track[6] = "mno";
        track[7] = "pqrs";
        track[8] = "tuv";
        track[9] = "wxyz";

        solve(0,digits,track,ans,"");
        return ans;
    }
};
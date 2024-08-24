class Solution {
public:
    void func(string s,int lc,int rc,vector<string> &ans){
        if(lc == 0 && rc == 0){
            ans.push_back(s);
            return;
        }
        if(lc == rc){
            func(s+'(',lc-1,rc,ans);
        }else if(lc < rc){
            if(rc > 0){
                func(s+')',lc,rc-1,ans);
            }
            if(lc > 0){
                func(s+'(',lc-1,rc,ans);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        int lc = n;
        int rc = n;
        vector<string> ans;
        func("",lc,rc,ans);
        return ans;
    }
};
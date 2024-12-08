class Solution {
public:
    void solve(int n , vector<string> &ans,string s,int l,int r){
        if(l == n && r == n){
            ans.push_back(s);
            return;
        }
        if(l < n){
            s.push_back('(');
            solve(n,ans,s,l+1,r);
            s.pop_back();
        }
        if(!s.empty() && r < n){
            s.push_back(')');
            solve(n,ans,s,l,r+1);
            s.pop_back();
        }
        return;

    }
    bool valid(string s){
        stack<char> st;
        for(int i = 0;i<s.length();i++){
            if(s[i] == '('){
                st.push('(');
            }else if(s[i] == ')'){
                if(st.empty()){
                    return false;
                }
                st.pop();
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n,ans,"",0,0);
        vector<string> arr;
        for(int i = 0;i<ans.size();i++){
            bool check = valid(ans[i]);
            if(check){
                arr.push_back(ans[i]);
            }
        }
        return arr;
    }
};
class Solution {
public:
    string removeStars(string s) {
        stack<char> st;

        for(int i=0;i<s.length();i++){
            if(s[i] == '*'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        string finalAns="";
        for(int i = ans.length()-1;i>=0;i--){
            finalAns.push_back(ans[i]);
        }
        return finalAns;
    }
};
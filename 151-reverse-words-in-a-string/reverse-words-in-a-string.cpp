class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        for(int i = 0;i<s.length();i++){
            st.push(s[i]);
        }
        string a = "";
        string ans = "";
        while(!st.empty() && st.top() == ' '){
            st.pop();
        }
        while(!st.empty()){
            char top = st.top();
            st.pop();
            if(top == ' ' && a.length() > 0){
                reverse(a.begin(),a.end());
                if(ans.length() > 0){
                    ans = ans + " ";
                }
                ans = ans+a;
                a = "";
            }else if(top != ' '){
                a.push_back(top);
            }
        }
        if(a.length() >= 1){
            if(ans.length() > 0){
                    ans = ans + " ";
                }
            reverse(a.begin(),a.end());
            ans = ans+a;
        }
        return ans;
    }
};
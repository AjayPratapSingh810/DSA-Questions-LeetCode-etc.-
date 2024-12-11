class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans = "";
        int i = 0;
        string a = "";
        while(i<s.length()){
            if((s[i] >= 'a' && s[i] <= 'z')||(s[i] >= 'A' && s[i] <= 'Z') || (s[i]>='0' && s[i] <= '9')){
                a.push_back(s[i]);
            }
            else if(s[i] == ' ' && a.length() > 0){
                st.push(a);
                a = "";
            }
            i++;
        }
        if(a.length() > 0){
            st.push(a);
        }
        while(!st.empty()){
            string top = st.top();
            ans = ans+top;
            st.pop();
            if(!st.empty()){
                ans = ans+' ';
            }
        }
        return ans;
    }
};
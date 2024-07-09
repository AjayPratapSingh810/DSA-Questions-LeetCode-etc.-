class Solution {
public:
    string simplifyPath(string path) {
        string curr = "";
        stack<string> st;
        for (int i = 0; i <= path.length(); i++) {
           if (i == path.length() || path[i] == '/') {
                if (curr == "..") {
                    if (!st.empty()) st.pop();
                } else if (curr != "" && curr != ".") {
                    st.push(curr);
                }
                curr = "";
            } else {
                curr += path[i];
            }
        }
        string ans = "";
        while (!st.empty()) {
            string top = st.top();
            st.pop();
            if (top != "") {
                ans = top + ans;
                ans = '/' + ans;
            }
        }
        if (ans == "") {
            return "/";
        }
        return ans;
    }
};
class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        string ans = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == ']'){
                string taken = "";
                while(st.top() != '['){
                    taken = st.top()+taken;
                    st.pop();
                }
                st.pop();
                string num = "";
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    num = st.top()+num;
                    st.pop();
                }
                int n = stoi(num);
                string track = "";
                while(n){
                    track = track+taken;
                    n--;
                }
                for (int i = 0; i < track.length(); i++) {
                    st.push(track[i]);
                }
                track = "";
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};
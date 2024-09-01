class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int> > st;
        st.push({s[0],1});
        for(int i =1;i<s.length();i++){
            if(!st.empty() && st.top().first == s[i]){
                pair<char,int> p = st.top();
                st.pop();
                p.second += 1;
                if(p.second < k){
                    st.push(p);
                }
            }else{
                st.push({s[i],1});
            }
        }
        string ans = "";
        while(!st.empty()){
            pair<char,int> p = st.top();
            st.pop();
            int num = p.second;
            while(num){
                ans.push_back(p.first);
                num--;
            }
        }
        int i = ans.length()-1;
        string answer = "";
        while(i>=0){
            answer.push_back(ans[i]);
            i--;
        }
        return answer;
    }
};
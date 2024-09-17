class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char,int>> st;
        stack<pair<char,int>> star;

        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(make_pair('(',i));
            }else if(s[i] == '*'){
                star.push(make_pair('*',i));
            }else{
                if(st.empty() && star.empty()){
                    return false;
                }
                if(!st.empty()){
                    st.pop();
                }else{
                    star.pop();
                }
                
            }
        }
        while(!st.empty()){
            if(star.empty()){
                return false;
            }
            pair<char,int> p = star.top();
            if(p.second < st.top().second){
                return false;
            }else{
                st.pop();star.pop();
            }
        }
        return true;

    }
};
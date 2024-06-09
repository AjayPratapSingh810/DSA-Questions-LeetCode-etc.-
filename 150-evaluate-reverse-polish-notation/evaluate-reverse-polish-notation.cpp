class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i=0;i<tokens.size();i++){
            string a = tokens[i];
            if(a == "*" || a=="/" || a=="+" || a=="-"){
                if(a == "*"){
                    int top1 = st.top();
                    st.pop();
                    int top2 = st.top();
                    st.pop();
                    int ans = top1*top2;
                    st.push(ans);
                }
                else if(a == "+"){
                    int top1 = st.top();
                    st.pop();
                    int top2 = st.top();
                    st.pop();
                    int ans = top1+top2;
                    st.push(ans);
                }
                else if(a == "-"){
                    int top1 = st.top();
                    st.pop();
                    int top2 = st.top();
                    st.pop();
                    int ans = top2-top1;
                    st.push(ans);
                } else if(a == "/"){
                    int top1 = st.top();
                    st.pop();
                    int top2 = st.top();
                    st.pop();
                    int ans = top2/top1;
                    st.push(ans);
                }
            }else{
                int num = 0;
                int z = 0;
                bool neg = false;
                for(int j = a.length()-1;j>=0;j--){
                    if(a[j] == '-'){
                        neg = true;
                        break;
                    }
                    num = num + (pow(10,z)*(a[j]-'0'));
                    z++;
                }
                if(neg){
                    num = 0-num;
                }
                st.push(num);
            }
        }
        return st.top();
    }
};
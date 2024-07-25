class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1;
        int j = b.length()-1;
        stack<char> st; 
        char carry = '0';
        while(i>=0 && j>=0){
            char x = a[i];
            char y = b[j];
            if(x == '1' && y == '1'){
                if(carry == '1'){
                    st.push('1');
                    carry = '1';
                }else{
                    st.push('0');
                    carry = '1';
                }
            }else if(x == '1' && y == '0'){
                if(carry == '1'){
                    st.push('0');
                    carry = '1';
                }else{
                    st.push('1');
                    carry = '0';
                }
            }else if(x == '0' && y == '1'){
                if(carry == '1'){
                    st.push('0');
                    carry = '1';
                }else{
                    st.push('1');
                    carry = '0';
                }
            }else{
                if(carry == '1'){
                    st.push('1');
                    carry = '0';
                }else{
                    st.push('0');
                    carry = '0';
                }
            }
            i--;
            j--;
        }

        while(i>=0){
            char x = a[i];
            if(x == '0'){
                if(carry == '1'){
                    st.push('1');
                    carry = '0';
                }else{
                    st.push('0');
                    carry = '0';
                }
            }else{
                 if(carry == '1'){
                    st.push('0');
                    carry = '1';
                }else{
                    st.push('1');
                    carry = '0';
                }
            }
            i--;
        }
        while(j>=0){
            char y = b[j];
            if(y == '0'){
                if(carry == '1'){
                    st.push('1');
                    carry = '0';
                }else{
                    st.push('0');
                    carry = '0';
                }
            }else{
                 if(carry == '1'){
                    st.push('0');
                    carry = '1';
                }else{
                    st.push('1');
                    carry = '0';
                }
            }
            j--;
        }
        if(carry == '1'){
            st.push('1');
        }
        string ans = "";
        while(!st.empty()){
            char top = st.top();
            st.pop();
            ans = ans+top;
        }
        return ans;

    }
};
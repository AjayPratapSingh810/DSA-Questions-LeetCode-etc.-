class Solution {
public:
    int myAtoi(string s) {
        if(s.length() == 0){
            return 0;
        }
        long long ans = 0;
        int i = 0;
        while(s[i] == ' '){
            i++;
        }
        bool neg = false;
        if(s[i] == '-'){
            neg = true;
            i++;
        }else if(s[i] == '+'){
            i++;
        }
        while(i<s.length()){
            if(s[i] >= '0' && s[i] <= '9'){
                int ch = s[i] - '0';
                ans = ans*10 + ch;
            }else{
                break;
            }
            if(ans > INT_MAX){
                if(neg){
                    return INT_MIN;
                }
                return INT_MAX;
            }
            i++;
        }
        if(ans > INT_MAX){
            if(neg){
                return INT_MIN;
            }
            return INT_MAX;
        }
        if(neg){
            return -ans;
        }
        return ans;
    }
};
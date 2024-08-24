class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        long long ans = 0;
        for (i; i < s.length(); i++) {
            if (s[i] == ' ') {
                continue;
            } else {
                break;
            }
        }
        bool neg = false;
        if (s[i] == '-') {
            neg = true;
            i++;
        }
        if (s[i] == '+') {
            if (neg == true) {
                return 0;
            }
            i++;
        }
        for (i; i < s.length(); i++) {
            if (s[i] != '0') {
                break;
            }
        }
        for (i; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                int a = s[i] - '0';
                ans = ans * 10 + a;
            } else {
                break;
            }
            if (ans > INT_MAX) {
                if(neg){
                    return INT_MIN;
                }
                return INT_MAX;
            }
        }

        if (neg) {
            ans = 0 - ans;
        }

        return ans;
    }
};
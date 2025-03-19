class Solution {
public:
    string addStrings(string num1, string num2) {
        string result = "";
        int carry = 0;
        int i = num1.size() - 1, j = num2.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0)
                sum += num1[i--] - '0';
            if (j >= 0)
                sum += num2[j--] - '0';

            result = (char)(sum % 10 + '0') + result;
            carry = sum / 10;
        }
        return result;
    }
    string multiply(string num1, string num2) {
        vector<string> ans;
        for (int i = num2.size() - 1; i >= 0; i--) {
            int pro = 0;
            int carry = 0;
            string str = "";
            for (int j = num1.size() - 1; j >= 0; j--) {
                int a = num1[j] - '0';
                int b = num2[i] - '0';
                int product = (a * b + carry);
                carry = product / 10;
                str = (char)(product % 10 + '0') + str;
            }
            if (carry) {
                str = (char)(carry + '0') + str;
            }
            str.append(num2.size() - 1 - i, '0');
            ans.push_back(str);
        }
        string result = "0";
        for (const string& s : ans) {
            result = addStrings(result, s);
        }
        if(result[0] == '0'){
            return "0";
        }
        return result;
    }
};
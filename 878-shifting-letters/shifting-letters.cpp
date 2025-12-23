class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum = (sum + shifts[i]) % 26;
        }

        for (int i = 0; i < s.length(); i++) {
            int a = s[i] - 'a';
            a = (a + sum) % 26;
            s[i] = a + 'a';

            sum = (sum - shifts[i] % 26 + 26) % 26;
        }

        return s;
    }
};

class Solution {
public:
    void solve(string word, unordered_set<string>& st, int step,
               queue<pair<string, int>>& q) {

        for (int i = 0; i < word.length(); i++) {
            for (int i = 0; i < word.length(); i++) {
                char originalChar = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == originalChar)
                        continue;

                    word[i] = ch;

                    if (st.find(word) != st.end()) {
                        q.push(make_pair(word, step + 1));
                        st.erase(word);
                    }
                }
                word[i] = originalChar;
            }
        }
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st;
        for (int i = 0; i < wordList.size(); i++) {
            st.insert(wordList[i]);
        }
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        int ans = INT_MAX;
        while (!q.empty()) {
            pair<string, int> p = q.front();
            q.pop();
            if (p.first == endWord) {
                if (ans > p.second) {
                    ans = p.second;
                }
            }
            solve(p.first, st, p.second, q);
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};
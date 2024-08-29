class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        if(s.length() < k || s.length() == 0 || s.length() < k){
            return 0;
        }
        for(int i = 0;i<=s.length()-k;i++){
            string track = "";
            vector<int> visit(26,0);
            for(int j = i;j<s.length();j++){
                int a = s[j]-'a';
                visit[a]++;
                bool ok = true;
                for(int l = 0;l<26;l++){
                    if(visit[l] < k && visit[l] > 0){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    if(ans < j-i+1){
                        ans = j-i+1;
                    }
                }
            }
        }
        return ans;
    }
};
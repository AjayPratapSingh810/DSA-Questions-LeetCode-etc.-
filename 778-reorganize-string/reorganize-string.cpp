class Solution {
public:
    string reorganizeString(string s) {
        vector<int> track(26,0);
        for(int i=0;i<s.length();i++){
            int a = s[i] - 'a';
            track[a]++;
        }

        string ans = "";
        while(ans.length() != s.length()){
            int max = 0;
            int maxI = -1;
            int size = ans.length();
            for(int j = 0;j<26;j++){
                if(track[j] > max && (size == 0 || ans[size-1] != 'a'+j)){
                    maxI = j;
                    max = track[j];
                }
            }
            if(max == 0){
                return "";
            }else{
                track[maxI]--;
                char a = 'a'+maxI;
                ans.push_back(a);
            }
        }
        return ans;
    }
};
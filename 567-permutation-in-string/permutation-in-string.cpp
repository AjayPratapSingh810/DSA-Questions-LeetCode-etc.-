class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        vector<int> present(26,0);
        vector<int> check(26,0);

        for(int i= 0;i<s1.length();i++){
            int x = s1[i]-'a';
            present[x]++;
        }
        int s = 0;
        int e = 0;

        while(e<s1.length()){
            int x = s2[e]-'a';
            check[x]++;
            e++;
        }
        if(check == present){
            return true;
        }
        while(e < s2.length()){
            int a = s2[e]-'a';
            int b = s2[s]-'a';
            check[a]++;
            check[b]--;
            s++;
            e++;
            if(check == present){
                return true;
            }
        }
        return false;
    }
};
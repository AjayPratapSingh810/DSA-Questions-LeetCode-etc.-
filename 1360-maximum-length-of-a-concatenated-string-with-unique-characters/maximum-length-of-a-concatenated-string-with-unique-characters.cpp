class Solution {
public:
    void solve(int x,vector<string>& arr,int& ans,string s){
        if(x == arr.size()){
            ans = max(ans, (int)s.length());
            return;
        }

        // not include
        solve(x+1,arr,ans,s);

        // include
        vector<bool> present(26,false);
        for(int i=0;i<s.length();i++){
            int a = s[i]-'a';
            present[a] = true;
        }
        bool ok = true;
        for(int i=0;i<arr[x].length();i++){
            int a = arr[x][i]-'a';
            if(present[a] == true){
                ok = false;
                break;
            }
            present[a] = true;
        }
        if(ok){
            s = s+arr[x];
            solve(x+1,arr,ans,s);
        }
    }
    int maxLength(vector<string>& arr) {
        int ans = 0;
        solve(0,arr,ans,"");
        return ans;
    }
};
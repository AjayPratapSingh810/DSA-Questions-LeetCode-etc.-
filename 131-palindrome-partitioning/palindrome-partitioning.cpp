class Solution {
public:
    void solve(int x,vector<vector<string> > &ans,vector<string> arr,string s){
        if(x >= s.length()){
            return;
        }
        string str = "";
        for(int i= x;i<s.length();i++){
            str.push_back(s[i]);
            bool palindrome = true;
            int m = 0;
            int n = str.length()-1;
            while(m<n){
                if(str[m] != str[n]){
                    palindrome = false;
                }
                m++;
                n--;
            }
            if(palindrome){
                arr.push_back(str);
                if(i == s.length()-1){
                    ans.push_back(arr);
                }
                solve(i+1,ans,arr,s);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> arr;
        solve(0,ans,arr,s);
        return ans;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> st;

        for(int i = 0;i<nums.size();i++){
            st.push_back(to_string(nums[i]));
        }
        auto compare = [](const string &s1, const string &s2){
            return s1+s2 > s2+s1;
        };
        sort(st.begin(),st.end(),compare);

        string ans = "";

        for(int i=0;i<st.size();i++){
            ans += st[i];
        }
        if(ans[0] == '0'){
            return "0";
        }
        return ans;
    }
};
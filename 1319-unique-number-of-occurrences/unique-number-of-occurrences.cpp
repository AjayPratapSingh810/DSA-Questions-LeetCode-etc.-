class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        set<int> st;
        for(auto i : mp){
            int a = mp[i.first];
            st.insert(a);
        }
        if(st.size() == mp.size()){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0;i<s.length();i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i : mp){
            pair<int,char> p;
            p.first = i.second;
            p.second = i.first;
            pq.push(p);
        }
        string ans = "";
        while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();
            int times = p.first;
            char ch = p.second;
            for(int i = 0;i<times;i++){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
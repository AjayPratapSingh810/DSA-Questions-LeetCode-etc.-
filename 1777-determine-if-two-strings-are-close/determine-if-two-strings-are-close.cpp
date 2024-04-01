class Solution {
public:
    bool closeStrings(string word1, string word2) {
        priority_queue<int> pq;
        priority_queue<int> pq1;
        
        unordered_set<char> ch;
        unordered_set<char> ch1;

        unordered_map<char,int> mp;
        unordered_map<char,int> mp2;

        for(int i=0;i<word1.length();i++){
            mp[word1[i]]++;
        }
        for(int i=0;i<word2.length();i++){
            mp2[word2[i]]++;
        }

        for(auto i : mp){
            pq.push(i.second);
            ch.insert(i.first);
        }
        for(auto i : mp2){
            pq1.push(i.second);
            ch1.insert(i.first);
        }
        while(!pq.empty() && !pq1.empty()){
            if(pq.top() != pq1.top()){
                return false;
            }
            pq.pop();
            pq1.pop();
        }
        if(!pq.empty() || !pq.empty()){
            return false;
        }
        if(ch == ch1){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<string,bool> mp;
        for(int i=0;i<deadends.size();i++){
            mp[deadends[i]] = true;
        }

        queue<pair<string,int>> q;
        q.push(make_pair("0000",0));
        unordered_map<string,bool> visited;
        visited["0000"] = true;
        int ans = INT_MAX;

        while(!q.empty()){
            pair<string,int> p = q.front();
            q.pop();
            string s = p.first;
            int step = p.second;
            if(s == target){
                if(step < ans){
                    ans = step;
                }
            }
            if(mp[s] == true){
                continue;
            }
            // first wheel
            for(int i = 0;i<4;i++){
                char ch = s[i];
                int a = ch - '0';
                int frwd = (a+1)%10;
                char f = '0'+frwd;
                string st1 = s;
                st1[i] = f;
                if(!visited[st1]){
                    visited[st1] = true;
                    q.push(make_pair(st1,step+1));
                }
                int bkwd = a-1;
                if(a == 0){
                    bkwd = 9;
                }
                char b = '0'+bkwd;
                string st2 = s;
                st2[i] = b;
                if(!visited[st2]){
                    visited[st2] = true;
                    q.push(make_pair(st2,step+1));
                }
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};
#include <set>
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > q;
        map<int,int> mp;
        multiset<int, greater<int> > ms;
        vector<int> track;
        for(int i=0;i<nums.size();i++){
            int num = nums[i];
            
            int find = 0;
            int c = 0;
            if(num == 0){
             find = mapping[0];   
            }
            while(num){
                int x = num%10;
                num = num/10;
                x = mapping[x];
                find = x*pow(10,c)+find;
                c++; 
            }
             q.push(make_pair(find,i));
        }

        vector<int> ans;
        while(!q.empty()){
            pair<int,int> front = q.top();
            q.pop();
            int a = front.second;
            ans.push_back(nums[a]);
        }
        return ans;
    }
};
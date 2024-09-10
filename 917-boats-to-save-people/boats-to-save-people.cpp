class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans = 0;
        int s = 0;
        int e = people.size()-1;

        while(s<=e){
            if(people[s]+people[e] <= limit){
                ans++;
                s++;
                e--;
            }else if(people[s]+people[e] > limit){
                ans++;
                e--;
            }
        }
        return ans;
    }
};
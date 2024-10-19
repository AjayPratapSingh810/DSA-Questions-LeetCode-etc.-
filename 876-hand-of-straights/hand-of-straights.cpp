class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0){
            return false;
        }
        priority_queue <int, vector<int>, greater<int> > pq;
        unordered_map<int,int> mp;

        for(int i=0;i<hand.size();i++){
            pq.push(hand[i]);
            mp[hand[i]]++;
        }
        int x = 0;
        while(true){
            int top = pq.top();
            pq.pop();
            if(mp[top] > 0){
                int a = top;
                int count = groupSize;
                while(count){
                    if(mp[a] > 0){
                        mp[a]--;
                        a++;
                        count--;
                    }else{
                        return false;
                    }
                }
            }
            bool happn = false;
            for(auto i : mp){
                if(i.second > 0){
                    happn = true;
                }
            }
            if(!happn){
                return true;
            }

        }
        return true;
    }
};
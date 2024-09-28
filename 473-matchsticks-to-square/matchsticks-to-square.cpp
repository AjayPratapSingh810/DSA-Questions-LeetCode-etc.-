class Solution {
public:
    bool solve(int startIndex,vector<long long> &current,vector<int> &matchsticks,long long side){
        if(startIndex == matchsticks.size()){
            return current[0] == side && current[1] == side && current[2] == side && current[3] == side;
        }

        int curr = matchsticks[startIndex];
        for(int i=0;i<4;i++){
            if(current[i] + curr <= side){
                current[i] += curr;
                if(solve(startIndex+1,current,matchsticks,side)){
                    return true;
                }
                current[i] -= curr;
            }
            if(current[i] == 0){
                break;
            }
        }
        return false;

    } 
    bool makesquare(vector<int>& matchsticks) {
        long long sum = 0;
        for (int i = 0; i < matchsticks.size(); i++) {
            sum = sum + matchsticks[i];
        }
        if(sum % 4 != 0){
            return false;
        }
        sort(matchsticks.rbegin(),matchsticks.rend());
        long long side = sum / 4;
        int size = matchsticks.size();
        
        vector<long long> current(4,0);

        return solve(0,current,matchsticks,side); 
    }
};
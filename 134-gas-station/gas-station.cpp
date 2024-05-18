class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int debt = 0;
        int credit = 0;
        int index = -1;
        for(int i=0;i<gas.size();i++){
            if(credit+gas[i] >= cost[i]){
                if(index == -1){
                    index = i;
                }
                credit = credit+gas[i]-cost[i];
            }else{
                if(index != -1){
                    index = -1;
                    debt = debt+(cost[i]-credit-gas[i]);
                    credit = 0;
                }else{
                    debt = debt+cost[i]-gas[i];
                }
            }
        }
        if(credit >= debt){
            return index;
        }
        return -1;
    }
};
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans;
        for(int i=0;i<prices.size();i++){
            int taken = prices[i];
            bool check = true;
            for(int j = i+1;j<prices.size();j++){
                if(taken >= prices[j]){
                    ans.push_back(taken-prices[j]);
                    check = false;
                    break;
                }
            }
            if(check){
                ans.push_back(taken);
            }
        }
        return ans;
    }
};
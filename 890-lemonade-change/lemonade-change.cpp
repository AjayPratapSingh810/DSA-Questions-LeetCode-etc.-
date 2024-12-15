class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int,int> mp;
        mp[5] = 0;
        mp[10] = 0;
        mp[20] = 0;
        for(int i = 0;i<bills.size();i++){
            if(bills[i] == 5){
                mp[5]++;
            }else if(bills[i] == 10){
                if(mp[5] == 0){
                    return false;
                }else{
                    mp[5]--;
                    mp[10]++;
                }
            }else{
                if(mp[10] > 0){
                    mp[10]--;
                    if(mp[5] > 0){
                        mp[5]--;
                    }else{
                        return false;
                    }
                }else{
                    if(mp[5] > 2){
                        mp[5] -= 3;
                    }else{
                        return false;
                    }
                }
                mp[20]++;
            }
        }
        return true;
    }
};
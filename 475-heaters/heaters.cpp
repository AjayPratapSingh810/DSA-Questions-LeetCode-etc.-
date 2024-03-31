class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int ans = -1;
        for(int i = 0;i<houses.size();i++){
            int s = 0;
            int e = heaters.size()-1;
            int mini = INT_MAX;
            while(s<=e){
                int mid = (s+e)/2;
                if(heaters[mid] == houses[i]){
                    mini = 0;
                    break;
                }else{
                    int diff = abs(heaters[mid]-houses[i]);
                    mini = min(mini,diff);
                    if(heaters[mid] < houses[i]){
                        s = mid+1;
                    }else{
                        e = mid-1;
                    }
                }
            }
            if(mini > ans){
                ans = mini;
            }
        }
        return ans;
    }
};
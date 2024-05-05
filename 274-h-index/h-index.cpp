class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i = 1;
        bool flag = true;
        int ans = 0;
        while(flag){
            flag = false;
            int count = 0;
            for(int j=0;j<citations.size();j++){
                if(citations[j] >= i){
                    count++;
                }
            }
            if(count >= i){
                ans = i;
                flag = true;
            }
            i++;
        }
        return ans;
    }
};
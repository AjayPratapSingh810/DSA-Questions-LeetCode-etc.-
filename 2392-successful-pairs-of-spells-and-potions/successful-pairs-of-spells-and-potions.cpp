class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        long long n=spells.size();
        long long m=potions.size();
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            long long a = spells[i];
            long long s = 0;
            long long e = potions.size()-1;
            long long pro = static_cast<long long>(potions[e]) * a;
            if(pro < success){
                ans.push_back(0);
                continue;
            }
            while(s<e){
                long long mid = s+(e-s)/2;
                long long pro = static_cast<long long>(potions[mid]) * a;
                if(pro >= success){
                    e = mid-1;
                }else{
                    s = mid+1;
                }
            }
            pro = potions[s]*a;
            if(pro >= success){
                s = s-1;
            }
            long long sol = potions.size()-s-1;
            ans.push_back(sol);
        }
        return ans;
    }
};
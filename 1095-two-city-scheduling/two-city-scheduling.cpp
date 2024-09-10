class Solution {
public:
    static bool compare(vector<int> a,vector<int> b)
    {
        return abs(a[0] - a[1]) >= abs(b[0] - b[1]); 
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size();
        int a = n/2, b = n/2;
        int ans = 0;
        sort(costs.begin(),costs.end(),compare);

        int i = 0;
        while(i< n && a && b){
            if(costs[i][0] < costs[i][1]){
                ans = ans+costs[i][0];
                a--;
            }else{
                ans += costs[i][1];
                b--;
            }
            i++;
        }
        while(i< n && a){
            ans = ans+costs[i][0];
            a--;
            i++;
        }
        while(i< n && b){
            ans = ans+costs[i][1];
            b--;
            i++;
        }
        return ans;
    }
};
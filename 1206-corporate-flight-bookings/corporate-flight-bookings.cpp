class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> s(n+1,0);
        for(int i = 0;i<bookings.size();i++){
            int a = bookings[i][0];
            int b = bookings[i][1];
            int z = bookings[i][2];
            s[a-1] += z;
            s[b] -= z;
        }
        for(int i = 1;i<n+1;i++){
            s[i] += s[i-1];
        }
        s.pop_back();
        return s;
    }
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int> > track;
        for(int i=0;i<position.size();i++){
            track.push_back(make_pair(position[i],speed[i]));
        }
        sort(track.begin(),track.end());

        stack<double> st;
        for(int i = track.size()-1;i>=0;i--){
            double time = (double)(target - track[i].first) / track[i].second;
            if(st.empty() || st.top() < time){
                st.push(time);
            }
        }
        return st.size();
    }
};
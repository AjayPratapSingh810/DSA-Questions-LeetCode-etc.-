class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int i =0;
        while(i<asteroids.size()){
             if(!st.empty() && (st.top() >= 0 && asteroids[i] < 0)){
                bool cond = false;
                if(-asteroids[i] > st.top()){
                    st.pop();
                    cond = true;
                }else if(-asteroids[i] == st.top()){
                    st.pop();
                }
                if(!cond){
                    i++;
                }
            }else{
                st.push(asteroids[i]);
                i++;
            }
        }
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int s = 0;
        int e = ans.size()-1;
        while(s<e){
            swap(ans[s],ans[e]);
            s++;
            e--;
        }
        return ans;
    }
};
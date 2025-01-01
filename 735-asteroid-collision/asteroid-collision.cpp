class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            if (st.empty()) {
                st.push(asteroids[i]);
            } else {
                int a = asteroids[i];
                while (true) {
                    if(st.empty()){
                        break;
                    }
                    int top = st.top();
                    st.pop();
                    if (top >0 && a< 0&&abs(top) == abs(a)) {
                        a = 0;
                        break;
                    }
                    if (top > 0 && a < 0) {
                        int t = abs(a);
                        int x = max(top, t);
                        if(x == t){
                            a = -x;
                        }else{
                            a = x;
                        }
                    }else{
                        st.push(top);
                        break;
                    }
                }
                if(a != 0){
                    st.push(a);
                }
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            ans.push_back(top);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
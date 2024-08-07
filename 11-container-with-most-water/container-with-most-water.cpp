class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0;
        int e = height.size()-1;
        int ans = 0;
        while(s<e){
            int vol = min(height[s],height[e])*(e-s);
            if(vol > ans){
                ans = vol;
            }
            if(height[s] < height[e]){
                s++;
            }else{
                e--;
            }
        }
        return ans;
    }
};
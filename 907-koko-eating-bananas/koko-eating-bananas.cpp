class Solution {
public:
    bool solve(vector<int> &piles,int h,int mid){
        for(int i=0;i<piles.size();i++){
            int r = piles[i];
            int d = r/mid;
            h = h-d;
            if(r%mid > 0){
                h--;
            }
            if(h<0){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int x = 1;
        int y = INT_MAX;

        while(x<y){
            int mid = x+(y-x)/2;
            if(solve(piles,h,mid)){
                y = mid;
            }else{
                x = mid+1;
            }
        }
        return x;
    }
};
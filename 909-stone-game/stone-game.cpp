class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int start = 0;
        int end = piles.size()-1;
        int alice = 0;
        int bob = 0;
        while(start < end){
            if(piles[start] >= piles[end]){
                alice = alice + piles[start];
                bob = bob + piles[end];
                start++;
                end--;
            }else{
                alice = alice + piles[end];
                bob = bob + piles[start];
                start++;
                end--;
            }
        }
        if(alice > bob){
            return true;
        }
        return false;
    }
};
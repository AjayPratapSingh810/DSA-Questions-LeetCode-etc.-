class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> track(26, 0);
        vector<int> prev(26, -1);
        for (int i = 0; i < tasks.size(); i++) {
            int a = tasks[i] - 'A';
            track[a]++;
        }

        int step = 0;

        while (true) {
            bool happn = false;
            int maxi = -1;
            int max = INT_MIN;
            for (int i = 0; i < 26; i++) {
                if (track[i] > 0 && (prev[i] == -1 || (step - prev[i]) > n) && track[i] > max) {
                    maxi = i;
                    max = track[i];
                }
            }
            if(max != INT_MIN){
                track[maxi]--;
                prev[maxi] = step;
                step++;
                happn = true;
            }
            if (!happn) {
                bool zero = true;
                for (int i = 0; i < 26; i++) {
                    if (track[i] != 0) {
                        zero = false;
                    }
                }
                if (zero) {
                    return step;
                }
            }
            if (!happn) {
                step++;
            }
        }
        return -1;
    }
};
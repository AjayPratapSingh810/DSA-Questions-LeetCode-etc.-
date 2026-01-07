class Solution {
public:
    vector<vector<long long>> rects;
    vector<long long> prefix;
    long long totalPoints;
    mt19937_64 gen;

    Solution(vector<vector<int>>& r) : gen(random_device{}()) {
        totalPoints = 0;

        for (auto& rect : r) {
            long long a = rect[0];
            long long b = rect[1];
            long long x = rect[2];
            long long y = rect[3];

            long long points = (x - a + 1) * (y - b + 1);
            totalPoints += points;
            prefix.push_back(totalPoints);

            rects.push_back({a, b, x, y});
        }
    }
    long long randomLL(long long a, long long b) {
        uniform_int_distribution<long long> dist(a, b);
        return dist(gen);
    }
    vector<long long> pick() {
        long long random = randomLL(1, totalPoints);
        int idx = 0;
        for (int i = 0; i < prefix.size(); i++) {
            if (random <= prefix[i]) {
                idx = i;
                break;
            }
        }

        auto& r = rects[idx];

        uniform_int_distribution<long long> dx(r[0], r[2]);
        uniform_int_distribution<long long> dy(r[1], r[3]);

        return {dx(gen), dy(gen)};
    }
};

class Solution {
public:
    void filledColors(vector<vector<int>>& image, int color,int pre,vector<vector<bool> > &visit) {
        for (int i = 0; i < image.size(); i++) {
            for (int j = 0; j < image[0].size(); j++) {
                if (image[i][j] == color && visit[i][j] == true) {
                    if (i > 0 && image[i-1][j] == pre) {
                        visit[i - 1][j] = true;
                        image[i - 1][j] = color;
                    }
                    if (j < image[0].size() - 1 && image[i][j+1] == pre) {
                        visit[i][j + 1] = true;
                        image[i][j + 1] = color;
                    }
                    if (i < image.size() - 1 && image[i+1][j] == pre) {
                        visit[i + 1][j] = true;
                        image[i + 1][j] = color;
                    }
                    if (j > 0 && image[i][j-1] == pre) {
                        visit[i][j - 1] = true;
                        image[i][j - 1] = color;
                    }
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<bool> > visit(image.size(),vector<bool>(image[0].size(),false));
        int pre = image[sr][sc];
        image[sr][sc] = color;
        if (sr > 0 && image[sr-1][sc] == pre) {
            visit[sr-1][sc] = true;
            image[sr - 1][sc] = color;
        }
        if (sc < image[0].size() - 1 && image[sr][sc+1] == pre) {
            visit[sr][sc + 1] = true;
            image[sr][sc + 1] = color;
        }
        if (sr < image.size() - 1 && image[sr+1][sc] ==pre) {
            visit[sr+1][sc] = true;
            image[sr + 1][sc] = color;
        }
        if (sc > 0 && image[sr][sc-1] == pre) {
            visit[sr][sc - 1] = true;
            image[sr][sc - 1] = color;
        }
        bool done = true;
        while (done) {
            done = false;
            vector<vector<int>> duplicate = image;
            filledColors(duplicate, color,pre,visit);
            if (duplicate != image) {
                image = duplicate;
                done = true;
            }
        }
        return image;
    }
};
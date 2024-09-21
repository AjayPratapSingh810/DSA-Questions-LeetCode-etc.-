class Solution {
public:
    pair<int,int> rowCol(int num,int n){
        int r = (num-1)/n;
        int c = (num-1)%n;
       if (r % 2 == 1) {
            c = n - 1 - c; // Reverse column in odd rows
        }
        return {n - 1 - r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int size = board.size();
        vector<vector<bool> > visited(size,vector<bool> (size,false));
        queue<pair<int,int> > q;
        q.push(make_pair(1,0));
       visited[size - 1][0] = true;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int square = p.first;
            int step = p.second;

            for(int i = 1;i<=6;i++){
                 int newSquare = square + i;
                if (newSquare > size * size) continue; // Skip out-of-bound moves

                auto [row, col] = rowCol(newSquare, size);

                if (visited[row][col]) continue; // Already visited this square
                visited[row][col] = true;

                // Check for snakes or ladders
                if (board[row][col] != -1) {
                    newSquare = board[row][col];
                }

                if (newSquare == size * size) {
                    return step + 1; // Reached the last square
                }

                q.push({newSquare, step + 1});
            }
        }
        return -1;
    }
};
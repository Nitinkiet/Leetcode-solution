class Solution {
public:
    int dirX[4] = {1,-1,0,0};
    int dirY[4] = {0,0,1,-1};
    int n, ans;

    bool isValid(int i, int j){
        return !(i<0 || i>=n || j<0 || j>=n);
    }

    void BFS_fill(vector<vector<int>>& grid, int i, int j){
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;
        while(!q.empty()){
            auto pos = q.front(); q.pop();
            for(int i=0;i<4;i++){
                int x = dirX[i]+pos.first;
                int y = dirY[i]+pos.second;
                if( isValid(x, y) && grid[x][y] == 1 ){
                    q.push({x,y});
                    grid[x][y] = -1;
                }
            }
        }
    }

    int BFS_find_path(vector<vector<int>>& grid, queue<pair<int, int>> &q){
        int size, dist = 0;
        while(!q.empty()){
            size = q.size(), dist++;
            while( size-- > 0 ){
                auto pos = q.front(); q.pop();
                for(int i=0;i<4;i++){
                    int x = dirX[i]+pos.first;
                    int y = dirY[i]+pos.second;
                    if( isValid(x, y) && grid[x][y] != -1 ){
                        if( grid[x][y] == 1 ) return dist-1;
                        q.push({x,y});
                        grid[x][y] = -1;
                    }
                }
            }
        }
        return -1;
    }


    void fillQueue(vector<vector<int>>& grid, queue<pair<int, int>> &q){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( grid[i][j] == -1 )
                    q.push({i, j});
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if( grid[i][j] == 1 ){
                    BFS_fill(grid, i, j); 
                    fillQueue(grid, q); 
                    return BFS_find_path(grid, q); 
                }
            }
        }
        return -1;
    }
};
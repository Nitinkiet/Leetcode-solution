class Solution {
public:
    bool f(int i,int j,int k,vector<vector<int>>& grid,int&n){
        if(i<0 || j<0 || i>=n || j>=n)return false;
        if(grid[i][j]!=k)return false;
        if(k== n*n - 1 )return true;
        return f(i-2,j-1,k+1,grid,n) || f(i-2,j+1,k+1,grid,n) || f(i-1,j-2,k+1,grid,n) || f(i-1,j+2,k+1,grid,n) || f(i+1,j-2,k+1,grid,n) || f(i+1,j+2,k+1,grid,n) || f(i+2,j+1,k+1,grid,n) || f(i+2,j-1,k+1,grid,n);
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        return f(0,0,0,grid,n);
    }
};
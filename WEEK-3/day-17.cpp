/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally
or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
*/

    class Solution {
public:
    void dfs(vector<vector<char>>&grid,int i,int j){
        if(grid[i][j]=='0') return;
        grid[i][j]='0';
        if(i>0) dfs(grid,i-1,j);
        if(j>0) dfs(grid,i,j-1);
        if(i < (grid.size()-1) ) dfs(grid,i+1,j);
        if(j < (grid[0].size()-1) ) dfs(grid,i,j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};

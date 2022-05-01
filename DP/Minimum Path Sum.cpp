//https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(i && j) grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j];
                else if(i) grid[i][j]=grid[i-1][j]+grid[i][j];
                else if(j) grid[i][j]=grid[i][j-1]+grid[i][j];
                ans=grid[i][j];
            }
        }
        return ans;
    }
};

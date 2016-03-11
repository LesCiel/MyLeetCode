// accepted

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int RowNum = grid.size();
        if(RowNum == 0)
        	return 0;
        int ColNum = grid[0].size();
        if(ColNum == 0)
        	return 0;

        int count = 0;
        for(int i = 0; i < RowNum; i++) {
        	for(int j = 0; j < ColNum; j++) {
        		if(grid[i][j] == '1') //find a new island
        		{
        			dfs(i, j, grid, RowNum, ColNum);
        			count++;
        		}
        	}
        }
        return count;
    }

private:
	void dfs(int x, int y, vector<vector<char>>& grid, int RowNum, int ColNum) {
		if(x < 0 || y < 0 || x >= RowNum || y >= ColNum || grid[x][y] == '0' )
			return;
		grid[x][y] = '0';
		dfs(x-1, y, grid, RowNum, ColNum);
		dfs(x+1, y, grid, RowNum, ColNum);
		dfs(x, y-1, grid, RowNum, ColNum);
		dfs(x, y+1, grid, RowNum, ColNum);
	}
};
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    	for(int i = 0; i < n; i++)
    		result.pushback(-1);
        
    }
private:
	vector<int> result;
	void solve(int LineIndex)
	{
		
	}

	bool ColumnCorrect(int LineIndex)
	{
		if(count(result.begin(), result.end(), result[LineIndex]) != 1)
			return false;
		return true;
	}

	bool SlantCorrect(int LineIndex,int n)
	{
		int i = LineIndex;
		int j = result[LineIndex];
		int k = 1;
		while(i-k >= 0)
		{
			if(result[i-k] == j-k || result[i-k] == j+k)
				return false;
		}
		k = 1;
		while(i+k < n)
		{
			if(result[i+k] == j-k || result[i+k] == j+k)
				return false;
		}
	}
};












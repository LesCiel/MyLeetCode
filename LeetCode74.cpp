// accepted. 
// binary search


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	result = false;
    	if(matrix.size() == 0)
    		return result;
    	if(matrix[0].size() == 0)
    		return result;

    	m = matrix.size();
    	n = matrix[0].size();
    	int start = 0;
    	int end = m*n;
    	t = target;
    	SearchCore(matrix, start, end);
    	return result;    
    }

private:
	bool result;
	int m;
	int n;
	int t;
	void SearchCore(vector<vector<int>>& matrix, int start, int end)
	{
		if(start >= end)
			return;
		int k = (start + end) / 2;
		int i = k / n;
		int j = k % n;
		if(matrix[i][j] > t)
		{
			end = k;
			SearchCore(matrix, start, end);
		}
		else if(matrix[i][j] < t)
		{
			start = k+1;
			SearchCore(matrix, start, end);
		}
		else
			result = true;
	}
};






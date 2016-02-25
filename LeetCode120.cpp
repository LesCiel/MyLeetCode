// Accepted
// Dynamic Programming

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

    	if(triangle.size() == 0)
    		return 0;
    	if(triangle.size() == 1)
    		return triangle[0][0];

    	int n = triangle.size();
    	vector<vector<int>> Pathsum;
    	for(int i = 0; i < n; i++) {
    		vector<int> temp;
            Pathsum.push_back(temp);
    		for(int j = 0; j <= i; j++) {
    			Pathsum[i].push_back(-1);  // initialization
    		}
    	}

    	Pathsum[0][0] = triangle[0][0];
    	for(int i = 1; i < n; i++) {
    		for(int j = 0; j <= i; j++) {
    			if(j == 0)
    				Pathsum[i][j] = Pathsum[i-1][j] + triangle[i][j];
    			else if(j == i)
    				Pathsum[i][j] = Pathsum[i-1][j-1] + triangle[i][j];
    			else
    				Pathsum[i][j] = min(Pathsum[i-1][j-1], Pathsum[i-1][j]) + triangle[i][j];
    		}
    	}
    	int minsum = Pathsum[n-1][0];
    	for(int j = 0; j < n; j++) {
    		if(Pathsum[n-1][j] < minsum)
    			minsum = Pathsum[n-1][j];
    	}
    	return minsum;     
    }

private:
	int min(int x, int y) {
		if(x < y)
			return x;
		else
			return y;
	}
};

// this algorithm can be improved to save memory use to o(n)
// since after compute Pathsum[i][j-1] and Pathsum[i][j], Pathsum[i-1][j-1] can be deleted (will never be used again).
// so there is no need to maintain a complete vector<vector> the same size with triangle.

// here is a more elegant solution:
/*
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> sum = triangle[n - 1];
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++) sum[j] = min(sum[j], sum[j + 1]) + triangle[i][j];
        }
        return sum[0];
    }
};
以上做法的思路是，如果目标是要求到达第i行的最短路径和，那么假设已知到达第i-1行的每个点的最短路径和，到达第i-1行后再经过一步就会到达第i行，
只需要保证接下来这一步走的也是最短距离就能保证整个路径是最短的。 继续推演，可以把路径看成从第0行到第i行一共i步，每一步都有2个选择，若假设
路径一定会经过第k行的第j个点，那么可以将路径分为两部分：从第0行到第k行，从第k行到第i行。只要这两部分都是最短的，那么总路径也是最短的。
*/





// accepted 
// space O(n2)
//如果先上下对折，再沿着左下-右上的对角线对折，可以得到空间复杂度为O(1)的做法

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    	int n = matrix.size();
       vector<vector<int> > tmp = matrix;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                matrix[j][n-i-1] = tmp[i][j];
            }
        }
    }
};
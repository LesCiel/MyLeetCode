// accepted
// 最简单方法利用格雷码的推导公式+位运算
// 还可以考虑格雷码的镜像性质

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for(int i = 0; i < pow(2,n); i++)
        	res.push_back(i^(i>>1));
        return res;
    }
};
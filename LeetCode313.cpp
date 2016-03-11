// accepted

// 本题思路跟ugly number II 思路完全相同，只是把质数的个数加到k而已。
// 需要注意的地方是，质数分解的方案虽然是唯一的，但是顺序不同可能会造成有好几个不同的方案。
// 例如质数表为[2,3,5]时，前5个丑数为1，2，3，4，5
// 第6个丑数时: index+2 = 2, index+3 = 1, index+5 = 1
// temp[0] = ugly[2]x2 = 3x2 = 6
// temp[1] = ugly[1]x3 = 2x3 = 6
// temp[2] = ugly[1]x5 = 2x5 = 10
// 以上备选丑数中最小值为6，但不是唯一的，此时应当把index+2和index+3都加1
// 如果这里不方便实现，在求下一个（第i个）丑数时，一定要判断备选丑数是否小于等于第i-1个丑数
// 如果是，则必须把该index++,重新计算该index对应的备选丑数，这也是本解法中while循环所做的事情

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	if(n == 1)
    		return 1;
        int k = primes.size();
        vector<int> index(k, 0);
        vector<int> temp(k, 1);
        vector<int> ugly(n, 1);
        for(int i = 1; i < n; i++) {
        	ugly[i] = INT_MAX;
        	int index_choose = -1;
        	for(int j = 0; j < k; j++) {
        		temp[j] = ugly[index[j]] * primes[j];
        		while(temp[j] <= ugly[i-1])
        		{
        		    index[j]++;
        		    temp[j] = ugly[index[j]] * primes[j];
        		}
        		ugly[i] = ugly[i] < temp[j] ? ugly[i] : temp[j];
        		index_choose = ugly[i] < temp[j] ? index_choose : j; 
        	}
        	index[index_choose]++;
        }
        return ugly[n-1];
    }
};
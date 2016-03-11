class Solution {
public:
    int nthUglyNumber(int n) {
    	if(n == 1)
    		return 1;
    	int k = 3;
    	vector<int> primes(2,3);
    	primes[1] = 3;
    	primes[2] = 5;
    	vector<int> index(k, 0);
    	vector<int> ugly(n, 1);
    	vector<int> temp(k, 1);
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



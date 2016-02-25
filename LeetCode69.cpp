class Solution {
public:
    int mySqrt(int x) {
    	if(x < 0)
    		return -1;
    	if(x == 0)
    		return 0;
    	if(x == 1)
    		return 1;
    	long start = 1;
    	long end = x;
    	long k;
        while(true)
        {
        	if(end < start)
        		return end;
        	k = (start + end) / 2;
        	if(k * k > x)
        		end = k - 1;
        	else if(k * k < x)
        		start = k + 1;
        	else
        		return k;
        }
        
    }
};
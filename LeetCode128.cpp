class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    	int length = 0;
    	if (nums.size() == 0)
    		return length;
    	unordered_set<int> iset;
    	vector<int>::iterator it;
    	for(it = nums.begin(); it != nums.end(); it++)
    		iset.insert(*it);

    	for(it = nums.begin(); it != nums.end(); it++)
    	{
    		if(iset.find(*it)!=iset.end())
    		{
    			int temp = 1;
    			int right = *it + 1;
    			while(iset.find(right) != iset.end())
    			{
    				iset.erase(right);
    				temp++;
    				right++;
    			}
    			int left = *it - 1;
    			while(iset.find(left) != iset.end())
    			{
    				iset.erase(left);
    				temp++;
    				left--;
    			}
    			if(temp > length)
    				length = temp;
    		}
    	}
    	return length;
    }
};
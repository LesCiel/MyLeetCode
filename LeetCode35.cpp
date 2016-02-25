// accepted
// binary search

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	if(nums.size() == 0)
    		return 0;
    	if(target <= nums[0])
    		return 0;
    	if(target > nums[nums.size()-1])
    		return nums.size();

    	int start = 0;
    	int end = nums.size();
    	int k;
    	while((end-start) > 1)
    	{
    		k = (start + end) / 2;
    		if(nums[k] > target)
    			end = k;
    		else if(nums[k] < target)
    			start = k;
    		else
    			return k;
    	}
    	return end;
        
    }
};
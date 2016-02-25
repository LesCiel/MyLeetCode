public class Solution {
    public int search(int[] nums, int target) {
    	if(nums.size() == 0)
    		return -1;

    	int start = 0;
    	int end = nums.size() - 1;
    	int k;
    	int pivot;
    	while(end-start > 1)
    	{
    		if(nums[start] > nums[k])
    			end = k;
    		else
    			start = k;
    	}
    	if(nums[start] > start[end])
    		pivot = end;
    	else
    		pivot = start;      
    }
    int offset = nums.size() - pivot - 1;
    // i' = (i+offset) %  nums.size()

};











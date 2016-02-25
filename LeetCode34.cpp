// accepted 
// binary search


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	result.push_back(-1);
    	result.push_back(-1);
    	if(nums.size() == 0)
    		return result;

    	// initialize result as [n-1, 0]

    	int start = 0;
    	int end = nums.size();
    	t = target;
    	SearchCore(nums, start, end);
    	return result;    
    }

private:
	vector<int> result;
	int t;
	void SearchCore(vector<int>& nums, int start, int end)
	{
		if(start >= end)
			return;
		int k = (start + end) / 2;

		if(nums[k] > t)
		{
			end = k;
			SearchCore(nums, start, end);
		}
		else if(nums[k] < t)
		{
			start = k+1;
			SearchCore(nums, start, end);
		}
		else
		{
			int start2 = k+1;
			int end2 = k;
			if(k < result[0] || result[0] == -1)
				result[0] = k;
			if(k > result[1]  || result[1] == -1)
				result[1] = k;
			SearchCore(nums, start, end2);
			SearchCore(nums, start2, end);
		}
	}
};






// Accepted
//这是DP问题？！

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    	if(nums.size() == 0)
    		return result;
    	sort(nums.begin(), nums.end());
    	vector<int> start;
    	start.clear();
    	Core(start, -1, nums);
    	return result;  
    }

private:
	vector<vector<int>> result;

	void Core(vector<int> subset, int k, vector<int>& nums) {
		if(k >= 0)
			subset.push_back(nums[k]);
		result.push_back(subset);
		for(int i = k+1; i < nums.size(); i++) {
			Core(subset, i, nums);
		}
	}
};
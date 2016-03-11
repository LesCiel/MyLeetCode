// accepted

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    	if(nums.size() == 0 || nums.size() == 1)
    		return;
        sort(nums.begin(),nums.end());
        for(int i = 1; i < nums.size(); i++) {
        	if(i%2 == 0) {
        		int temp = nums[i];
        		nums[i] = nums[i-1];
        		nums[i-1] = temp;
        	}
        }
    }
};
//accepted

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp(nums.size(),0);

        int i,j,k;
        i = (nums.size()-1)/2;
        j = nums.size() - 1;
        k = 0;

        while(j > (nums.size()-1)/2) {
        	temp[k*2] = nums[i];
        	temp[k*2+1] = nums[j];
        	i--;
        	j--;
        	k++;
        }
        if(nums.size()%2 == 1)
        	temp[nums.size()-1] = nums[0];
        for(i = 0; i<nums.size();i++)
            nums[i] = temp[i];
    }
};
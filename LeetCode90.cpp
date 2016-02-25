// Accepted
// not by me



class Solution {  
public:  
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {  
        vector<vector<int>> ans(1, vector<int>());  
        sort(nums.begin(), nums.end());  
          
        int pre_size = 0;  
        for (int i = 0; i < nums.size(); i++)  
        {  
            int n = ans.size();  
            for (int j = 0; j < n; j++) //第二个for循环是为了求得包含nums[i]的所有子集    
            {  
                if (i == 0 || nums[i] != nums[i -1] || j>=pre_size)  
                {  
                    ans.push_back(ans[j]); //在尾部重新插入ans已经存在的子集    
                    ans.back().push_back(nums[i]); //将nums[i]添加进去   
                }  
            }  
            pre_size = n;  
        }  
        return ans;  
    }  
};  
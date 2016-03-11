class Solution {
public:
     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int size = nums.size();
        if(size <= 0 || k <= 0){
            return result;
        }
        deque<int> deque;
        for(int i = 0;i < k-1;++i){
            while(!deque.empty() && nums[i] >= nums[deque.back()]){
                deque.pop_back();
            }
            deque.push_back(i);
        }
        if(size < k){
            result.push_back(nums[deque.front()]);
        }
        for(int i = k-1;i < size;++i){
        	//从队尾开始，只要队中元素比nums[i]小就pop它，队中元素的个数不可能超过k，因此它不可能成为往后的最大值
            while(!deque.empty() && nums[i] >= nums[deque.back()]){
                deque.pop_back();
            }
            //如果遇到比nums[i]大的队中元素，但如果它已经超出window大小，也要舍弃
            while(!deque.empty() && i - deque.front() >= k){
                deque.pop_front();
            }
            //无论大小都要把当前的nums[i]放入队列
            deque.push_back(i);
            result.push_back(nums[deque.front()]);
        }//for
        return result;
    }
        
};
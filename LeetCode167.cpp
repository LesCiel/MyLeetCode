// accepted

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	vector<int> result(2,0);
        int i = 0;

        while(i < (numbers.size()-1) && numbers[i] <= target - numbers[0]) {
        	int start = i+1;
        	int end = numbers.size()-1;
        	int left = target-numbers[i];
        	int mid;

        	while(start < end) {
        		mid = (start + end)/2;
        		if(numbers[mid] > left)
        			end = mid;
        		else if(numbers[mid] < left)
        			start = mid+1;
        		else {
        			result[0] = i+1;
        			result[1] = mid+1;
        			return result;
        		}
        	}
        	if(numbers[end] == left) {
        	    result[0] = i+1;
        	    result[1] = end+1;
        	    return result;
        	}
        	i++;
        }
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	vector<int> left;
    	vector<int> right;
    	for(int i = 0; i < heights.size(); i++)
    	{
    		left.push_back(i);
    		right.push_back(i);
    	}
    	for(int = 0; i < heights.size()-1; i++)
    	{
    		if(heights[i] < heights[i+1])
    			left[i+1] = i+1;
    		else if(heights[i] > heights[i+1])
    			right[i] = i;
    		else
    		{
    			left[i+1] = i;
    			right[i] = i+1;
    		}
    	}

    	int max = 0;
    	int temp = 0;
    	for(int i = 0; i < heights.size(); i++)
    	{
    		temp = heights[i] * (right[i] - left[i] + 1);
    		if(temp > max)
    			max = temp;
    	}
    	return max;
    }
};







/*
// time excess
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	int Smax = 0;
    	int temp = 0;
    	for(int i = 0; i < heights.size(); i++){
    		temp = maxlength(i, heights) * heights[i];
    		if (temp > Smax)
    			Smax = temp;
    	}
        return Smax;
    }
private:
	int maxlength(int i, vector<int> heights){
		int left = i;
		int left_length = 0;
		int right = i;
		int right_length = 0;
		while(left >= 0){
			if(heights[left] >= heights[i]){
				left_length++;
				left --;
			}
			else
				break;
		}
		while(right < heights.size()){
			if(heights[right] >= heights[i]){
				right_length++;
				right++;
			}
			else
				break;
		}
	    return(left_length + right_length - 1);
	}
	
};
*/
//accepted
//思路正确，但是实现太繁琐

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> result(2,0);

    	// if there are a+b = target and a = b
    	vector<int>::iterator it;
    	it = find(nums.begin(), nums.end(),target/2);
        if(target%2 == 0 && it !=nums.end()) {
        	result[0] = it - nums.begin();
        	it = find(it+1, nums.end(),target/2);
        	if(it != nums.end()) {
        		result[1] = it - nums.begin();
        		return result;
        	}
        }

        // a+b = target and a!=b
        unordered_map<int, int> num;
        for(int i = 0; i < nums.size(); i++) {
        	num.insert(pair<int, int>(nums[i],i));
        }
        unordered_map<int, int>::iterator it1;
        unordered_map<int, int>::iterator it2; 	
        int left;
        for(it1 = num.begin(); it1!=num.end(); it1++) {
        	left = target - it1->first;
        	it2 = num.find(left);
        	if(it2 != num.end() && it1 != it2) {
        		result[0] = min(it1->second,it2->second);
        		result[1] = max(it1->second,it2->second);
        		return result;
        	}
        }
        return result;
    }
};

//更为简洁的做法，nums[i]只跟nums[0-i-1]的数尝试配对
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0, n = nums.size();
        unordered_map<int, int> m;
        vector<int> ret;

        for (i = 0; i < n; ++i)
        {
            if (m.find(target - nums[i]) != m.end())
            {
                ret.push_back(m[target - nums[i]]);
                ret.push_back(i);
                break;
            }
            m[nums[i]] = i;
        }

        return ret;
    }
};





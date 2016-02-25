// accepted

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.size() == 0)
    		return "";
    	if(strs.size() == 1)
    		return strs[0];
        
    	int j = 0;
    	bool stopflag = false;
    	while(!stopflag){
    		for(int i = 0; i < strs.size()-1; i++){
    			if(strs[i] == "" || strs[i+1] == "")
    				return "";
    			if(strs[i][j] != strs[i+1][j])
    			{
    				stopflag = true;
    				j--;
    				break;
    			}
    			if((j == strs[i].size()-1) ||( j == strs[i+1].size()-1))
    				stopflag = true;
    		}
    		j++;
    	}
    	return strs[0].substr(0,j);    
    }
};
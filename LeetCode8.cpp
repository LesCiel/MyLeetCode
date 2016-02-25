class Solution {
public:
    int myAtoi(string str) {
    	int num = 0;
    	int t = 1;
        bool spaceflag = false;
    	for(int i = str.size() - 1; i >= 0; i--){
    		if(str[i] < 58 && str[i] > 47){
                if(spaceflag == true)
                {
                    num = 0;
                    t = 1;
                }
    			num = num + int(str[i]-48)*t;
    			t = t*10;
    		}
            else if(str[i] == 32){
                spaceflag = true;
            }
    		else if(i != 0)
    		{
    			num = 0;
    			t = 1;
    		}
    		else{
                if(spaceflag == true){
                    num = 0;
                    break;
                }
    			if(str[i] == 43)
    				break;
    			else if(str[i] == 45)
    				num = 0 - num;
    			else
    				num = 0;
    		}
    	}
        return num;
    }
};

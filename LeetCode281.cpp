// accepted

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& V1, vector<int>& V2) {
        v1_index = 0; //下一次该访问的Index
        v2_index = 0;
        v_num = 1; //下一次该访问的vector
        v1 = V1;
        v2 = V2;
    }

    int next() {
        if(v_num == 1) {
        	v_num = 2;
        	if(v1_index < v1.size())
        	{
        		v1_index++;
        		v_num = 2;
        		return(v1[v1_index-1]);
        	}
        	else {
        		v2_index++;
        		return(v2[v2_index-1]);
        	}
        }
        else {
        	v_num = 1;
        	if(v2_index < v2.size())
        	{
        		v2_index++;
        		return(v2[v2_index-1]);
        	}
        	else {
        		v1_index++;
        		return(v1[v1_index-1]);
        	}
        }
    }

    bool hasNext() { 
       	if(v1_index < v1.size())
       		return true;
       	else {
       		if(v2_index < v2.size())
       			return true;
       		else
       			return false;    		
       	}
    }
private:
	int v1_index;
	int v2_index;
	int v_num;
	vector<int> v1;
	vector<int> v2;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
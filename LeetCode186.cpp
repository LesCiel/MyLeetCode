//accepted

class Solution {
public:
    void reverseWords(string &s) {
    	Reverse(0,s.length()-1,s);
    	int j = 0;
    	int i;
    	for(i = 0; i < s.length(); i++) {
    	    if(s[i] == ' ') {
        	    Reverse(j,i-1,s);
            	j = i+1;
        	}
    	}
    	Reverse(j, i-1, s);
	}

	void Reverse(int p, int q, string &s) {
    	for(int i = p; i<=q; i++) {
        	char tmp = s[i];
        	s[i] = s[q];
        	s[q] = tmp;
        	q--;
    	}
	}
};
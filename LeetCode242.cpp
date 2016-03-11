// hash_table 
// accepted

class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(s.length() != t.length())
    		return false;
        unordered_map<char,int> CharS;
        unordered_map<char,int> CharT;
        for(int i = 0; i < s.length(); i++) {
        	unordered_map<char,int>::iterator it1;
        	unordered_map<char,int>::iterator it2;
        	it1 = CharS.find(s[i]);
        	it2 = CharT.find(t[i]);
        	if(it1 != CharS.end())
        		it1->second++;
        	else
        		CharS.insert(pair<char,int>(s[i],1));
        	if(it2 != CharT.end())
        		it2->second++;
        	else
        		CharT.insert(pair<char,int>(t[i],1));
        }

        unordered_map<char,int>::iterator it;
        for(it = CharS.begin(); it != CharS.end(); it++) {
        	int countS = it->second;
        	int countT = CharT[it->first];
        	if(countT != countS)
        		return false;
        }
        return true;
    }
};

// vector sort
// accepted
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
    		return false;
    		
        vector<int> vs;
        vector<int> vt;
        for(int i = 0; i < s.length(); i++) {
            vs.push_back(s[i]);
            vt.push_back(t[i]);
        }
        sort(vs.begin(),vs.end());
        sort(vt.begin(),vt.end());
        return(vs == vt);
    }
};


// clever and efficient method (idea of map using array index and ASCII)
// 12ms accepted

class Solution {
public:
    bool isAnagram(string s, string t) {
        int charArr[26] = {0};

        for(int i=0;i<s.size();i++){
            charArr[(int(s[i])-97)]++;
        }
        for(int j=0;j<t.size();j++){
            charArr[(int(t[j])-97)]--;
        }
        for(int k=0;k<26;k++){
            if(charArr[k] != 0){
                return false;
            }
        }
        return true;
    }
};



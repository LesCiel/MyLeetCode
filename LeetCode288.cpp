// ac
// 注意题目说的是如果没有other word的缩写和given word一样，就算是unique，也就是说dictionary中可能出现重复词
// 所以不能只考虑缩写出现的次数，还要记录每个缩写对应到dictionary中的原词是什么

class ValidWordAbbr {
private:
    unordered_map<string, vector<string>> myMap;
    string abbreviation(string word)
    {
        string s;
        int n = word.length();
        if(n<=2)
            s = word;
        else
            s = word[0] + to_string(n-2) + word[n-1];
        return s;
    }
public:
    ValidWordAbbr(vector<string> &dictionary) {
        int n = dictionary.size();
        int i;
        string s;
        for(i=0; i<n; i++)
        {
            s = abbreviation(dictionary[i]);
            myMap[s].push_back(dictionary[i]);
        }
    }

    bool isUnique(string word) {
        string s= abbreviation(word);
        if(myMap.count(s) == 0) 
            return true;

        vector<string> words = myMap[s];

        for(int i=0; i<words.size(); i++)
            if(words[i] != word)
                return false;

        return true;
    }
};

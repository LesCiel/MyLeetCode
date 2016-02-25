class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict)
    {
        bool dp[s.length()];
        memset(dp, false, s.length());

        for(int i = 0; i < s.length(); i++) {
            if(dict.count(s.substr(i,s.length()-i+1)))
                dp[i] = true;
        }

        for(int i = s.length()-1; i >= 0; i--) {
            if(!dp[i]) {
                for(int j = i; j < s.length(); j++) {
                    if(dict.count(s.substr(i,j-i)) && dp[j])
                        dp[i] = true;
                }
            }
        }
        return dp[0];
    }
};
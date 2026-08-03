class Solution {
public:
    vector<int> dp;
    bool solve(int index,string& s,vector<string>& wordDict){
        if(index==s.length()){
            return true;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        for(string word:wordDict){
            if(index+word.length()<=s.length() && s.substr(index,word.length())==word){
                if(solve(index+word.length(),s,wordDict)){
                    return dp[index]=true;
                }
            }
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.length(),-1);
        return solve(0,s,wordDict);
    }
};
